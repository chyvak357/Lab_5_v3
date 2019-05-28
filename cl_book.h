#ifndef LAB1_V5_CL_BOOK_H
#define LAB1_V5_CL_BOOK_H

#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

class cl_book {
private:

    string author;      // �����
    string name;      // ��������
    int invent;       // ����������� �����
    string pub;     // �����������
    int page;       //���������� �������
    int price;       // ����

public:
    cl_book(){ // ����������� ��� ����������
        author = "Unnamed";
        name = "Unnamed";
        invent = 0;
        pub = "Unnamed";
        page = 0;
        price = 0;
    }

        // �����    ���    ������ �����     ���-��     �������     ����
    cl_book(string a, string nam, int n, string pubg, int num, int p ){ // ����������� � ����������
        author = a;
        name = nam;
        invent = n;
        pub = pubg;
        page = num;
        price = p;
    }

    virtual ~cl_book(){ // ����������
        cout << "������ ����� �����" <<  endl << endl;
    }

    void set_price(int p) { // ������ ����
        price = p;
    }

    void set_author(string a){ // ������ �����
        author = a;
    }

    void set_name(string n){
        name = n;
    }

    void set_page(int n){
        page = n;
    }

    void set_invent(int n){
        invent = n;
    }

    void set_pupblisher(string pubg){
        pub = pubg;
    }

    void set_string(int n){
        page = n;
    }

    string get_author(){
        return author;
    }

    string get_name(){
        return name;
    }

    int get_invent(){
        return invent;
    }

    string get_puplisher(){
        return pub;
    }

    int get_page(){
        return page;
    }

    int get_price(){    // �������� ���� �����
        return price;
    }

    // �� �������� ����� � ������� ������ ������� ������ ����� �����
    void get_num_from_name(string auth, string name, vector<cl_book> &lib);

    // ����������� ������ ��� ����� �� ����� ���������������� � ������ ������
    virtual void one_publisher(cl_book &ob_2);

};
#endif //LAB1_V5_CL_BOOK_H

/*����� ����� ����:
 * �����
 * ��������
 * ����������� �����
 * ������������
 * ���������� �������
 * ����
 *
 * �������������� ��������:
 *          1) ������� ����������� ����� ����� �� ������� ������ � ��������.
 *          2) ����������, ������ �� ��� ����� � ����� ������������.
 */

/*����� � ��� ����� ����:
 * �������� ����
 * ���� �������������� �����
 *
 * �������������� ��������
 *          3) ������� �� ������������ �������� ����.
 *          4) ����������, ����� �� ���� ���� ��������� � ��������������.
 *
 */