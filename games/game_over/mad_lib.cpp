#include <iostream>
#include <string>

using namespace std;

string askText(string prompt);
int askNumber(string pronpt);
void tellStory(
    string name, string noun, int number, string bodyPart, string verb);

int main()
{
    cout << "Welcom to Mad Lib.\n\n";
    cout << "Answer the following questions to heelp create a new story.\n";

    string name = askText("Please enter a name: ");
    string noun = askText("Please enter a plural noun: ");
    int number = askNumber("Please enter a number: ");
    string bodyPart = askText("Please enter a body part: ");
    string verb = askText("Please enter a verb: ");

    tellStory(name, noun, number, bodyPart, verb);
    return 0;
}

string askText(string prompt)
{
    string text;
    cout << prompt;
    cin >> text;

    return text;
}

int askNumber(string prompt)
{
    int num;
    cout << prompt;
    cin >> num;

    return num;
}

void tellStory(
    string name, string noun, int number, string bodyPart, string verb)
{
    cout << "\nHere's your story:\n";
    cout << "The famous explorer: ";
    cout << name;
    cout << " had nearly given up a life-long quest to find\n";
    cout << "The Lost City of ";
    cout << noun;
    cout << " found the ecplorer.\n";
    cout << "Surrounded by ";
    cout << number;
    cout << " " << noun;
    cout << ", a tear came to ";
    cout << name << "'s ";
    cout << bodyPart << ".\n";
    cout << "After all this time the quest was finnaly over. ";
    cout << "And then the ";
    cout << noun << "\n";
    cout << "promptly devoured ";
    cout << name << ". ";
    cout << "The mortal of the story? Be careful what you ";
    cout << verb;
    cout << " for. ";
}