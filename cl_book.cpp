#include <vector>
#include <iostream>
#include "cl_book.h"

using namespace std;


//  ������� ����������� ����� ����� �� ������� ������ � ��������
                            //  �����, ��������, ������ ���� ����
void cl_book::get_num_from_name(string auth, string name, vector<cl_book> &lib) {
    bool key = false; // ���� ��� �� ��� ��� ����� �� ����� �����, ������� ���������
    for (int i = 0; i < lib.size(); i++){ // ������� ���� ��������� ������
        if (lib[i].get_name() == name && lib[i].get_author() == auth){ // ���������� �������� � ������ ����� � ������� (������ �������� ���)
            cout << "�����: " << lib[i].get_author() << endl;       // ������ ��� ������, ��� �����, ����� �����
            cout << "��������: " << lib[i].get_name() << endl;
            cout << "������������������ �����: " << lib[i].get_invent() << endl;
            key = true;
        }
    }
    if (key == false){ // ���� �� ������� �� ����� ����� � ������ � ������� �������
        cout << "����� �� �������" << endl;
    }
}


// ����������, ����������� �� ����������� �����
// � �������� this ��������������� ������ ������, � ������ ��������� � ���������� ������� �� ������
void cl_book::one_publisher(cl_book &ob_2){
    // ����� this -> ������ ��� this ��� ��������� �� ������� ������ � �������� ������� �����
    // ���� ���������� ������� ����� �������, �� ������� ���������
    if (this->get_puplisher() == ob_2.get_puplisher()){
        cout << "����� " << this -> get_name() << " � " <<  ob_2.get_name() << " �� ���������� �����������" << endl;
    } else {
        cout << "����� " << this -> get_name() << " � " <<  ob_2.get_name() << " �� ������ �����������" << endl;
    }
}

