#include <algorithm>
#include <ctime>
#include <iostream>
#include <random>
#include <string>
#include <vector>

using namespace std;

class Card {
public:
    enum rank {
        ACE = 1,
        TWO,
        THREE,
        FOUR,
        FIVE,
        SIX,
        SEVEN,
        EIGHT,
        NINE,
        TEN,
        JACK,
        QUEEN,
        KING
    };
    enum suit { CLUBS, DIAMONDS, HEARTS, SPADES };
    friend ostream& operator<<(ostream& os, const Card& aCard);
    Card(rank r = ACE, suit s = SPADES, bool ifu = true);
    int getValue() const;
    void flip();

private:
    rank m_Rank;
    suit m_Suit;
    bool m_IsFaceUp;
};
Card::Card(rank r, suit s, bool ifu)
    : m_Rank(r)
    , m_Suit(s)
    , m_IsFaceUp(ifu) {};
int Card::getValue() const
{
    int value = 0;
    if (m_IsFaceUp) {
        value = m_Rank;
        if (value > 10) {
            value = 10;
        }
    }
    return value;
}
void Card::flip() { m_IsFaceUp = !(m_IsFaceUp); }
// ------Hand-------
class Hand {
public:
    Hand();
    virtual ~Hand();

    void add(Card* pCard);
    void clear();
    int getTotal() const;

protected:
    vector<Card*> m_Cards;
};
Hand::Hand() { m_Cards.reserve(7); }
Hand::~Hand() { clear(); }
void Hand::add(Card* pCard) { m_Cards.push_back(pCard); }
void Hand::clear()
{
    vector<Card*>::iterator iter = m_Cards.begin();
    for (iter = m_Cards.begin(); iter != m_Cards.end(); ++iter) {
        delete *iter;
        *iter = 0;
    }

    m_Cards.clear();
}
int Hand::getTotal() const
{
    if (m_Cards.empty()) {
        return 0;
    }
    if (m_Cards[0]->getValue() == 0) {
        return 0;
    }
    // находит сумму очков всех карт, каждый туз дает очко
    int total = 0;
    vector<Card*>::const_iterator iter;
    for (iter = m_Cards.begin(); iter != m_Cards.end(); ++iter) {
        total += (*iter)->getValue();
    }
    // определить, дердит ли рука туз
    bool containsAce = false;
    for (iter = m_Cards.begin(); iter != m_Cards.end(); ++iter) {
        if ((*iter)->getValue() == Card::ACE) {
            containsAce = true;
        }
    }
    if (containsAce && total <= 11) {
        total += 10;
    }
    return total;
}
// ------GenericPlayer-------
class GenericPlayer : public Hand {
    friend ostream& operator<<(ostream& os, const GenericPlayer& gp);

public:
    GenericPlayer(const string& name = "");
    virtual ~GenericPlayer();
    virtual bool isHitting() const = 0;
    bool isBusted() const;
    void bust() const;

protected:
    string m_Name;
};
GenericPlayer::GenericPlayer(const string& name)
    : m_Name(name) {};
GenericPlayer::~GenericPlayer() {};
bool GenericPlayer::isBusted() const { return (getTotal() > 21); }
void GenericPlayer::bust() const { cout << m_Name << " bust.\n"; }

class Player : public GenericPlayer {
public:
    Player(const string& name = "");
    virtual ~Player();
    virtual bool isHitting() const;
    void win() const;
    void lose() const;
    void push() const;
};

Player::Player(const string& name)
    : GenericPlayer(name) {};
Player::~Player() {};
bool Player::isHitting() const
{
    cout << m_Name << ", do you want a hit? (Y/N): ";
    char response;
    cin >> response;

    return (response == 'y' || response == 'Y');
}
void Player::win() const { cout << m_Name << " wins.\n"; }
void Player::lose() const { cout << m_Name << " loses.\n"; }
void Player::push() const { cout << m_Name << " pushes.\n"; }

class House : public GenericPlayer {
public:
    House(const string& name = "House");
    virtual ~House();
    virtual bool isHitting() const;
    void flipFirstCard();
};
House::House(const string& name)
    : GenericPlayer(name) {};
House::~House() {};
bool House::isHitting() const { return (getTotal() <= 16); }
void House::flipFirstCard()
{
    if (!m_Cards.empty()) {
        m_Cards[0]->flip();
    } else {
        cout << "No card to flip!\n";
    }
}

class Deck : public Hand {
public:
    Deck();
    virtual ~Deck();
    void populate();
    void shuffleDeck();
    void deal(Hand& aHand);
    void additionalCards(GenericPlayer& aPlayer);
};
Deck::Deck()
{
    m_Cards.reserve(52);
    populate();
}
Deck::~Deck() { }
void Deck::populate()
{
    clear();
    for (int s = Card::CLUBS; s <= Card::SPADES; ++s) {
        for (int r = Card::ACE; r <= Card::KING; ++r) {
            add(new Card(
                static_cast<Card::rank>(r), static_cast<Card::suit>(s)));
        }
    }
}
void Deck::shuffleDeck()
{
    random_device rd;
    mt19937 g(rd());
    shuffle(m_Cards.begin(), m_Cards.end(), g);
}
void Deck::deal(Hand& aHand)
{
    if (!m_Cards.empty()) {
        aHand.add(m_Cards.back());
        m_Cards.pop_back();
    } else {
        cout << "Out of cards. Unable to deal.";
    }
}
void Deck::additionalCards(GenericPlayer& aPlayer)
{
    cout << endl;
    while (!(aPlayer.isBusted()) && aPlayer.isHitting()) {
        deal(aPlayer);
        cout << aPlayer << endl;
        if (aPlayer.isBusted()) {
            aPlayer.bust();
        }
    }
}

class Game {
public:
    Game(const vector<string>& names);
    ~Game();
    void play();

private:
    Deck m_Deck;
    House m_House;
    vector<Player> m_Players;
};
Game::Game(const vector<string>& names)
{
    vector<string>::const_iterator pName;
    for (pName = names.begin(); pName != names.end(); ++pName) {
        m_Players.push_back(Player(*pName));
    }
    srand(static_cast<unsigned int>(time(0)));
    m_Deck.populate();
    m_Deck.shuffleDeck();
}
Game::~Game() { }
void Game::play()
{
    vector<Player>::iterator pPlayer;
    for (int i = 0; i < 2; ++i) {
        for (pPlayer = m_Players.begin(); pPlayer != m_Players.end();
             ++pPlayer) {
            m_Deck.deal(*pPlayer);
        }
        m_Deck.deal(m_House);
    }
    m_House.flipFirstCard();

    for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer) {
        cout << *pPlayer << endl;
    }

    cout << m_House << endl;

    for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer) {
        m_Deck.additionalCards(*pPlayer);
    }

    m_House.flipFirstCard();

    cout << endl << m_House;

    m_Deck.additionalCards(m_House);
    if (m_House.isBusted()) {
        for (pPlayer = m_Players.begin(); pPlayer != m_Players.end();
             ++pPlayer) {
            if (!(pPlayer->isBusted())) {
                pPlayer->win();
            }
        }
    } else {
        for (pPlayer = m_Players.begin(); pPlayer != m_Players.end();
             ++pPlayer) {
            if (!(pPlayer->isBusted())) {
                if (pPlayer->getTotal() > m_House.getTotal()) {
                    pPlayer->win();
                } else if (pPlayer->getTotal() < m_House.getTotal()) {
                    pPlayer->lose();
                } else {
                    pPlayer->push();
                }
            }
        }
    }
    for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer) {
        pPlayer->clear();
    }
    m_House.clear();
}

ostream& operator<<(ostream& os, const Card& aCard);
ostream& operator<<(ostream& os, const GenericPlayer& aPlayer);

int main()
{
    cout << "\t\tWelcome to Blackjack!\n\n";
    int numPlayers = 0;
    while (numPlayers < 1 || numPlayers > 7) {
        cout << "How many players? (1 - 7): ";
        cin >> numPlayers;
    }
    vector<string> names;
    string name;
    for (int i = 0; i < numPlayers; ++i) {
        cout << "Enter player name: ";
        cin >> name;
        names.push_back(name);
    }
    cout << endl;

    Game game(names);

    char again = 'y';
    while (again != 'n' && again != 'N') {
        game.play();
        cout << "\nDo you wnat to play again? (y/n): ";
        cin >> again;
    }
    return 0;
}

ostream& operator<<(ostream& os, const Card& aCard)
{
    const string RANKS[] = { "0", "A", "2", "3", "4", "5", "6", "7", "8", "9",
        "10", "J", "Q", "K" };
    const string SUITS[] = { "c", "d", "h", "s" };
    if (aCard.m_IsFaceUp) {
        os << RANKS[aCard.m_Rank] << SUITS[aCard.m_Suit];
    } else {
        os << "XX";
    }

    return os;
}

ostream& operator<<(ostream& os, const GenericPlayer& aPlayer)
{
    os << aPlayer.m_Name << ":\t";
    vector<Card*>::const_iterator pCard;
    if (!aPlayer.m_Cards.empty()) {
        for (pCard = aPlayer.m_Cards.begin(); pCard != aPlayer.m_Cards.end();
             ++pCard) {
            os << *(*pCard) << "\t";
        }

        if (aPlayer.getTotal() != 0) {
            cout << "(" << aPlayer.getTotal() << ")";
        }
    } else {
        os << "<empty>";
    }
    return os;
}