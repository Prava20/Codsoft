#include <iostream>
#include <vector>
#include <iomanip>
#include <stdexcept>

class Grading {
public:
    Grading() {
        std::cout << "Grading System is as Follows" << std::endl;
        std::cout << "Average Percentage\tGrade" << std::endl;
        std::cout << "90-100\t\t\tS(Outstanding)" << std::endl;
        std::cout << "75-89\t\t\tA(Excellent)" << std::endl;
        std::cout << "66-74\t\t\tB(Very Good)" << std::endl;
        std::cout << "56-65\t\t\tC(Good)" << std::endl;
        std::cout << "50-55\t\t\tD(Average)" << std::endl;
        std::cout << "45-49\t\t\tE(Poor)" << std::endl;
        std::cout << "<45\t\t\tF(Fail)" << std::endl;
    }

    void gradeAssign(float averagePercentage, float total) {
        char Grade;
        if (averagePercentage >= 90 && averagePercentage <= 100) {
            Grade = 'S';
        } else if (averagePercentage >= 75 && averagePercentage <= 89) {
            Grade = 'A';
        } else if (averagePercentage >= 66 && averagePercentage <= 74) {
            Grade = 'B';
        } else if (averagePercentage >= 56 && averagePercentage <= 65) {
            Grade = 'C';
        } else if (averagePercentage >= 50 && averagePercentage <= 55) {
            Grade = 'D';
        } else if (averagePercentage >= 45 && averagePercentage <= 49) {
            Grade = 'E';
        } else if (averagePercentage < 45) {
            Grade = 'F';
        } else {
            Grade = 'I';
        }
        display(total, averagePercentage, Grade);
    }

    void display(float total, float averagePercentage, char Grade) {
        std::cout << "Your Result as Follows" << std::endl;
        std::cout << "Total Marks--->" << total << "\nAverage Percentage--->" << averagePercentage << "\nGrade--->" << Grade << std::endl;
    }
};

int main() {
    Grading gr;
    std::cout << "Enter the Total Number of Subjects: ";
    int Subjects;
    std::cin >> Subjects;

    std::vector<int> marks(Subjects);

    std::cout << "Enter the Respective Subjects Marks out of 100" << std::endl;
    for (int i = 0; i < Subjects; i++) {
        std::cout << "Subject-" << (i + 1) << "--->";
        try {
            std::cin >> marks[i];
            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Invalid Type\nRe-Enter the Marks" << std::endl;
                i--;
            }
        } catch (const std::runtime_error& e) {
            std::cout << "Invalid Type\nRe-Enter the Marks" << std::endl;
            i--;
        }
    }

    int total = 0;
    for (int i = 0; i < Subjects; i++) {
        total += marks[i];
    }

    float averagePercentage = static_cast<float>(total) / Subjects;
    gr.gradeAssign(averagePercentage, total);

    return 0;
}
