
#include "menu.h"
#include <string>
#include <iostream>

// ������� �����. ���������� ������ ��� ����� ����� ��������� ����� ���� �������� ��� �������
// ���������� ����� ����� ���:
// 1 - ����� �����    2 - ����� ���
int menu::select_class(){
    int type;   // ��� �� �������� ����� ����������� � �������� ��� � return
    cout << "�������� �����" << endl;
    cout << "1. �����" << endl;
    cout << "2. ��� �����" << endl;
    cin >> type; // ���� � ����������
    return type;
}

// ����� ��� �������� ������� ��� ���������� (����� 1 ����)
void menu::create_default() {
    int type = select_class(); // ���������� ��� ������ ������ �������� ������ (�� ����� ����)
    switch (type) {

        case 1: { // ����� �����
            cl_book temp;                // ��������� ������, ��� �� � ��� ��������
                                         // ���������� ��� ���������� ���������� �� ������ cl_book
            book_list.push_back(temp);   // ��������� ������ � ������ ���� �������� ������ �����
                                         // ������ ����������� �� ���� �������� ��������
                                         // ����� ���� ������ ����� ������ � ������ ������� ������� ������

            // ����� ���������� ����� ������, ����� ����� ���� ������ ������ �����, ��� ����� ��������� ������
            break;
        }

        case 2: { // ����� ���
            cl_kind temp;
            kind_list.push_back(temp); // ����������� ����� ��� ������� (�������� � ����� ������)
            break;
        }

        default: // ���� ������������ ��� �� ������ �����, �� �������� ����
            cout << "������ �����" << endl;
            select_class();
    }
    main_menu();
}

// ������� �� ����������������� �����
void menu::create_user(){
    int type = select_class(); // �������� �����, ��� �������� ������� ������
    switch (type) {
        case 1: { // ����� �����
            int num; // ������ ���������� ��� ����� ����� �����
            cl_book temp;  // ��������� ������
            string name;    // ��������� ���������� ��� ����� ������

            // ����� �� ����� ���������,            ���� ������         ������ �������� ������ � ��������� �����
            cout << "������� ������ �����: " << endl;      cin >> name;     temp.set_author( name);
            cout << "������� �������� �����: " << endl;    cin >> name;     temp.set_name(name);
            cout << "������� ����������� �����: " << endl; cin >> num;      temp.set_invent(num);
            cout << "������� �����������: " << endl;       cin >> name;     temp.set_pupblisher(name);
            cout << "������� ���-�� �������: " << endl;    cin >> num;      temp.set_page(num);
            cout << "������� ����: " << endl;              cin >> num;      temp.set_price(num);

            // ������� � ����� ������ �������
            book_list.push_back(temp); // ��������� � ������ �������� ��� ������, ��� ������ ��� �������������
            break;
        }

        case 2: {  // ����� ���
            int num;                        // �� ������� ��� �� ��� � ��� �������� ������
            cl_kind temp;
            string name;
            cout << "������� ������ �����: " << endl;       cin >> name;    temp.set_author(name);
            cout << "������� �������� �����: " << endl;     cin >> name;    temp.set_name(name);
            cout << "������� ����������� �����: " << endl;  cin >> num;     temp.set_invent(num);
            cout << "������� �����������: " << endl;        cin >> name;    temp.set_pupblisher(name);
            cout << "������� ���-�� �������: " << endl;     cin >> num;     temp.set_page(num);
            cout << "������� ����: " << endl;               cin >> num;     temp.set_price(num);
            cout << "������� ��� �����: " << endl;          cin >> name;    temp.set_kind(name);
            cout << "������� ���� �����: " << endl;         cin >> name;    temp.set_genre(name);

            kind_list.push_back(temp);
            break;
        }

        default: // ���� �� ��������� ����� �����
            cout << "������ �����" << endl;
            select_class();
    }
}

// �������� ��� ������ ���� ��������� ������
// �� ���� ��������� ����� ������
void menu::show_all(int type){

    switch (type){
        case 1: { // �����
            // ���� �������� �� �������� ���� ��������� ������ (�� 0 � �� ����� )
                                // ����� size ���������� ���-�� ��������� � �������
            for (int i = 0; i < book_list.size(); i++){
                cout << "______" << i << "________" << endl; // ������ ��������

                // ����� ������,                ����� �������� ���� � ������� ������� get (��������)
                cout << "�����: " <<            book_list[i].get_author() << endl;
                cout << "��������: " <<         book_list[i].get_name() << endl;
                cout << "����������� �����: " <<book_list[i].get_invent() << endl;
                cout << "������������: " <<     book_list[i].get_puplisher() << endl;
                cout << "���������� �������: " << book_list[i].get_page() << endl;
                cout << "����: " <<             book_list[i].get_price() << endl;
                cout << "______________" << endl;
            }
            break;
        }

        case 2: { // ���
            for (int i = 0; i < kind_list.size(); i++){
                cout << "______" << i << "________" << endl;
                cout << "�����: " <<             kind_list[i].get_author() << endl;
                cout << "��������: " <<          kind_list[i].get_name() << endl;
                cout << "����������� �����: " << kind_list[i].get_invent() << endl;
                cout << "������������: " <<      kind_list[i].get_puplisher() << endl;
                cout << "���������� �������: " <<kind_list[i].get_page() << endl;
                cout << "����: " <<              kind_list[i].get_price() << endl;
                cout << "��� �����: " <<         kind_list[i].get_kind() << endl;
                cout << "����: " <<              kind_list[i].get_genre() << endl;
                cout << "______________" << endl;
            }
            break;
        }

    }
}


// ����� ��� ������������� ������� (�������� ������� �����)
void menu::change_obj(){
    int type = select_class(); // ������� �����
    int id; // ��������� ��� ������� ��������
    cout << "�������� ������ �������" << endl;
    switch (type) {
        case 1:{
            show_all(1); // ���������� ��� ������� ������ �����
            cin >> id;  // ������ ����� ������� (������ �� ������)
            int num; // ������ ���������� ��� ����� ����� �����
            string name; // ������ ���������� ��� ����� �����

            // ����� ������,    ���� ��������,    ��� ������� ������� ����������� � ������ book_list ��� �������� id ������ �������� ����
            cout << "������� ������ �����: " << endl;       cin >> name;     book_list[id].set_author(name);
            cout << "������� �������� �����: " << endl;     cin >> name;     book_list[id].set_name(name);
            cout << "������� ����������� �����: " << endl;  cin >> num;      book_list[id].set_invent(num);
            cout << "������� �����������: " << endl;        cin >> name;     book_list[id].set_pupblisher(name);
            cout << "������� ���-�� �������: " << endl;     cin >> num;      book_list[id].set_page(num);
            cout << "������� ����: " << endl;               cin >> num;      book_list[id].set_price(num);
            break;
        }

        case 2:{  // ����������
            show_all(2); // ���������� ��� ������� ������ ���
            cin >> id; // ������ ��������
            int num; // ������ ���������� ��� ����� ����� �����
            string name; // ��������� ��������� ��� ����� �����

            cout << "������� ������ �����: " << endl;      cin >> name;     kind_list[id].set_author(name);
            cout << "������� �������� �����: " << endl;    cin >> name;     kind_list[id].set_name(name);
            cout << "������� ����������� �����: " << endl; cin >> num;      kind_list[id].set_invent(num);
            cout << "������� �����������: " << endl;       cin >> name;     kind_list[id].set_pupblisher(name);
            cout << "������� ���-�� �������: " << endl;    cin >> num;      kind_list[id].set_page(num);
            cout << "������� ����: " << endl;              cin >> num;      kind_list[id].set_price(num);
            cout << "������� ��� �����: " << endl;         cin >> name;     kind_list[id].set_kind(name);
            cout << "������� ���� �����: " << endl;        cin >> name;     kind_list[id].set_genre(name);
            break;
        }

    }
}


// ������� �������������� �������� (�� ��� ������� � �������� � ����)
void menu::unique_act(){
    int type = select_class(); // ����� ��� ������ ������ ���������
    int temp;                   // ��������� ��� ������ ��������
    switch (type) {
        case 1:{ // �����
            // ����� �������� ��� ������� �����
            cout << "1. ������� ����������� ����� ����� �� ������� ������ � ��������" << endl;
            cout << "2. ����������, ������ �� ��� ����� � ����� ������������" << endl;
            cin >> temp;
            if (temp == 1){ // ���� ������� 1� ��������
                string name, auth; // ��������� ���������� ��� ������ � �������� �����
                cout << "������� ������� ������: " << endl;
                cin >> auth;
                cout << "������� �������� �����: " << endl;
                cin >> name;
                // book_list[0] ��� ����, ��� �� ������� ����� ������� ������
                // ������� ��� ������,     �������� �����,     ������ ���� ����
                book_list[0].get_num_from_name(auth, name, book_list);
                break;

            } else if (temp == 2) { // ���� ������� ������ ��������
                show_all(1);    // ���������� ��� ������� ��� ����, ��� �� ������� ������ ���� ��������
                cout << "������� ������� ���� ����: " << endl;
                int id1, id2; // ������� ���� ��������
                cin >> id1;
                cin >> id2;
                // ������������.�������_������( ������ ������ )
                book_list[id1].one_publisher(book_list[id2]);
                break;
            }

        }

        case 2:{  // ������ ��� ������ ���
            cout << "1. ������� �� ������������ �������� ����" << endl;
            cout << "2. ����������, ����� �� ���� ���� ��������� � ��������������" << endl;
            cin >> temp;
            if (temp == 1){ // ���� ������� 1-� ��������
                int num;
                cout << "������ ����������� �����: ";
                cin >> num;
                kind_list[0].get_kind_from_inv(num, kind_list);

            } else if (temp == 2){  // ���� ������� ������ ��������
                show_all(2);    // ���������� ��� ������� ��� ����, ��� �� ������� ������ ���� ��������
                cout << "������� ������� ���� ����: " << endl;
                int id1, id2; // ������� ���� ��������
                cin >> id1;
                cin >> id2;
                // ��� �� ���� �������� ��������������?
                // ������������.�����_������(������ ������ �� ������ ���� �������� ���)
                kind_list[id1].who_is_fiction(kind_list[id2]);
            }
        }

    }
}


// ������� ����
void menu::main_menu(){
    int choice;     // �������� ��� ������ ������ ������������
    cout << "1. ������� ����� ������ � ����������� �� ���������" << endl;
    cout << "2. ������� ����� ������ � ������ �������" << endl;
    cout << "3. ������������� ������������ ������" << endl;
    cout << "4. ������������ �������������� ��������" << endl;
    cout << "5. ������� ������ ���� �������� ����� �� �����" << endl;
    cout << "6. ��������� ������ ���������" << endl;
    cin >> choice; // ����� ����� ������������

    // ������������ ����� ����. �������� ��� ��� ����� ���� � ���������� �� �� ����, ��� ��� ������������
    switch (choice) // �������� ���������� � ������� ������������
    {
        case 1: { // ���� ������ 1� �����
            create_default();   // ����� ������ ��� �������� ������� ������������ ��� ����������
            break; // break ������������ ��� �� ��������� ���������� ���� ����������� switch case � ������ ��������� �������� � ����� (�� if � �����)
        }
        case 2: { // ���� ������ ������ ������... � ����� �� ��������
            create_user();  // ����� ������ �������� ������� �� ����, ��� ����� ������������
            break;
        }
        case 3: {
            change_obj(); // �������� �����-�� ������ (�������������)
            break;
        }
        case 4: {
            unique_act();   // �������������� �������� ��� ������ (�� ��� ������� � ������� 1 � 2)
            break;
        }
        case 5: {
            show_all( select_class() ); // ������� �� ����� ��� ������� ������-�� ������
            break;
        }
        case 6:{
            key = 1;    // ��� ������ �� ���������
            return;
        }
        default:    // ���� ���� �� ����������, ����� ������� ����
            cout << "������ �����" << endl;
            main_menu();
    }

    if ( key == 0) {    // ���� key ����� ����, �� ��������� ����� ������� ���� � �������� ������
        main_menu();
    } else {            // ��������� ���������, ���� ����������� � ��.
        cout <<  "������ ���������" << endl;
    }
}
