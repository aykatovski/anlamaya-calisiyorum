#include <iostream>
#include <chrono>
#include <thread>
#include <sstream>
#include <algorithm> // Include algorithm header

int main() {
    std::string message = "gunaydin-askim-umarim-rahat-uyumussundur-ve-gunun-guzel-gecer-bugun-hava-soguk-ve-ruzgarli-usumemeye-dikkat-et-seni-seviyorum-aykat-";
    std::replace(message.begin(), message.end(), '-', ' '); // Replace hyphens with spaces

    std::istringstream iss(message);
    std::string word;
    while (std::getline(iss, word, ' ')) {
        for (char letter : word) {
            std::cout << letter;
            std::this_thread::sleep_for(std::chrono::milliseconds(75)); // Speed up to 75 milliseconds per letter
        }
        std::cout << " "; // Add space between words
        std::this_thread::sleep_for(std::chrono::milliseconds(75)); // Speed up delay between words
    }

    std::this_thread::sleep_for(std::chrono::milliseconds(1750)); // Speed up pause for 1.75 seconds (3500 - 1750)

    return 0;
}

