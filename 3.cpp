#include <iostream>
#include <fstream>
#include <cctype> // Для isdigit()
using namespace std;
int main() {
    setlocale(LC_ALL, "RU");
    ifstream inputFile("old.txt");
    ofstream outputFile("new.txt");

    if (!inputFile.is_open()) {
        cerr << "Ошибка открытия файла old.txt" << endl;
        return 1;
    }

    if (!outputFile.is_open()) {
        cerr << "Ошибка открытия файла new.txt" << endl;
        return 1;
    }

    char ch;
    while (inputFile.get(ch)) {
        // Проверяем, является ли символ цифрой
        if (!isdigit(ch)) {
            // Если не цифра, записываем её в новый файл
            outputFile << ch;
        }
    }

    cout << "Цифры были удалены из файла old.txt, результат записан в файл new.txt" << endl;

    inputFile.close();
    outputFile.close();

    return 0;
} 
