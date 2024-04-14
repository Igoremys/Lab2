#include <iostream>
#include <fstream>
using namespace std;

int main() {
    setlocale(LC_ALL, "RU");
    ifstream file("a.txt");
    if (!file.is_open()) {
        cout << "Невозможно открыть файл a.txt" << std::endl;
        return 1;
    }

    int countZeros = 0;
    double product = 1;
    double num;

    while (file >> num) {
        if (num == 0) {
            countZeros++;
        }
        else if (num < 1 && num > 0) {
            product *= num;
        }
    }

    file.close();

    cout << "Количество нулевых элементов: " << countZeros << endl;
    cout << "Произведение элементов меньших 1 и больших 0: " << product << endl;

    return 0;
}
