#include <iostream>
#include <array>
#include <string_view>
#include <thread>
#include <chrono>
#include <random>

int randomInt(int min, int max) {
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

    std::cout << input << std::endl;

    return 0;
}