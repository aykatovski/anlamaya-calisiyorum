#include <iostream>
#include <sstream>
#include <vector>

void GradeQuestion(const std::string& studentAnswers, const std::string& answerSheet, int& correctCount, int& wrongCount, int& emptyCount) {
    int maxLength = std::max(studentAnswers.length(), answerSheet.length());

    for (int i = 0; i < maxLength; ++i) {
        char studentAns = (i < studentAnswers.length()) ? std::tolower(studentAnswers[i]) : '-';
        char answer = (i < answerSheet.length()) ? std::tolower(answerSheet[i]) : '-';

        bool isEmpty = studentAns == '-' || answer == '-';
        bool isWrong = !isEmpty && studentAns != answer;

        if (!isEmpty) {
            if (isWrong) {
                wrongCount++;
            }
            else {
                correctCount++;
            }
        }
        else {
            emptyCount++;
        }
    }
}

double CalculatePoints(int correctCount, int wrongCount) {
    return correctCount - (wrongCount * 0.25);
}

void DisplayResult(int questions, int correct, int wrong, int empty, double points) {
    std::cout << "Number of questions: " << questions
        << " | Right: " << correct
        << " | Wrong: " << wrong
        << " | Empty: " << empty
        << " | Points: " << points << std::endl;
}

void DisplayTotalResult(int totalQuestions, int totalCorrect, int totalWrong, int totalEmpty, double totalPoints) {
    std::cout << "------- Total Result -------" << std::endl;
    std::cout << "Total Questions: " << totalQuestions
        << " | Total Right: " << totalCorrect
        << " | Total Wrong: " << totalWrong
        << " | Total Empty: " << totalEmpty
        << " | Total Points: " << totalPoints << std::endl;
}

int main() {
    std::cout << "Enter pairs of strings in the format 'student's answers / answer sheet'." << std::endl;
    std::cout << "Separate each pair by pressing Enter. To finish, press Enter twice." << std::endl;

    int totalQuestions = 0;
    int totalCorrect = 0;
    int totalWrong = 0;
    int totalEmpty = 0;

    std::string input;
    while (std::getline(std::cin, input) && !input.empty()) {
        std::stringstream ss(input);
        std::string studentAnswers, answerSheet;
        if (std::getline(ss, studentAnswers, '/') && std::getline(ss, answerSheet)) {
            studentAnswers = studentAnswers.substr(studentAnswers.find_first_not_of(" \t\r\n"), studentAnswers.find_last_not_of(" \t\r\n") + 1);
            answerSheet = answerSheet.substr(answerSheet.find_first_not_of(" \t\r\n"), answerSheet.find_last_not_of(" \t\r\n") + 1);

            int correctCount = 0;
            int wrongCount = 0;
            int emptyCount = 0;

            GradeQuestion(studentAnswers, answerSheet, correctCount, wrongCount, emptyCount);

            totalQuestions += studentAnswers.length();
            totalCorrect += correctCount;
            totalWrong += wrongCount;
            totalEmpty += emptyCount;

            DisplayResult(studentAnswers.length(), correctCount, wrongCount, emptyCount, CalculatePoints(correctCount, wrongCount));
        }
        else {
            std::cout << "Invalid input format. Please enter the pair in the correct format." << std::endl;
        }
    }

    DisplayTotalResult(totalQuestions, totalCorrect, totalWrong, totalEmpty, CalculatePoints(totalCorrect, totalWrong));

    return 0;
}
