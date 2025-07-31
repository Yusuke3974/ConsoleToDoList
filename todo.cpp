#include "todo.h"
#include <iostream>
#include <fstream>

void ToDoList::addTask(const std::string &task)
{
    tasks.push_back(task);
}

void ToDoList::showTasks() const
{
    if (tasks.empty())
    {
        std::cout << "No tasks available.\n";
        return;
    }
    for (size_t i = 0; i < tasks.size(); ++i)
    {
        std::cout << i + 1 << ". " << tasks[i] << "\n";
    }
}

void ToDoList::deleteTask(int index)
{
    if (index >= 0 && index < (int)tasks.size())
    {
        tasks.erase(tasks.begin() + index);
    }
    else
    {
        std::cout << "Invalid task number.\n";
    }
}

void ToDoList::load(const std::string &filename)
{
    std::ifstream file(filename);
    if (!file)
        return;

    tasks.clear();
    std::string line;
    while (std::getline(file, line))
    {
        if (!line.empty())
            tasks.push_back(line);
    }
}

void ToDoList::save(const std::string &filename) const
{
    std::ofstream file(filename);
    for (const auto &task : tasks)
    {
        file << task << "\n";
    }
}
