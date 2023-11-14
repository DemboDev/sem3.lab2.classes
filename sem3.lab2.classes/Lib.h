#pragma once
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <string>
#include <vector>
using namespace std;
// ������

class Author {
private:
    string name;
    string date;
    string country;
public:
    static const int Len = 30;
    static const int LenDate = 11;
    Author() {
    }
    Author(string name, string date, string country) {
        if (name.empty() || country.empty()) {
            exit(-1);
        }
        else if (date.length() != LenDate - 1) {
            puts("� ����� ����� ��������");
            exit(-1);
        }
        else {
            if (date[0] < '0' || date[0] > '3' || date[1] < '0' || (date[1] > '1' && date[0] > '2') || date[1] > '9' || date[2] != '.' || date[3] < '0' || date[3] > '1' || date[4] < '0' || (date[4] > '0' && date[3] > '2') || date[4] > '9' || date[5] != '.' || date[6] < '0' || date[6] > '9' || date[7] < '0' || date[7] > '9' || date[8] < '0' || date[8] > '9' || date[9] < '0' || date[9] > '9') {
                puts("� ���� ������ �� �������, ������, ��� ��� �������, � �����");
                exit(-1);
            }
            else {
                SetName(name);
                SetDate(date);
                SetCountry(country);
            }
        }
    }
    ~Author() {
    }
    string GetName() {
        return name;
    }
    string GetDate() {
        return date;
    }
    string GetCountry() {
        return country;
    }
    void SetName(string name) {
        this->name = name;
    }
    void SetDate(string date) {
        this->date = date;
    }
    void SetCountry(string country) {
        this->country = country;
    }
    void PrintAuthor() { // ����� ���������� �� ������
        puts(this->GetName().c_str());
        puts(this->GetCountry().c_str());
        puts(this->GetDate().c_str());
    }
};

class Client {
private:
    string name;
    string date;
    string address;
    static int nClients;
public:
    Client operator++(){
        nClients++;
    }
    static int getCount() {
        return nClients;
    }
    static const int Len = 40;
    static const int LenDate = 11;
    Client() {
        nClients++;
    }
    Client(string name) {
        nClients++;
        this->name = name;
    }
    Client(string name, string date, string address) {
        nClients++;
        if (name.empty() || date.length() != LenDate - 1 || address.empty()) {
            exit(-1);
        }
        else {
            this->name = name;
            this->date = date;
            this->address = address;
        }
    }
    ~Client() {
    }string GetName() {
        return name;
    }
    string GetDate() {
        return date;
    }
    string GetAddress() {
        return address;
    }
    void SetName(string name) {
        this->name = name;
    }
    void SetDate(string date) {
        this->date = date;
    }
    void SetAddress(string address) {
        this->address = address;
    }
};

int Client::nClients = -1;

class Book {
private:
    int year;
    string name;
    static int nBooks;
public:
    Book operator++(){
        nBooks++;
    }
    static int getCount() {
        return nBooks;
    }
    static const int Len = 30;
    static const int LenDate = 11;
    class Author author;
    Book() {
        nBooks++;
    }
    Book(Author author) {
        nBooks++;
    }
    Book(string name, Author author, int year) {
        nBooks++;
        if (name.empty() || year < 1000) {
            exit(-1);
        }
        else {
            this->name = name;
            this->author = author;
            this->year = year;
        }
    }
    ~Book() {
    }
    string GetName() {
        return name;
    }
    int GetYear() {
        return year;
    }
    void SetName(string name) {
        this->name = name;
    }
    void SetYear(int year) {
        year = year;
    }
};

int Book::nBooks = -1;

class Operation {
private:
    string move;
    string date;
    static int nOperations;
public:
    static int getCount() {
        return nOperations;
    }
    static const int Len = 10;
    static const int LenDate = 11;
    Operation() {
        nOperations++;
    }
    Operation(string move, string date, Book book, Client client) {
        nOperations++;
        if (move.empty() || date.length() != LenDate - 1) {
            exit(-1);
        }
        else {
            this->book = book;
            this->client = client;
            this->move = move;
            this->date = date;
        }
    }
    ~Operation() {
    }
    string GetMove() {
        return move;
    }
    string GetDate() {
        return date;
    }
    void SetMove(string move) {
        this->move = move;
    }
    void SetDate(string date) {
        this->date = date;
    }
    Book book;
    Client client;
};

int Operation::nOperations = 0;

class Library {
private:
    string address;
public:
    vector <Book> book;
    vector <Client> readers;
    vector <Operation> operations;
    static const int Len = 40;
    static const int LenDate = 11;
    int NumBooks = 1;
    int NumReaders = 1;
    int NumOperations = 1;
    Library(){}
    Library(Book book, Client client, Operation operation, string address) {
        if (address.empty()) {
            exit(-1);
        }
        else {
            this->address = address;

            this->book.push_back(book);

            this->operations.push_back(operation);

            this->readers.push_back(client);
        }
    }
    ~Library(){}
    int GetNumBooks() {
        return NumBooks;
    }
    int GetNumReaders() {
        return NumReaders;
    }
    string GetAddress() {
        return address;
    }
    void SetAddress(string address) {
        this->address = address;
    }
    void AddBookToLibrary(Book book) {
        this->NumBooks += 1;
        this->book.push_back(book);
    }
    void AddReaderToLibrary(Client reader) {
        this->NumReaders += 1;
        this->readers.push_back(reader);
    }

    void AddOperationToLibrary(Operation operation) {
        this->NumOperations += 1;
        this->operations.push_back(operation);
    }
    void PrintLibrary() {
        printf("\n����������:\n\n����������� ����� (%d): \n", Book::getCount());
        for (int i = 0; i < this->NumBooks; i++) {
            cout << "\"" << this->book.at(i).GetName() << "\", ����� - " << this->book.at(i).author.GetName() << ", ��� ������� - " << this->book.at(i).GetYear() << "\n";
        }
        printf("\n����������� �������� (%d): \n", Client::getCount());
        for (int i = 0; i < this->NumReaders; i++) {
            cout << "���: " << this->readers.at(i).GetName() << ", ���� ��������:" << this->readers.at(i).GetDate() << ", ��������� �� ������ - " << this->readers.at(i).GetAddress() << "\n";
        }
        printf("\n�������� � ���������� (%d): \n", Operation::getCount());
        for (int i = 0; i < this->NumOperations; i++) {
            cout << "����� \"" << this->operations.at(i).book.GetName() << "\", ��������: " << this->operations.at(i).client.GetName() << ", ���� ���������� ��������: " << this->operations.at(i).GetDate() << ", ��� ��������: " << this->operations.at(i).GetMove() << "\n";
        }
        puts("");
    }
    Library operator+(Client& client) {
        this->NumReaders += 1;
        this->readers.push_back(client);
    }
    Library operator+(Book& book) {
        this->NumBooks += 1;
        this->book.push_back(book);
    }
};

// ��������������� �������

char vvod(char min, char max) { // ��������������� �������� �� ������������ �����, ���� ��� ������� ENTER
    char x;
    do {
        x = _getch();
    } while (x < min || x > max);
    return x;
}

void wait() {
    while (getchar() != '\n');
}

// �������� �������
Author AuthorInput() { // ���� ������
    int Len = Author::Len;
    int LenDate = Author::LenDate;
    string name;
    string date;
    string country;
    puts("������� ��� ������");
    cin >> name;
    do {
        do {
            puts("������� ���� �������� ������ � ������� DD.MM.YYYY");
            cin >> date;
        } while (date[0] < '0' || date[0] > '3' || date[1] < '0' || (date[1] > '1' && date[0] > '2') || date[1] > '9' || date[2] != '.' || date[3] < '0' || (date[3] == '1' && date[4] > '2') || date[3] > '1' || date[4] < '0' || (date[4] > '0' && date[3] > '2') || date[4] > '9' || date[5] != '.' || date[6] < '0' || date[6] > '9' || date[7] < '0' || date[7] > '9' || date[8] < '0' || date[8] > '9' || date[9] < '0' || date[9] > '9');
    } while (date.length() != 10);
    puts("������� ������ ������������� ������");
    cin >> country;

    return Author(name, date, country);
}

Client ClientInput() { // ���� ������� (��������)
    int Len = Client::Len;
    int LenDate = Client::LenDate;
    string name;
    string date;
    string address;

    puts("������� ��� ��������");
    cin >> name;
    do {
        do {
            puts("������� ���� �������� �������� � ������� DD.MM.YYYY");
            cin >> date;
        } while (date[0] < '0' || date[0] > '3' || date[1] < '0' || (date[1] > '1' && date[0] > '2') || date[1] > '9' || date[2] != '.' || date[3] < '0' || (date[3] == '1' && date[4] > '2') || date[3] > '1' || date[4] < '0' || (date[4] > '0' && date[3] > '2') || date[4] > '9' || date[5] != '.' || date[6] < '0' || date[6] > '9' || date[7] < '0' || date[7] > '9' || date[8] < '0' || date[8] > '9' || date[9] < '0' || date[9] > '9');
    } while (date.length() != 10);
    puts("������� ����� ���������� ��������");
    cin >> address;

    return Client(name, date, address);
}

Book BookInput(Author author) {
    int Len = Book::Len;
    int LenDate = Book::LenDate;
    int year;
    string name;

    puts("������� �������� �����");
    cin >> name;
    puts("������� ��� ������� �����");
    do {
        scanf("%d", &year);
        if (year < 1000) {
            puts("� ������ ����� ���������");
        }
    } while (year < 1000);
    wait();

    return Book(name, author, year);
}

Operation OperationInput(Book book, Client client) {
    int Len = Operation::Len;
    int LenDate = Operation::LenDate;
    string move;
    string date;

    puts("������� ��� ����������� ��������");
    cin >> move;
    do {
        do {
            puts("������� ���� ���������� �������� � ������� DD.MM.YYYY");
            cin >> date;
        } while (date[0] < '0' || date[0] > '3' || date[1] < '0' || (date[1] > '1' && date[0] > '2') || date[1] > '9' || date[2] != '.' || date[3] < '0' || (date[3] == '1' && date[4] > '2') || date[3] > '1' || date[4] < '0' || (date[4] > '0' && date[3] > '2') || date[4] > '9' || date[5] != '.' || date[6] < '0' || date[6] > '9' || date[7] < '0' || date[7] > '9' || date[8] < '0' || date[8] > '9' || date[9] < '0' || date[9] > '9');
    } while (date.length() != 10);

    return Operation(move, date, book, client);
}

Library LibraryInp(Book book, Client client, Operation operation) {
    int Len = Library::Len;
    int LenDate = Library::LenDate;
    string address;

    puts("������� ����� ����������");
    cin >> address;

    return Library(book, client, operation, address);
}
