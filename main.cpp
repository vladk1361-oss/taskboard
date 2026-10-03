#include <iostream>
#include <limits>
#include <string>
#include <vector>

int main() {
    std::vector<std::string> tasks;
    int choice = -1;

    while (choice != 0) {
        std::cout << "\n--- Мой список задач ---\n";
        std::cout << "1 - Добавить задачу\n";
        std::cout << "2 - Показать задачи\n";
        std::cout << "3 - Удалить задачу\n";
        std::cout << "4 - Очистить весь список\n";
        std::cout << "0 - Выйти\n";
        std::cout << "Выбор: ";

        if (!(std::cin >> choice)) {
            std::cout << "Введите число.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (choice == 1) {
            std::string task;
            std::cout << "Задача: ";
            std::getline(std::cin, task);

            if (task.empty()) {
                std::cout << "Задача пустая.\n";
            } else {
                tasks.push_back(task);
                std::cout << "Добавлено.\n";
            }
        } else if (choice == 2) {
            if (tasks.empty()) {
                std::cout << "Список пока пуст.\n";
            } else {
                for (std::size_t index = 0; index < tasks.size(); ++index) {
                    std::cout << index + 1 << ". " << tasks[index] << '\n';
                }
            }
        } else if (choice == 3) {
            int number;
            std::cout << "Номер задачи: ";

            if (!(std::cin >> number)) {
                std::cout << "Введите число.\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            } else {
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                if (number < 1 || number > static_cast<int>(tasks.size())) {
                    std::cout << "Задачи с таким номером нет.\n";
                } else {
                    tasks.erase(tasks.begin() + number - 1);
                    std::cout << "Удалено.\n";
                }
            }
        } else if (choice == 4) {
            if (tasks.empty()) {
                std::cout << "Список уже пуст.\n";
            } else {
                tasks.clear();
                std::cout << "Все задачи удалены.\n";
            }
        } else if (choice != 0) {
            std::cout << "Такой команды нет.\n";
        }
    }

    std::cout << "До свидания!\n";
}
