
#ifndef LAB1_V9_MENU_H
#define LAB1_V9_MENU_H

#include "cl_book.h"
#include "cl_kind.h"
#include <string>
#include <iostream>

using namespace std;


class menu {
private:
    vector<cl_book > book_list; // Список всех обьектов клаас Игрушка
    vector<cl_kind > kind_list; // Список всех обьектов клаас Конструктор
    int key = 0;

public:
    menu() {}
    ~menu() {}
    void create_default(); // Созать обьект без параметров
    void create_user(); // Создать обьект с параметрами пользователя
    void change_obj(); // Изменить обьект
    void show_all(int type); // Показать все обьекты класс
    void unique_act(); // Выполнить дополнительные операции
    void main_menu(); // Главное меню
    int select_class(); // Выбор класса

};


#endif //LAB1_V9_MENU_H
