
#ifndef LAB1_V9_MENU_H
#define LAB1_V9_MENU_H

#include "cl_book.h"
#include "cl_kind.h"
#include <string>
#include <iostream>

using namespace std;


class menu {
private:
    vector<cl_book > book_list; // ������ ���� �������� ����� �������
    vector<cl_kind > kind_list; // ������ ���� �������� ����� �����������
    int key = 0;

public:
    menu() {}
    ~menu() {}
    void create_default(); // ������ ������ ��� ����������
    void create_user(); // ������� ������ � ����������� ������������
    void change_obj(); // �������� ������
    void show_all(int type); // �������� ��� ������� �����
    void unique_act(); // ��������� �������������� ��������
    void main_menu(); // ������� ����
    int select_class(); // ����� ������

};


#endif //LAB1_V9_MENU_H
