#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

struct Worker {
    string lastName;
    string firstName;
    string middleName;
    string address;
    string nationality;
    string birthDate;
    int workshopNumber;
    int employeeID;
    string education;
    int startYear;
};

int main() {
    setlocale(LC_ALL, "Ru");
    ifstream inputFile("workers.txt");
    ofstream outputFile("workers_2010.txt");

    if (!inputFile.is_open()) {
        cerr << "Ошибка открытия файла workers.txt" << endl;
        return 1;
    }

    if (!outputFile.is_open()) {
        cerr << "Ошибка открытия файла workers_2010.txt" << endl;
        return 1;
    }

    vector<Worker> workers;

    string line;
    while (getline(inputFile, line)) {
        std::istringstream iss(line);
        Worker worker;
        char delimiter = ';';

        getline(iss, worker.lastName, delimiter);
        getline(iss, worker.firstName, delimiter);
        getline(iss, worker.middleName, delimiter);
        getline(iss, worker.address, delimiter);
        getline(iss, worker.nationality, delimiter);
        getline(iss, worker.birthDate, delimiter);
        iss >> worker.workshopNumber >> delimiter;
        iss >> worker.employeeID >> delimiter;
        getline(iss, worker.education, delimiter);
        iss >> worker.startYear;

        // Проверяем, поступил ли работник на работу в 2010 году
        if (worker.startYear == 2010) {
            workers.push_back(worker);
        }
    }

    // Записываем данные о работниках, поступивших в 2010 году, в новый файл
    for (const auto& worker : workers) {
        outputFile << worker.lastName << ';' << worker.firstName << ';' << worker.middleName << ';' << worker.address << ';'
            << worker.nationality << ';' << worker.birthDate << ';' << worker.workshopNumber << ';' << worker.employeeID << ';'
            << worker.education << ';' << worker.startYear << endl;
    }

    cout << "Данные о работниках, поступивших на работу в 2010 году, сохранены в файл workers_2010.txt" << endl;

    inputFile.close();
    outputFile.close();

    return 0;
}
