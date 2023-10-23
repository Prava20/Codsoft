#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

bool play() {
    int max = 10;
    int score = 0;
    int number = rand() % 100 + 1;
    std::cout << "You can have a maximum of " << max << " attempts." << std::endl;

    while (score < max) {
        std::cout << "Enter a number to guess: ";
        int num;
        if (std::cin >> num) {
            int diff = number - num;
            if (diff == 0) {
                std::cout << "Congratulations! Guess is correct." << std::endl;
                std::cout << "Number of attempts you have taken is: " << (score + 1) << std::endl;
                return true;
            } else if (diff < 0) {
                std::cout << "Guess is too high." << std::endl;
            } else {
                std::cout << "Guess is too low." << std::endl;
            }
            score++;
        } else {
            std::cout << "Invalid input. Please enter a valid number." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }

    if (score >= max) {
        std::cout << "Maximum attempts reached. The correct number was: " << number << std::endl;
    }

    return false;
}

int main() {
    srand(static_cast<unsigned>(time(nullptr));
    std::cout << "Welcome to the Number Guessing Game!" << std::endl;
    bool rounds;
    int roundsWon = 0;

    while (true) {
        rounds = play();
        if (rounds) {
            roundsWon++;
        }

        std::cout << "Do you want to play again? (yes/no): ";
        std::string Again;
        std::cin >> Again;
        if (Again != "yes") {
            break;
        }
    }

    std::cout << "Thanks for playing!\nRounds Won: " << roundsWon << std::endl;
    return 0;
}
