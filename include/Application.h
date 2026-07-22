#ifndef APPLICATION_H
#define APPLICATION_H

#include "StudentManager.h"

class Application
{
private:
    StudentManager manager;

public:
    void run();

private:
    void showMenu();

    void addStudent();

    void searchStudent();

    void deleteStudent();
};

#endif