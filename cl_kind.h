#include "cl_book.h"
#include <string>
#include <vector>

#ifndef LAB1_V5_KIND_H
#define LAB1_V5_KIND_H


class cl_kind : public cl_book {
private:
    string kind_name;   // ��� �����
    string genre;       // ���� �����

public:

    // ����������� ��� ����������
    cl_kind() : cl_book() {
        genre = "Unnamed";
        kind_name = "Unnamed";
    }

    // ����������� � ����������
    // �����    ���    ������ �����     ���-��     �������     ����,    ���,    ����
    cl_kind(string a, string nam, int n, string pubg, int num, int p, string k, string g )
            : cl_book(a, nam, n, pubg, num, p) // ��� ����� �������� �� ����������� ������ book
    {
        kind_name = k;
        genre = g;
    }

    ~cl_kind(){ // ����������
        cout << "������ ���� ����� �����" << endl << endl;
    }

    void set_kind(string k){
        kind_name = k;
    }

    void set_genre(string g){
        genre = g;
    }

    string get_kind(){
        return kind_name;
    }

    string get_genre(){
        return genre;
    }


    // ������� �� ������������ �������� ����
    // ��������� ��� ����� � �� ������ ������ ���� ����
    void get_kind_from_inv(int inv, vector<cl_kind> &lib);

    // ��� �� ���� ���� �������������� (������ ���� �������� � ���� KIND)
    void who_is_fiction(cl_kind & ob2);

};


#endif //LAB1_V5_KIND_H

/*����� � ��� �����
 * ����:
 *       �������� ����
 *       ���� �������������� �����
 *
 * �������������� ��������
 *          3) ������� �� ������������ �������� ����.
 *          4) ����������, ����� �� ���� ���� ��������� � ��������������.
 *
 */