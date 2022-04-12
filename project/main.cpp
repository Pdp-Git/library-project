#include <iostream>
#include "vector"

using namespace std;

struct Book {
    string name;
    string author;
    int madeYear;
    int pages;
};

struct Bookshelf {
    string name;
    vector<Book> books;
};

Bookshelf createBookshelf() {
    Bookshelf bookshelf;
    cout << "Bo'lim nomini kiriting\n";
    cin.ignore();
    getline(cin, bookshelf.name);
    return bookshelf;
}


Book createBook() {
    Book book;
    cout << "kittob nomini kiriting\n";
    cin.ignore();
    getline(cin, book.name);
    cout << "kitob avtorini kiriting\n";
    cin >> book.author;
    cout << "kitob yilini kiriting\n";
    cin >> book.madeYear;
    cout << "kitob sahifalar sonini kiriting\n";
    cin >> book.pages;
    return book;
}

void printBook(vector<Book> books) {
    for (int i = 0; i < books.size(); ++i) {
        cout << i + 1 << ") book\n";
        cout << books.at(i).name << endl;
        cout << books.at(i).author << endl;
        cout << books.at(i).madeYear << endl;
        cout << books.at(i).pages << endl;
        cout << endl;
    }
}

void printBookshelf(vector<Bookshelf> bookshelf) {
    for (int i = 0; i < bookshelf.size(); ++i) {
        cout << i + 1 << ") " << bookshelf.at(i).name << endl;
    }
    cout << endl;

}

int main() {
    cout << "Welcome to library" << endl;
    int option = 0, bookshelfId = 0, bookId = 0;
    vector<Bookshelf> bolimlar;
    vector<Book> booklist;
    vector<string> log;
    while (true) {
        cout << "0 exit\n"
                "1 bo'limlar ro'yxati\n"
                "2 bo'lim qo'shish\n"
                "3 bo'limni o'zgartirish\n"
                "4 bo'limni o'chirish\n"
                "5 kitoblar ro'yxati\n"
                "6 kitob qo'shish\n"
                "7 kitobni o'zgartirish\n"
                "8 kitobni o'chirish\n"
                "9 amaliyotlar tarixi\n";
        cin.ignore();
        cin >> option;//2
        switch (option) {
            case 0:
                cout << "Good bye\n";
                return 0;
            case 1:
                printBookshelf(bolimlar);
                break;
            case 2:
                bolimlar.push_back(createBookshelf());
                break;
            case 3:
                printBookshelf(bolimlar);
                cout << "O'zgartirmoqchi bo'lgan bo'limingizni tanlang\n";
                cin.ignore();
                cin >> bookshelfId;
                if (bookshelfId > 0 && bookshelfId <= bolimlar.size()) {
                    cout << "Bo'limning yangi nomini kiriting\n";
                    cin.ignore();
                    getline(cin, bolimlar.at(bookshelfId - 1).name);
                } else {
                    cout << "Bunday bo'lim mavjud emas!\n";
                }
                break;
            case 4:
                printBookshelf(bolimlar);
                cout << "O'chirmoqchi bo'lgan bo'limingizni tanlang\n";
                cin.ignore();
                cin >> bookshelfId;
                if (bookshelfId > 0 && bookshelfId <= bolimlar.size()) {
                    bolimlar.erase(bolimlar.begin() + (bookshelfId - 1));
                } else {
                    cout << "Bunday bo'lim mavjud emas!\n";
                }
                break;
            case 5:
                printBookshelf(bolimlar);
                cout << "Qaysi bo'lim kitoblarini ko'rmoqchisiz\n";
                cin >> bookshelfId;
                printBook(bolimlar.at(bookshelfId - 1).books);

                break;
            case 6:
                printBookshelf(bolimlar);
                cout << "Bo'limni tanlang\n";
                cin >> bookshelfId;
                bolimlar.at(bookshelfId - 1).books.push_back(createBook());
                log.push_back(bolimlar.at(bookshelfId - 1).name + " bo'limga " + bolimlar.at(bookshelfId - 1).books.at(
                        bolimlar.at(bookshelfId - 1).books.size() - 1).name + " kitob qo'shildi");

                break;
            case 7:
                printBookshelf(bolimlar);
                cout << "Bo'limni tanlang\n";
                cin >> bookshelfId;
                printBook(bolimlar.at(bookshelfId - 1).books);
                cout << "Kitobni tanlang\n";
                cin >> bookId;
                bolimlar.at(bookshelfId - 1).books.at(bookId - 1) = createBook();
                break;
            case 8:
                printBookshelf(bolimlar);
                cout << "Bo'limni tanlang\n";
                cin >> bookshelfId;
                printBook(bolimlar.at(bookshelfId - 1).books);
                cout << "Kitobni tanlang\n";
                cin >> bookId;
                log.push_back(bolimlar.at(bookshelfId - 1).name + " bo'limdan " +
                              bolimlar.at(bookshelfId - 1).books.at(bookId - 1).name + " kitob o'chirildi");
                bolimlar.at(bookshelfId - 1).books.erase((bolimlar.at(bookshelfId - 1).books.begin()) + (bookId - 1));
                break;
            case 9:
                for (string temp: log) {
                    cout << temp << endl;
                }
                break;
        }

    }
    return 0;
}


