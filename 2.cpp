#include <iostream>
#include <fstream>
using namespace std;

int main() {
    setlocale(LC_ALL, "RU");
    ifstream inputFile("a.txt");
    ofstream outputFile("a2.txt");

    if (!inputFile.is_open()) {
        cerr << "Ошибка открытия файла a.txt" << endl;
        return 1;
    }

    if (!outputFile.is_open()) {
        cerr << "Ошибка открытия файла a2.txt" << endl;
        return 1;
    }

    double num;
    while (inputFile >> num) {
        if (num != 0) {
            outputFile << num << endl;
        }
    }

    cout << "Ненулевые элементы файла a.txt были записаны в файл a2.txt" << endl;

    inputFile.close();
    outputFile.close();

    return 0;
}
