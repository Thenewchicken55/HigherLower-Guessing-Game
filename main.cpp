#include <iostream>
#include <string_view>

int randomInt(int min, int max) {
    srand(time(0));
    int range = max - min + 1;
    return rand() % range + min;
}

bool isNumber(const std::string& input)
{
    try {
        std::stoi(input);
        return true;
    } catch (std::invalid_argument&) {
        std::cerr << "That is not a number" << std::endl;
        return false;
    } catch (std::out_of_range&) {
        std::cerr << "Invalid input" << std::endl;
        return false;
    }
    return false;
}

int main()
{
    int min = -255, max = 255, answer = 0;

    // welcome message
    std::cout << "Welcome to Numeber Guesser 1.0" << std::endl;
    std::cout << "This program tries to guess the number you have in mind" << std::endl;
    std::cout << "Let's start, please pick a number between [-255, and 255]" << std::endl;

    // get input
    std::string input;
    std::cin >> input;
    if (!isNumber(input)) {
        return 1;
    }
    answer = std::stoi(input);

    // guess numbers
    int guess = randomInt(min, max);
    while(guess != answer) {
        std::cout << "Is your number " << guess << "?";
        std::cin >> input;

        if (input == "h") {
            min = guess + 1;
        } else if (input == "l") {
            max = guess - 1;
        } else {
            std::cout << "Say either 'h' for higher, or 'l' for lower" << std::endl;
        }

        guess = randomInt(min, max);
    }

    // confirm the right answer
    std::cout << "AH-HA! I got it now! Is your number " << guess << "? (y/n)";
    while(true) {
        std::cin >> input;
        if (input == "y") {
            std::cout << "I win!" << std::endl;
            break;
        } else if (input == "n") {
            std::cout << "You are cheating!" << std::endl;
            break;
        } else {
            std::cout << "y or n?" << std::endl;
        }
    }

    return 0;
}
