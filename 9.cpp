#include <iostream>
#include <fstream>
#include <string>

// Функция для записи символов в бинарный файл
void writeCharsToBinaryFile(const std::string& filename, const std::string& chars) {
    std::ofstream file(filename, std::ios::binary);
    if (!file.is_open()) {
        std::cerr << "Ошибка открытия файла для записи" << std::endl;
        return;
    }

    file.write(chars.c_str(), chars.size());

    file.close();
}

// Функция для замены символов '*' и '/' на символ '+'
void replaceCharsInBinaryFile(const std::string& filename) {
    std::fstream file(filename, std::ios::binary | std::ios::in | std::ios::out);
    if (!file.is_open()) {
        std::cerr << "Ошибка открытия файла для чтения и записи" << std::endl;
        return;
    }

    // Определяем размер файла
    file.seekg(0, std::ios::end);
    std::streampos fileSize = file.tellg();
    file.seekg(0, std::ios::beg);

    // Читаем содержимое файла в строку
    std::string content(fileSize, '\0');
    file.read(&content[0], fileSize);

    // Заменяем символы '*' и '/' на символ '+'
    size_t pos = 0;
    while ((pos = content.find_first_of("*/", pos)) != std::string::npos) {
        content[pos] = '+';
        ++pos;
    }

    // Перемещаем указатель в начало файла и перезаписываем содержимое
    file.seekp(0, std::ios::beg);
    file.write(content.c_str(), content.size());

    file.close();
}

int main() {
    setlocale(LC_ALL, "Ru");
    // Создаем строку с символами русского алфавита
    std::string russianAlphabet = "абвгдеёжзийклмнопрстуфхцчшщъыьэюя";

    // Записываем символы в бинарный файл
    writeCharsToBinaryFile("chars.bin", russianAlphabet);

    // Читаем и печатаем символы из бинарного файла перед изменением
    std::cout << "Символы до замены: ";
    std::ifstream inFile("chars.bin", std::ios::binary);
    char c;
    while (inFile.get(c)) {
        std::cout << c;
    }
    std::cout << std::endl;
    inFile.close();

    // Заменяем символы '*' и '/' на символ '+'
    replaceCharsInBinaryFile("chars.bin");

    // Читаем и печатаем символы из бинарного файла после изменения
    std::cout << "Символы после замены: ";
    inFile.open("chars.bin", std::ios::binary);
    while (inFile.get(c)) {
        std::cout << c;
    }
    std::cout << std::endl;
    inFile.close();

    return 0;
}
