#include <iostream>
#include <fstream>
using namespace std;

int main() {
    setlocale(LC_ALL, "RU");
    ifstream inputFile("Chisla.txt");

    if (!inputFile.is_open()) {
        cerr << "Ошибка открытия файла Chisla.txt" << endl;
        return 1;
    }

    int number;
    int position = 0; // Текущая позиция числа в файле
    int negativeCount = 0; // Счетчик отрицательных чисел на четных позициях

    while (inputFile >> number) {
        if (position % 2 == 0 && number < 0) {
            negativeCount++;
        }
        position++;
    }

    cout << "Количество отрицательных чисел на четных позициях: " << negativeCount << endl;

    inputFile.close();

    return 0;
}
