
#include "menu.h"
#include <string>
#include <iostream>

// Выбрать класс. Вызывается каждый раз когда нужно выполнить какое либо действие над классом
// Возвращает целое число где:
// 1 - Класс КНИГА    2 - класс ВИД
int menu::select_class(){
    int type;   // Что бы записать выбор польователя и передать его в return
    cout << "Выберете класс" << endl;
    cout << "1. Книга" << endl;
    cout << "2. Вид книги" << endl;
    cin >> type; // Ввод с клавиатуры
    return type;
}

// Метод для создания обьекта без параметров (пункт 1 меню)
void menu::create_default() {
    int type = select_class(); // Спрашиваем для какого класса создадим обьект (см метод выше)
    switch (type) {

        case 1: { // Класс КНИГИ
            cl_book temp;                // Временный обьект, что бы с ним работать
                                         // Конструтор без параметров вызывается из класса cl_book
            book_list.push_back(temp);   // Добавляем обьект в список всех обьектов класса КНИГА
                                         // Список наполняется по мере создания обьектов
                                         // Через него можжно иметь доступ к любому обьекту данного класса

            // После выполнения этого метода, будет удалён один обьект класса КНИГА, тот самый временный обьект
            break;
        }

        case 2: { // Класс ВИД
            cl_kind temp;
            kind_list.push_back(temp); // Стандартный метод для вектора (добавить в конец списка)
            break;
        }

        default: // Если пользователь ввёл не верный номер, то повторим ввод
            cout << "Ошибка ввода" << endl;
            select_class();
    }
    main_menu();
}

// Создать по пользовательскому вводу
void menu::create_user(){
    int type = select_class(); // Выбираем класс, для которого создать обьект
    switch (type) {
        case 1: { // Класс КНИГИ
            int num; // Просто переменная для ввода целых чисел
            cl_book temp;  // Временный обьект
            string name;    // Временная переменная для воода строки

            // Вывод на экран сообщения,            ввод строки         запись занчения строки в временный обькт
            cout << "Введите автора книги: " << endl;      cin >> name;     temp.set_author( name);
            cout << "Введите название книги: " << endl;    cin >> name;     temp.set_name(name);
            cout << "Введите инвентарный номер: " << endl; cin >> num;      temp.set_invent(num);
            cout << "Введите издательсво: " << endl;       cin >> name;     temp.set_pupblisher(name);
            cout << "Введите кол-во старниц: " << endl;    cin >> num;      temp.set_page(num);
            cout << "Введите цену: " << endl;              cin >> num;      temp.set_price(num);

            // Добвить в конец списка элемент
            book_list.push_back(temp); // Добавляем в список обьектов тот обьект, что тольок что редактировали
            break;
        }

        case 2: {  // Класс ВИД
            int num;                        // Всё сделано так же как и для прошлого класса
            cl_kind temp;
            string name;
            cout << "Введите автора книги: " << endl;       cin >> name;    temp.set_author(name);
            cout << "Введите название книги: " << endl;     cin >> name;    temp.set_name(name);
            cout << "Введите инвентарный номер: " << endl;  cin >> num;     temp.set_invent(num);
            cout << "Введите издательсво: " << endl;        cin >> name;    temp.set_pupblisher(name);
            cout << "Введите кол-во старниц: " << endl;     cin >> num;     temp.set_page(num);
            cout << "Введите цену: " << endl;               cin >> num;     temp.set_price(num);
            cout << "Введите вид книги: " << endl;          cin >> name;    temp.set_kind(name);
            cout << "Введите жанр книги: " << endl;         cin >> name;    temp.set_genre(name);

            kind_list.push_back(temp);
            break;
        }

        default: // Если не правильно ввели класс
            cout << "Ошибка ввода" << endl;
            select_class();
    }
}

// Показать все данные всех элементов класса
// На вход принимает номер класса
void menu::show_all(int type){

    switch (type){
        case 1: { // КНИГИ
            // Цикл проходит по индексам всех элементов списка (от 0 и до конца )
                                // метод size возврашает кол-во элементов в массиве
            for (int i = 0; i < book_list.size(); i++){
                cout << "______" << i << "________" << endl; // Индекс элемента

                // Вывод текста,                вывод значения поля с помощью методов get (геттеров)
                cout << "Автор: " <<            book_list[i].get_author() << endl;
                cout << "Название: " <<         book_list[i].get_name() << endl;
                cout << "Инвентарный номер: " <<book_list[i].get_invent() << endl;
                cout << "Издательство: " <<     book_list[i].get_puplisher() << endl;
                cout << "Количество страниц: " << book_list[i].get_page() << endl;
                cout << "Цена: " <<             book_list[i].get_price() << endl;
                cout << "______________" << endl;
            }
            break;
        }

        case 2: { // ВИД
            for (int i = 0; i < kind_list.size(); i++){
                cout << "______" << i << "________" << endl;
                cout << "Автор: " <<             kind_list[i].get_author() << endl;
                cout << "Название: " <<          kind_list[i].get_name() << endl;
                cout << "Инвентарный номер: " << kind_list[i].get_invent() << endl;
                cout << "Издательство: " <<      kind_list[i].get_puplisher() << endl;
                cout << "Количество страниц: " <<kind_list[i].get_page() << endl;
                cout << "Цена: " <<              kind_list[i].get_price() << endl;
                cout << "Вид книги: " <<         kind_list[i].get_kind() << endl;
                cout << "Жанр: " <<              kind_list[i].get_genre() << endl;
                cout << "______________" << endl;
            }
            break;
        }

    }
}


// Метод для редактировния обьекта (поменять значния полей)
void menu::change_obj(){
    int type = select_class(); // Выбрать класс
    int id; // Перменная для индекса элемента
    cout << "Ввведите индекс объекта" << endl;
    switch (type) {
        case 1:{
            show_all(1); // Показывает все обьекты класса КНИГИ
            cin >> id;  // Вводим номер обьекта (смотря на список)
            int num; // Просто переменная для ввода целых чисел
            string name; // Просто переманная для ввода строк

            // Вывод текста,    ввод занчения,    Для обьекта который содержиться в списке book_list под индексом id меняем значение поля
            cout << "Введите автора книги: " << endl;       cin >> name;     book_list[id].set_author(name);
            cout << "Введите название книги: " << endl;     cin >> name;     book_list[id].set_name(name);
            cout << "Введите инвентарный номер: " << endl;  cin >> num;      book_list[id].set_invent(num);
            cout << "Введите издательсво: " << endl;        cin >> name;     book_list[id].set_pupblisher(name);
            cout << "Введите кол-во старниц: " << endl;     cin >> num;      book_list[id].set_page(num);
            cout << "Введите цену: " << endl;               cin >> num;      book_list[id].set_price(num);
            break;
        }

        case 2:{  // Конструтор
            show_all(2); // Показывает все обьекты класса ВИД
            cin >> id; // Индекс элемента
            int num; // Просто переменная для ввода целых чисел
            string name; // Временная пременная для ввода строк

            cout << "Введите автора книги: " << endl;      cin >> name;     kind_list[id].set_author(name);
            cout << "Введите название книги: " << endl;    cin >> name;     kind_list[id].set_name(name);
            cout << "Введите инвентарный номер: " << endl; cin >> num;      kind_list[id].set_invent(num);
            cout << "Введите издательсво: " << endl;       cin >> name;     kind_list[id].set_pupblisher(name);
            cout << "Введите кол-во старниц: " << endl;    cin >> num;      kind_list[id].set_page(num);
            cout << "Введите цену: " << endl;              cin >> num;      kind_list[id].set_price(num);
            cout << "Введите вид книги: " << endl;         cin >> name;     kind_list[id].set_kind(name);
            cout << "Введите жанр книги: " << endl;        cin >> name;     kind_list[id].set_genre(name);
            break;
        }

    }
}


// Выбрать дополнительную операцию (то что указано в заданиях к лабе)
void menu::unique_act(){
    int type = select_class(); // Выбор для какого класса выполнить
    int temp;                   // Перменная для выбора действия
    switch (type) {
        case 1:{ // КНИГА
            // Выбор действия для обьекта КНИГА
            cout << "1. Вернуть инвентарный номер книги по фамилии автора и названию" << endl;
            cout << "2. Определить, изданы ли две книги в одном издательстве" << endl;
            cin >> temp;
            if (temp == 1){ // Если выбрали 1е действие
                string name, auth; // Строковые переменный для Автора и Названию книги
                cout << "Введите фамилию автора: " << endl;
                cin >> auth;
                cout << "Введите название книги: " << endl;
                cin >> name;
                // book_list[0] для того, что бы вызвать метод данного класса
                // Передаём имя автора,     название книги,     Список всех книг
                book_list[0].get_num_from_name(auth, name, book_list);
                break;

            } else if (temp == 2) { // Если выбрали второе действие
                show_all(1);    // Показываем все обьекты для того, что бы выбрать индекс двух обьектов
                cout << "Введите индексы двух книг: " << endl;
                int id1, id2; // Индексы двух обьектов
                cin >> id1;
                cin >> id2;
                // ПервыйОбьект.вызовов_метода( Второй обьект )
                book_list[id1].one_publisher(book_list[id2]);
                break;
            }

        }

        case 2:{  // Методы для класса ВИД
            cout << "1. Вернуть по инвентарному название вида" << endl;
            cout << "2. Определить, какая из двух книг относится к художественным" << endl;
            cin >> temp;
            if (temp == 1){ // Если выбрали 1-е действие
                int num;
                cout << "Ведите инвентарный номер: ";
                cin >> num;
                kind_list[0].get_kind_from_inv(num, kind_list);

            } else if (temp == 2){  // Если ывбрали второе действие
                show_all(2);    // Показываем все обьекты для того, что бы выбрать индекс двух обьектов
                cout << "Введите индексы двух книг: " << endl;
                int id1, id2; // Индексы двух обьектов
                cin >> id1;
                cin >> id2;
                // Кто из двух обьектов художественный?
                // первыйОбьект.вызов_метода(второй обьект из списка всех обьектов ВИД)
                kind_list[id1].who_is_fiction(kind_list[id2]);
            }
        }

    }
}


// Главное меню
void menu::main_menu(){
    int choice;     // перменна для записи выбора пользователя
    cout << "1. Создать новый обьект с параметрами по умолчанию" << endl;
    cout << "2. Создать новый обьект с своими данными" << endl;
    cout << "3. Редактировать существующий обьект" << endl;
    cout << "4. Использовать дополнительную операцию" << endl;
    cout << "5. Вывести список всех обьектов класа на экран" << endl;
    cout << "6. Завершить работу программы" << endl;
    cin >> choice; // Ввели выбор пользователя

    // Конструкуция Свитч Кейс. Выбирает тот или инной кейс в зависимоти от от того, что ввёл польщователь
    switch (choice) // Передали переменную с выбором пользователя
    {
        case 1: { // Если выбрал 1й пункт
            create_default();   // Вызов метода для создания обьекта конструтором мез параметров
            break; // break используется что бы завершить выполнение всей конструкции switch case и дальше выполнить условние в конце (см if в конце)
        }
        case 2: { // Если выбрал второй пункут... а далле по аналогии
            create_user();  // Вызов метода создания обьекта по тому, что введёт пользователь
            break;
        }
        case 3: {
            change_obj(); // Изменить какой-то обьект (редактировать)
            break;
        }
        case 4: {
            unique_act();   // Дополнительные операции для класса (то что описано в задании 1 и 2)
            break;
        }
        case 5: {
            show_all( select_class() ); // Вывести на экран все обьекты какого-то класса
            break;
        }
        case 6:{
            key = 1;    // Для выхода из программы
            return;
        }
        default:    // Если ввод не коорректен, снова вызваем меню
            cout << "Ошибка ввода" << endl;
            main_menu();
    }

    if ( key == 0) {    // Если key равен нулю, то программа снова вызвает меню и работает дальше
        main_menu();
    } else {            // Завершаем програаму, меню закрывается и всё.
        cout <<  "Работа завершена" << endl;
    }
}
