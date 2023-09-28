#include <bits/stdc++.h>
int main()
{
    int secret_number, user_guess;

    // Initialize random seed
    std::srand(std::time(0));

    // Generate a random number between 1 and 100
    secret_number = std::rand() % 100 + 1;

    std::cout << "Welcome to the Number Guessing Game!\n";

    while (true)
    {
        std::cout << "Enter your guess (between 1 and 100): ";
        std::cin >> user_guess;

        if (user_guess < secret_number)
        {
            std::cout << "Too low! Try again.\n";
        }
        else if (user_guess > secret_number)
        {
            std::cout << "Too high! Try again.\n";
        }
        else
        {
            std::cout << "Congratulations! You guessed the correct number, which was " << secret_number << ".\n";
            break;
        }
    }

    return 0;
}
