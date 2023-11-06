#pragma once
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

// ������

class Author {
private:
    char* name;
    char* date;
    char* country;
public:
    static const int Len = 30;
    static const int LenDate = 11;
    Author() {
        char* name = (char*)calloc(Len, sizeof(char));
        strcpy(name, "���� �������� ������\0");
        char* date = (char*)calloc(LenDate, sizeof(char));
        strcpy(date, "11.11.1911");
        char* country = (char*)calloc(Len, sizeof(char));
        strcpy(country, "������\0");
    }
    Author(char* name, char* date, char* country) {
        if (strlen(name) == 0 || strlen(country) == 0) {
            exit(-1);
        }
        else if (strlen(date) != LenDate - 1) {
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
    char* GetName() {
        return name;
    }
    char* GetDate() {
        return date;
    }
    char* GetCountry() {
        return country;
    }
    void SetName(char* name) {
        this->name = name;
    }
    void SetDate(char* date) {
        this->date = date;
    }
    void SetCountry(char* country) {
        this->country = country;
    }
    void PrintAuthor() { // ����� ���������� �� ������
        puts(this->GetName());
        puts(this->GetCountry());
        puts(this->GetDate());
    }
};

class Client {
private:
    char* name;
    char* date;
    char* address;
public:
    static const int Len = 40;
    static const int LenDate = 11;
    Client() {
    }
    Client(char* name) {
        this->name = name;
        strcpy(this->date, "11.11.1911\0");
        strcpy(this->address, "������\0");
    }
    Client(char* name, char* date, char* address) {
        if (strlen(name) == 0 || strlen(date) != LenDate - 1 || strlen(address) == 0) {
            exit(-1);
        }
        else {
            this->name = name;
            this->date = date;
            this->address = address;
        }
    }
    ~Client() {
    }char* GetName() {
        return name;
    }
    char* GetDate() {
        return date;
    }
    char* GetAddress() {
        return address;
    }
    void SetName(char* name) {
        this->name = name;
    }
    void SetDate(char* date) {
        this->date = date;
    }
    void SetAddress(char* address) {
        this->address = address;
    }
};

class Book {
private:
    int year;
    char* name;
public:
    static const int Len = 30;
    static const int LenDate = 11;
    class Author author;
    Book() {
    }
    Book(Author author) {
        strcpy(this->name, "����� �������");
        this->year = 2000;
        this->author = author;
    }
    Book(char* name, Author author, int year) {
        if (strlen(name) == 0 || year < 1000) {
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
    char* GetName() {
        return name;
    }
    int GetYear() {
        return year;
    }
    void SetName(char* name) {
        this->name = name;
    }
    void SetYear(int year) {
        year = year;
    }
    void PrintBook() {
        puts(this->GetName());
        printf("%d\n", this->GetYear());
        puts(this->author.GetCountry());
        puts(this->author.GetName());
        puts(this->author.GetDate());
    }
};

class Operation {
private:
    char* move;
    char* date;
public:
    static const int Len = 10;
    static const int LenDate = 11;
    Operation() {
    }
    Operation(char* move, char* date, Book book, Client client) {
        if (strlen(move) == 0 || strlen(date) != LenDate - 1) {
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
    char* GetMove() {
        return move;
    }
    char* GetDate() {
        return date;
    }
    void SetMove(char* move) {
        this->move = move;
    }
    void SetDate(char* date) {
        this->date = date;
    }
    class Book book;
    class Client client;
};

class Library {
private:
    char* address;
public:
    static const int Len = 40;
    static const int LenDate = 11;
    int NumBooks = 1;
    int NumReaders = 1;
    int NumOperations = 1;
    Library(){}
    Library(Book book, Client client, Operation operation, char* address) {
        if (strlen(address) == 0) {
            exit(-1);
        }
        else {
            this->address = address;

            this->book = (Book*)malloc(sizeof(Book));
            this->book[this->NumBooks - 1] = book;

            this->operations = (Operation*)malloc(sizeof(Operation));
            this->operations[this->NumOperations - 1] = operation;

            this->readers = (Client*)malloc(sizeof(Client));
            this->readers[this->NumReaders - 1] = client;
        }
    }
    ~Library(){}
    class Book* book;
    class Client* readers;
    class Operation* operations;
    char* GetAddress() {
        return address;
    }
    void SetAddress(char* address) {
        this->address = address;
    }
    void AddBookToLibrary(Book book) {
        this->NumBooks += 1;
        this->book = (Book*)realloc(this->book, sizeof(Book) * this->NumBooks);
        this->book[this->NumBooks - 1] = book;
    }
    void AddReaderToLibrary(Client reader) {
        this->NumReaders += 1;
        this->readers = (Client*)realloc(this->readers, sizeof(Client) * this->NumReaders);
        this->readers[this->NumReaders - 1] = reader;
    }

    void AddOperationToLibrary(Operation operation) {
        this->NumOperations += 1;
        this->operations = (Operation*)realloc(this->operations, sizeof(Operation) * this->NumOperations);
        this->operations[this->NumOperations - 1] = operation;
    }
    void PrintLibrary() {
        puts("\n����������:\n\n����������� ����� : ");
        for (int i = 0; i < this->NumBooks; i++) {
            printf("\"%s\", ����� - %s, ��� ������� - %d\n", this->book[i].GetName(), this->book[i].author.GetName(), this->book[i].GetYear());
        }
        puts("\n����������� �������� : ");
        for (int i = 0; i < this->NumReaders; i++) {
            printf("���: %s, ���� ��������: %s, ��������� �� ������ - %s\n", this->readers[i].GetName(), this->readers[i].GetDate(), this->readers[i].GetAddress());
        }
        puts("\n�������� � ���������� : ");
        for (int i = 0; i < this->NumOperations; i++) {
            printf("����� \"%s\", ��������: %s, ���� ���������� ��������: %s, ��� ��������: %s\n", this->operations[i].book.GetName(), this->operations[i].client.GetName(), this->operations[i].GetDate(), this->operations[i].GetMove());
        }
        puts("");
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
    char* name = (char*)calloc(Len, sizeof(char));
    char* date = (char*)calloc(LenDate + 1, sizeof(char));
    char* country = (char*)calloc(Len, sizeof(char));

    puts("������� ��� ������");
    gets_s(name, Len);
    do {
        do {
            puts("������� ���� �������� ������ � ������� DD.MM.YYYY");
            gets_s(date, LenDate);
        } while (date[0] < '0' || date[0] > '3' || date[1] < '0' || (date[1] > '1' && date[0] > '2') || date[1] > '9' || date[2] != '.' || date[3] < '0' || (date[3] == '1' && date[4] > '2') || date[3] > '1' || date[4] < '0' || (date[4] > '0' && date[3] > '2') || date[4] > '9' || date[5] != '.' || date[6] < '0' || date[6] > '9' || date[7] < '0' || date[7] > '9' || date[8] < '0' || date[8] > '9' || date[9] < '0' || date[9] > '9');
    } while (strlen(date) != 10);
    puts("������� ������ ������������� ������");
    gets_s(country, Len);

    return Author(name, date, country);
}

Client ClientInput() { // ���� ������� (��������)
    int Len = Client::Len;
    int LenDate = Client::LenDate;
    char* name = (char*)calloc(Len, sizeof(char));
    char* date = (char*)calloc(LenDate + 1, sizeof(char));
    char* address = (char*)calloc(Len, sizeof(char));

    puts("������� ��� ��������");
    gets_s(name, Len);
    do {
        do {
            puts("������� ���� �������� �������� � ������� DD.MM.YYYY");
            gets_s(date, LenDate);
        } while (date[0] < '0' || date[0] > '3' || date[1] < '0' || (date[1] > '1' && date[0] > '2') || date[1] > '9' || date[2] != '.' || date[3] < '0' || (date[3] == '1' && date[4] > '2') || date[3] > '1' || date[4] < '0' || (date[4] > '0' && date[3] > '2') || date[4] > '9' || date[5] != '.' || date[6] < '0' || date[6] > '9' || date[7] < '0' || date[7] > '9' || date[8] < '0' || date[8] > '9' || date[9] < '0' || date[9] > '9');
    } while (strlen(date) != 10);
    puts("������� ����� ���������� ��������");
    gets_s(address, Len);

    return Client(name, date, address);
}

Book BookInput(Author author) {
    int Len = Book::Len;
    int LenDate = Book::LenDate;
    int year;
    char* name = (char*)calloc(Len, sizeof(char));

    puts("������� �������� �����");
    gets_s(name, Len);
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
    char* move = (char*)calloc(Len, sizeof(char));
    char* date = (char*)calloc(LenDate + 1, sizeof(char));

    puts("������� ��� ����������� ��������");
    gets_s(move, Len);
    puts("������� ���� ���������� ��������");
    gets_s(date, LenDate);

    return Operation(move, date, book, client);
}

Library LibraryInp(Book book, Client client, Operation operation) {
    int Len = Library::Len;
    int LenDate = Library::LenDate;
    char* address = (char*)calloc(Len, sizeof(char));

    puts("������� ����� ����������");
    gets_s(address, Len);

    return Library(book, client, operation, address);
}
