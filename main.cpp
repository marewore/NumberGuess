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

int main()
{
    cout << "Welcome to the Number Guessing Game!\n"
        << "I'm thinking of a number between 1 and 100.\n"
        << "You have a limited number of chances to guess the correct number.\n"
        << "\nPlease select the difficulty level:\n"
        << "1. Easy (10 chances)\n"
        << "2. Medium (5 chances)\n"
        << "3. Hard (3 chances)\n";

    int difficulty, chances;
    const int EASY = 1, MEDIUM = 2, HARD = 3;

	cout << "\nEnter your choice: ";
    cin >> difficulty;

    switch (difficulty) {
    case EASY: chances = 10; break;
    case MEDIUM: chances = 5; break;
    case HARD: chances = 3; break;
    default: chances = 5; break;
    }

    cout << "\nGreat! You have selected the "
        << (difficulty == EASY ? "Easy" : (difficulty == MEDIUM ? "Medium" : "Hard"))
        << " difficulty level.\nLet's start the game!\n";
       
    int number = generateRandomNumber(1, 100);

    int guess;
    bool guessed = false;

    for (int i = 0; i < chances; i++)
    {
        cout << "\nEnter your guess: ";
        cin >> guess;

        if (guess == number) {
            cout << "Congratulations! You guessed the correct number in " << i << " attempts.";
            guessed = true;
            break;
		} 
        else if (guess < number) {
			cout << "The number is greater than " << guess << ".\n";
		} 
        else {
            cout << "The number is less than " << guess << ".\n";
        }
    }

    if (!guessed) {
        cout << "\nYou ran out of guesses! The correct number was " << number << ". Better luck next time!\n";
    }

	return 0;
}
