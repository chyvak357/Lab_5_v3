#include "cl_book.h"
#include <string>
#include <vector>

#ifndef LAB1_V5_KIND_H
#define LAB1_V5_KIND_H


class cl_kind : public cl_book {
private:
    string kind_name;   // Вид книги
    string genre;       // Жанр книги

public:

    // Конструктор без параметров
    cl_kind() : cl_book() {
        genre = "Unnamed";
        kind_name = "Unnamed";
    }

    // Конструктор с парамтрами
    // Автор    Имя    Инверт номер     Изд-во     страниц     цена,    вид,    жанр
    cl_kind(string a, string nam, int n, string pubg, int num, int p, string k, string g )
            : cl_book(a, nam, n, pubg, num, p) // Эта часть Вызваеся из констуртора класса book
    {
        kind_name = k;
        genre = g;
    }

    ~cl_kind(){ // деструктор
        cout << "Обьект вида книги удалён" << endl << endl;
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


    // Вернуть по инвентарному название вида
    // Принимает инв номер и по ссылке список всех книг
    void get_kind_from_inv(int inv, vector<cl_kind> &lib);

    // Кто из двух книг ХУДОЖЕСТВЕННАЯ (должно быть написано в поле KIND)
    void who_is_fiction(cl_kind & ob2);

};


#endif //LAB1_V5_KIND_H

/*Класс – Вид книги
 * Поля:
 *       Название вида
 *       жанр художественной книги
 *
 * Дополнительные операции
 *          3) Вернуть по инвентарному название вида.
 *          4) Определить, какая из двух книг относится к художественным.
 *
 */