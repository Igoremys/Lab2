#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

// Структура для представления компьютера
struct Computer {
    string name;
    double cpuFrequency;  // Частота процессора в ГГц
    int ramSize;          // Объем оперативной памяти в ГБ
    int hddSize;          // Объем жесткого диска в ГБ
    double price;         // Цена в долларах
};

// Функция для записи компьютеров в бинарный файл
void writeComputersToBinaryFile(const string& filename, const vector<Computer>& computers) {
    ofstream file(filename, ios::binary);
    if (!file.is_open()) {
        cerr << "Ошибка открытия файла для записи" << endl;
        return;
    }

    for (const auto& computer : computers) {
        file.write(reinterpret_cast<const char*>(&computer), sizeof(Computer));
    }

    file.close();
}

// Функция для чтения компьютеров из бинарного файла
vector<Computer> readComputersFromBinaryFile(const string& filename) {
    vector<Computer> computers;
    ifstream file(filename, ios::binary);
    if (!file.is_open()) {
        cerr << "Ошибка открытия файла для чтения" << endl;
        return computers;
    }

    Computer computer;
    while (file.read(reinterpret_cast<char*>(&computer), sizeof(Computer))) {
        computers.push_back(computer);
    }

    file.close();
    return computers;
}

int main() {
    setlocale(LC_ALL, "Ru");
    // Создаем несколько компьютеров
    vector<Computer> computers = {
        {"Computer1", 3.0, 8, 512, 1000.0},
        {"Computer2", 2.5, 16, 1024, 1500.0},
        {"Computer3", 2.8, 4, 256, 800.0},
        {"AsusComputer", 2.2, 16, 512, 1200.0},  // Asus компьютер с частотой процессора менее 2 ГГц
        {"AsusComputer2", 2.6, 8, 512, 1100.0},  // Asus компьютер с частотой процессора более 2 ГГц
    };

    // Записываем компьютеры в бинарный файл
    writeComputersToBinaryFile("computers.bin", computers);

    // Читаем компьютеры из бинарного файла
    vector<Computer> readComputers = readComputersFromBinaryFile("computers.bin");

    // Вычисляем общую стоимость всех компьютеров, у которых частота процессора более 2 ГГц/сек от фирмы Asus
    double totalCost = 0.0;
    cout << "Информация о компьютерах фирмы Asus с частотой процессора более 2 ГГц:" << endl;
    for (const auto& computer : readComputers) {
        if (computer.cpuFrequency > 2.0 && computer.name.find("Asus") != string::npos) {
            totalCost += computer.price;
            cout << "Название: " << computer.name << ", Цена: $" << computer.price << endl;
        }
    }

    cout << "Общая стоимость: $" << totalCost << endl;

    return 0;
}
