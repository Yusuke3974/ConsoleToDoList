#ifndef TODO_H
#define TODO_H

#include <vector>
#include <string>

class ToDoList
{
private:
    std::vector<std::string> tasks;

public:
    void addTask(const std::string &task);
    void showTasks() const;
    void deleteTask(int index);
    void load(const std::string &filename);
    void save(const std::string &filename) const;
};

#endif
