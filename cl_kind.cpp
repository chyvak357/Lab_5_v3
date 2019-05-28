
#include "cl_kind.h"

// ������� �� ������������ �������� ����
// �� ���� ���������           ������-�����,    ������ ���� �������� ���� �� ������ (��� �� �� ����������� �����)
void cl_kind::get_kind_from_inv(int inv, vector<cl_kind> &lib){
    bool key = false; // ���� ��� �� ��� ��� ����� �� ����� �����, ������� ���������
    for (int i = 0; i < lib.size(); i++){   // ������� ���� ��������� ������
        if (lib[i].get_invent() == inv){ // ���������� ���-� ����� ������� � ��������
            cout << "������������������ �����: " << lib[i].get_invent() << endl; // ������� �����, ��� � ���� �����
            cout << "���: " << lib[i].get_name() << endl;
            cout << "����: " << lib[i].get_genre() << endl;
            key = true;
        }
    }
    if (key == false){      // ���� �� ������� �� ����� ����� � ������ � ������� �������
        cout << "����� �� ������" << endl;
    }
}


// ����� ����� ��������������?
// this - ������ ����� (��������� �� ������ ������ �����)
void cl_kind :: who_is_fiction(cl_kind & ob2){

    // ���� � ����� ���� � ���� genre (����) ����� "��������������" �� ������� ���������
    if (this->get_kind() == "��������������" && ob2.get_kind() == "��������������"  ){
        cout << "����� " << this->get_name() << " � " << ob2.get_name() << " ��� ��������������" << endl;

        // ���� ������ ��������������
    } else if ( this->get_kind() != "��������������" && ob2.get_kind() == "��������������" ){
        cout << "����� " << ob2.get_name() << " ��������������" << endl;

        // ���� ������ ��������������
    } else if (this->get_kind() == "��������������" && ob2.get_kind() != "��������������" ){
        cout << "����� " << this->get_name() << " ��������������" << endl;

        // ���� ��� ����� �� ��������������
    } else {
        cout << "����� " << this->get_name() << " � " << ob2.get_name() << " ��� �� ��������������" << endl;
    }
}
