#include <iostream>
#include "todo.h"

int main()
{
    ToDoList list;
    list.load("tasks.txt");

    int choice;
    do
    {
        std::cout << "1. Add Task\n2. Show Tasks\n3. Delete Task\n0. Exit\n> ";
        std::cin >> choice;

        if (choice == 1)
        {
            std::string task;
            std::cout << "Enter task: ";
            std::cin.ignore();
            std::getline(std::cin, task);
            list.addTask(task);
        }
        else if (choice == 2)
        {
            list.showTasks();
        }
        else if (choice == 3)
        {
            int index;
            std::cout << "Enter task number to delete: ";
            std::cin >> index;
            list.deleteTask(index - 1);
        }
    } while (choice != 0);

    list.save("tasks.txt");
    return 0;
}
