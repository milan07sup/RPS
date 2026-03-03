#include <iostream>
#include <locale>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include "quick_sort.h"
#include "array.h"
#include "validation.h"

static void show_menu() {
    std::cout << "\nМеню программы:\n"
        << "1. Ввод массива с клавиатуры\n"
        << "2. Сгенерировать случайный массив\n"
        << "3. Загрузить массив из файла\n"
        << "4. Выход\n"
        << "Выберите пункт: ";
}

int main() {
    // Устанавливаем русскую кодировку
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");

    srand((unsigned)time(0));

    while (true) {
        show_menu();

        int choice = input_check_int();  // ИСПРАВЛЕНО: объявляем переменную

        if (choice == 4) {
            std::cout << "Выход из программы\n";
            break;
        }

        std::vector<int> array;

        switch (choice) {
        case 1:
            array = Array::input_array();
            break;
        case 2:
            array = Array::random_array();
            break;
        case 3:
            array = Array::load_from_file();
            break;
        default:
            std::cout << "Неверный ввод! Попробуйте снова\n";
            continue;
        }

        if (!array.empty()) {
            Array::print_array(array, "Исходный массив: ");

            std::vector<int> sorted_array = QuickSort::sort(array);

            Array::print_array(sorted_array, "Отсортированный массив: ");

            std::cout << "Сохранить результат в файл? (1 - да, 2 - нет): ";
            int save = input_check_int();

            if (save == 1) {
                Array::save_to_file(array, sorted_array);
            }
        }
    }

    return 0;
}