#include <ncurses.h>

void erase(int y, int x)
{
    mvaddch(y, x, '#');
}

void game_loop(char main_char, int row, int col, int ch)
{
    if (ch == 'q' || ch == 'Q')
    {
        return;
    }

    mvaddch(row, col, main_char);
    refresh();

    for (;;)
    {
        ch = getch();

        if (ch == KEY_LEFT)
        {
            erase(row, col);
            col = col - 1;
            mvaddch(row, col, main_char);
            refresh();
        }
        else if (ch == KEY_RIGHT)
        {
            erase(row, col);
            col = col + 1;
            mvaddch(row, col, main_char);
            refresh();
        }
        else if (ch == KEY_UP)
        {
            erase(row, col);
            row = row - 1;
            mvaddch(row, col, main_char);
            refresh();
        }
        else if (ch == KEY_DOWN)
        {
            erase(row, col);
            row = row + 1;
            mvaddch(row, col, main_char);
            refresh();
        }
        else if (ch == 'q' || ch == 'Q')
        {
            break;
        }
    }
}

int main()
{
    // Initialize ncurses
    initscr();
    clear();
    noecho();
    cbreak();
    keypad(stdscr, TRUE);
    curs_set(0);

    int row = 10, col = 10;
    char main_char = '@';

    printw("Welcom to the PR game. \n Press any key to start. \nIf you want to quit press q");

    int ch = getch();

    clear();

    game_loop(main_char, row, col, ch);

    endwin();

    return 0;
}
