#ifndef LAB1_V5_CL_BOOK_H
#define LAB1_V5_CL_BOOK_H

#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

class cl_book {
private:

    string author;      // Автор
    string name;      // Название
    int invent;       // Инвентарный номер
    string pub;     // Издательсво
    int page;       //Количество страниц
    int price;       // Цена

public:
    cl_book(){ // Конструктор без параметров
        author = "Unnamed";
        name = "Unnamed";
        invent = 0;
        pub = "Unnamed";
        page = 0;
        price = 0;
    }

        // Автор    Имя    Инверт номер     Изд-во     страниц     цена
    cl_book(string a, string nam, int n, string pubg, int num, int p ){ // Конструктор с парамтрами
        author = a;
        name = nam;
        invent = n;
        pub = pubg;
        page = num;
        price = p;
    }

    virtual ~cl_book(){ // деструктор
        cout << "Обьект Книга удалён" <<  endl << endl;
    }

    void set_price(int p) { // Задать цену
        price = p;
    }

    void set_author(string a){ // Задать фирму
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

    int get_price(){    // Получить цену книги
        return price;
    }

    // По назвинию книги и фамилии автора вернуть инвент номер книги
    void get_num_from_name(string auth, string name, vector<cl_book> &lib);

    // Вирутальная потому что такой же метод переопределяется в другом классе
    virtual void one_publisher(cl_book &ob_2);

};
#endif //LAB1_V5_CL_BOOK_H

/*Класс Книга Поля:
 * Автор
 * Название
 * Инвентарный номер
 * Издательство
 * Количество страниц
 * Цена
 *
 * Дополнительные операции:
 *          1) Вернуть инвентарный номер книги по фамилии автора и названию.
 *          2) Определить, изданы ли две книги в одном издательстве.
 */

/*Класс – Вид книги Поля:
 * Название вида
 * жанр художественной книги
 *
 * Дополнительные операции
 *          3) Вернуть по инвентарному название вида.
 *          4) Определить, какая из двух книг относится к художественным.
 *
 */