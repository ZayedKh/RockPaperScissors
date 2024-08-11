#include <iostream>
#include <iomanip>
#include <cmath>
#include <ctime>

char getUserCHoice();
char getComputerChoice();
void showChoice();
void chooseWinner(char player, char computer);

int main()
{
    showChoice();
    return 0;
}

char getUserCHoice()
{
    char userChoice;

    do
    {
        std::cout << "Rock (R), Paper (P), or Scissors (S)?\n";
        std::cin >> userChoice;
    }
    while (!(userChoice == 'R' || userChoice == 'P' || userChoice == 'S'));

    return userChoice;
}

char getComputerChoice()
{
    char computerChoice;

    srand(time(nullptr));
    int numChoice = rand() % 3 + 1;

    switch (numChoice)
    {
    case 1:
        computerChoice = 'R';
        break;
    case 2:
        computerChoice = 'P';
        break;
    case 3:
        computerChoice = 'S';
        break;
    }

    return computerChoice;
}

void showChoice()
{
    std::cout << "Make your choice!\n";
    char userChoice = getUserCHoice();

    char computerChoice = getComputerChoice();
    std::cout << "The computers choice was " << computerChoice << "!" << '\n';
    chooseWinner(userChoice, computerChoice);
}

void chooseWinner(char player, char computer)
{
    std::cout << "********************\n";
    if (player == computer)
    {
        std::cout << "The result is a draw!";
    }
    else if ((player == 'R' && computer == 'S') || (player == 'P' && computer == 'R') || (player == 'S' && computer ==
        'P'))
    {
        std::cout << "You won!\n";
    }
    else
    {
        std::cout << "The computer has won!\n";
    }
}
