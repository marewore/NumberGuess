#include <iostream>
#include <random>

using namespace std;

int generateRandomNumber(int min, int max)
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(min, max);
    return dis(gen);
}

void playGame()
{
    cout << "\nPlease select the difficulty level:\n"
         << "1. Easy (10 chances)\n"
         << "2. Medium (5 chances)\n"
         << "3. Hard (3 chances)\n";

    int difficulty, chances;

    cout << "\nEnter your choice: ";
    cin >> difficulty;

    switch (difficulty) {
        case 1: chances = 10; break;
        case 2: chances = 5; break;
        case 3: chances = 3; break;
        default: chances = 5; break;
    }

    cout << "\nGreat! You have selected the "
         << (difficulty == 1 ? "Easy" : (difficulty == 2 ? "Medium" : "Hard"))
         << " difficulty level.\nLet's start the game!\n";

    int number = generateRandomNumber(1, 100);
    int guess;

    for (int i = 0; i < chances; i++)
    {
        cout << "\nEnter your guess: ";
        cin >> guess;

        if (guess == number) {
            cout << "Congratulations! You guessed the correct number in " << i + 1 << " attempts.\n";
            return;
        } 
        else if (guess < number) {
            cout << "The number is greater than " << guess << ".\n";
        } 
        else {
            cout << "The number is less than " << guess << ".\n";
        }
    }
    cout << "\nYou ran out of guesses! The correct number was " << number << ". Better luck next time!\n";
}

int main()
{
    cout << "\nWelcome to the Number Guessing Game!\n"
         << "I'm thinking of a number between 1 and 100.\n"
        << "You have a limited number of chances to guess the correct number.\n";

    char playAgain;

    do {
        playGame();
        
        cout << "\nDo you want to try again? (y/n): ";
        cin >> playAgain;

    } while (playAgain == 'y' || playAgain == 'Y');

    return 0;
}