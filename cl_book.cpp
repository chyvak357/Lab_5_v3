#include <vector>
#include <iostream>
#include "cl_book.h"

using namespace std;


//  Вернуть инвентарный номер книги по фамилии автора и названию
                            //  Автор, навзание, список всех книг
void cl_book::get_num_from_name(string auth, string name, vector<cl_book> &lib) {
    bool key = false; // Ключ что бы есл ине нашли ни одной книги, вывести сообщение
    for (int i = 0; i < lib.size(); i++){ // Перебор всех элементов списка
        if (lib[i].get_name() == name && lib[i].get_author() == auth){ // Сравниваем название и автора книги с введённм (должны совпасть оба)
            cout << "Автор: " << lib[i].get_author() << endl;       // Выводм Имя автора, имя книги, номер книги
            cout << "Название: " << lib[i].get_name() << endl;
            cout << "Инвентаризационный номер: " << lib[i].get_invent() << endl;
            key = true;
        }
    }
    if (key == false){ // Если не нашлось ни одной книги в списке с нужноым номером
        cout << "Книга не найдена" << endl;
    }
}


// Сравнивает, одинакового ли издательсва книги
// В качестве this подразумевается первый обьект, а второй передаётся в параметрах функции по ссылке
void cl_book::one_publisher(cl_book &ob_2){
    // Пишем this -> потому что this это УКАЗАТЕЛЬ на текущий обьект к которому вызвали метод
    // Если возрастные границы точно совпали, то выводим сообщение
    if (this->get_puplisher() == ob_2.get_puplisher()){
        cout << "Книги " << this -> get_name() << " и " <<  ob_2.get_name() << " от одинаковых издательств" << endl;
    } else {
        cout << "Книги " << this -> get_name() << " и " <<  ob_2.get_name() << " от разных издательств" << endl;
    }
}

