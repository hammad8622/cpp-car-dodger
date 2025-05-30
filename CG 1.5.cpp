#include<iostream>
#include<conio.h>
#include <windows.h>
using namespace std;

// Global variables for console manipulation
HANDLE output_screen = GetStdHandle(STD_OUTPUT_HANDLE);
COORD cursor;

// Game variables
int speed = 50;
int enemyY[3];
int enemyX[3];
char player[4][3] = { ' ','0',' ',
                    '-','|','-',
                    ' ','|',' ',
                    '/',' ','\\', };

int player_position;
int score = 0;

// Function prototypes
void cursor_xy(int x, int y);
void make_car(int v);
void del_car(int v);
void set_car(int v);
void del_player();
void make_player();
int accident();
void dead();
void play();

int main()
{
    // Main menu loop
    do
    {
        system("cls");
        cursor_xy(10, 6); cout << "         Car Dodging Game        ";
        cursor_xy(10, 9); cout << "1. Start Game";
        cursor_xy(10, 11); cout << "2. Quit";
        cursor_xy(10, 13); cout << "Select option: ";
        char op = getche();
        if (op == '1') play();
        else if (op == '2') exit(0);

    } while (1);
    return 0;
}

// Function to set cursor position in the console for printing text at desired location
void cursor_xy(int x, int y)
{
    cursor.X = x;
    cursor.Y = y;
    SetConsoleCursorPosition(output_screen, cursor);
}

// Function to draw an enemy car at a specific position
void make_car(int v)
{
    cursor_xy(enemyX[v], enemyY[v]);     cout << " ** ";
    cursor_xy(enemyX[v], enemyY[v] + 1); cout << "****";
    cursor_xy(enemyX[v], enemyY[v] + 2); cout << " ** ";
}

// Function to clear the area occupied by an enemy car when its position changes
void del_car(int v)
{
    cursor_xy(enemyX[v], enemyY[v]);     cout << "    ";
    cursor_xy(enemyX[v], enemyY[v] + 1); cout << "    ";
    cursor_xy(enemyX[v], enemyY[v] + 2); cout << "    ";
}

// Function to initialize the position of a car
void set_car(int v)
{
    del_car(v);
    enemyY[v] = 1;
    enemyX[v] = 17 + rand() % (33);
}

// Function to draw the player's character
void make_player()
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 3; j++) {
            cursor_xy(j + player_position, i + 22); cout << player[i][j];
        }
    }
}

// Function to clear the area occupied by the player's character when he moves
void del_player()
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 3; j++) {
            cursor_xy(j + player_position, i + 22); cout << " ";
        }
    }
}

// Function to check for collision between the player and cars
int accident()
{
    // Check collision with the first car
    if (enemyY[0] + 4 >= 23 && enemyX[0] >= player_position && enemyX[0] <= player_position + 2)
    {
        return 1;
    }

    // Check collision with the second car
    if (enemyY[1] + 4 >= 23 && enemyX[1] >= player_position && enemyX[1] <= player_position + 2)
    {
        return 1;
    }

    // Check collision with the third car
    if (enemyY[2] + 4 >= 23 && enemyX[2] >= player_position && enemyX[2] <= player_position + 2)
    {
        return 1;
    }

    return 0;
}

// Function to handle the game over scenario
void dead()
{
    system("cls");
    cout << endl;
    cout << "\tWASTED" << endl;
    cout << "\tScore: " << score << endl;
    cout << "Press any key to go back to menu" << endl;
    getch();
}

// Function to play the game ( main gameplay function : most other functions are called here )
void play()
{
    // Initialize player's position and score
    player_position = 34;
    score = 0;

    // Clear the console and set initial car positions
    system("cls");
    set_car(0);
    set_car(1);
    set_car(2);

    cursor_xy(77, 2); cout << " => A Key - Left";
    cursor_xy(77, 4); cout << " => D Key - Right";
    cursor_xy(77, 6); cout << " => I Key - Speed Up";
    cursor_xy(77, 8); cout << " => K Key - Speed Down";
    cursor_xy(77, 16); cout << "=> Press any key to start...";

    getch();

    // Gameplay loop
    while (1)
    {
        // Check if a key is pressed
        if (kbhit())
        {
            char ch = getch();
            // Move player left
            if (ch == 'a')
            {
                if (player_position > 18)
                    player_position -= 4;
            }
            // Move player right
            if (ch == 'd')
            {
                if (player_position < 50)
                    player_position += 4;
            }
            // Speed up the game
            if (ch == 'i')
            {
                    speed -= 10;
            }
            // Slow down the game
            if (ch == 'k')
            {
                    speed += 10;
            }
            // Exit the game ( Esc Key)
            if (ch == 27)
                break;
        }

        // Draw player and cars, check for collision
        make_player();
        make_car(0);
        make_car(1);
        make_car(2);
        if (accident() == 1)
        {
            // Handle game over scenario
            dead();
            return;
        }

        // Sleep function controls the speed of the loop ( makes the game faster/slower )
        Sleep(speed);

        // Clear player and cars for next frame
        del_player();
        del_car(0);
        del_car(1);
        del_car(2);

        // Adjust the position (Y-Axis) of the second car if it is the same as first car
        if (enemyY[1] == enemyY[0])
                enemyY[1] += 10 + rand() % 5;

        // Adjust the position (X-Axis) of the second car if it is the same as first car
        if (enemyX[1] == enemyX[0])
                enemyX[1] += 10 + rand() % 5;

        // Adjust the position (Y-Axis) of the third car if it is the same as first car
        if (enemyY[2] == enemyY[0])
                enemyY[2] += 10 + rand() % 5;

        // Adjust the position (X-Axis) of the third car if it is the same as first car
        if (enemyX[2] == enemyX[0])
                enemyX[2] += 10 + rand() % 5;

        // Adjust the position (Y-Axis) of the third car if it is the same as second car
        if (enemyY[2] == enemyY[1])
                enemyY[2] += 10 + rand() % 5;

        // Adjust the position (X-Axis) of the third car if it is the same as second car
        if (enemyX[2] == enemyX[1])
                enemyX[2] += 10 + rand() % 5;

        // Move the cars down the screen
        enemyY[0] += 1;
        enemyY[1] += 1;
        enemyY[2] += 1;

        // Check if the first car has reached the bottom of the screen
        if (enemyY[0] > 22)
        {
            // Respawn the first car at the top and increment the score
            set_car(0);
            score++;
        }

        // Check if the second car has reached the bottom of the screen
        if (enemyY[1] > 22)
        {
            // Respawn the second car at the top and increment the score
            set_car(1);
            score++;
        }

        // Check if the third car has reached the bottom of the screen
        if (enemyY[2] > 22)
        {
            // Respawn the third car at the top and increment the score
            set_car(2);
            score++;
        }
    }
}
