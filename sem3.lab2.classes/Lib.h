#pragma once
#define Len 30
#define LenDate 11
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

// Классы

class Author {
private:
    char* name;
    char* date;
    char* country;
public:
    Author() {
        char* name = (char*)calloc(Len, sizeof(char));
        strcpy(name, "Иван Иванович Иванов\0");
        char* date = (char*)calloc(LenDate, sizeof(char));
        strcpy(date, "11.11.1911");
        char* country = (char*)calloc(Len, sizeof(char));
        strcpy(country, "Россия\0");
    }
    Author(char* name, char* date, char* country) {
        if (strlen(name) == 0 || strlen(country) == 0) {
            exit(-1);
        }
        else if (strlen(date) != LenDate - 1) {
            puts("Я тупой прост немножко");
            exit(-1);
        }
        else {
            if (date[0] < '0' || date[0] > '3' || date[1] < '0' || (date[1] > '1' && date[0] > '2') || date[1] > '9' || date[2] != '.' || date[3] < '0' || date[3] > '1' || date[4] < '0' || (date[4] > '0' && date[3] > '2') || date[4] > '9' || date[5] != '.' || date[6] < '0' || date[6] > '9' || date[7] < '0' || date[7] > '9' || date[8] < '0' || date[8] > '9' || date[9] < '0' || date[9] > '9') {
                puts("У тебя ошибка во времени, братан, так что извиняй, я пошёл");
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
};

class Client {
private:
    char* name;
    char* date;
    char* address;
public:
    Client() {
    }
    Client(char* name) {
        this->name = name;
        strcpy(this->date, "11.11.1911\0");
        strcpy(this->address, "Россия\0");
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
    class Author author;
    Book() {
    }
    Book(Author author) {
        strcpy(this->name, "Захар Беляков");
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
        this->year = year;
    }
};

class Operation {
private:
    char* move;
    char* date;
public:
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
    void SetName(char* date) {
        this->date = date;
    }
    class Book book;
    class Client client;
};

class Library {
private:
    char* address;
public:
    int NumBooks = 1;
    int NumReaders = 1;
    int NumOperations = 1;
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
};

// Вспомогательные функции

char vvod(char min, char max) { // автоматизировал проверку на допустимость ввода, ввод без нажатия ENTER
    char x;
    do {
        x = _getch();
    } while (x < min || x > max);
    return x;
}

void wait() {
    while (getchar() != '\n');
}

// Основные функции

Author AuthorInput() { // ввод автора
    char* name = (char*)calloc(Len, sizeof(char));
    char* date = (char*)calloc(LenDate + 1, sizeof(char));
    char* country = (char*)calloc(Len, sizeof(char));

    puts("Введите имя автора");
    gets_s(name, Len);
    do {
        do {
            puts("Введите дату рождения автора в формате DD.MM.YYYY");
            gets_s(date, LenDate);
        } while (date[0] < '0' || date[0] > '3' || date[1] < '0' || (date[1] > '1' && date[0] > '2') || date[1] > '9' || date[2] != '.' || date[3] < '0' || (date[3] == '1' && date[4] > '2') || date[3] > '1' || date[4] < '0' || (date[4] > '0' && date[3] > '2') || date[4] > '9' || date[5] != '.' || date[6] < '0' || date[6] > '9' || date[7] < '0' || date[7] > '9' || date[8] < '0' || date[8] > '9' || date[9] < '0' || date[9] > '9');
    } while (strlen(date) != 10);
    puts("Введите страну происхождения автора");
    gets_s(country, Len);

    return Author(name, date, country);
}

Client ClientInput() { // ввод клиента (читателя)
    char* name = (char*)calloc(Len, sizeof(char));
    char* date = (char*)calloc(LenDate + 1, sizeof(char));
    char* address = (char*)calloc(Len, sizeof(char));

    puts("Введите имя читателя");
    gets_s(name, Len);
    do {
        do {
            puts("Введите дату рождения читателя в формате DD.MM.YYYY");
            gets_s(date, LenDate);
        } while (date[0] < '0' || date[0] > '3' || date[1] < '0' || (date[1] > '1' && date[0] > '2') || date[1] > '9' || date[2] != '.' || date[3] < '0' || (date[3] == '1' && date[4] > '2') || date[3] > '1' || date[4] < '0' || (date[4] > '0' && date[3] > '2') || date[4] > '9' || date[5] != '.' || date[6] < '0' || date[6] > '9' || date[7] < '0' || date[7] > '9' || date[8] < '0' || date[8] > '9' || date[9] < '0' || date[9] > '9');
    } while (strlen(date) != 10);
    puts("Введите адрес проживания читателя");
    gets_s(address, Len);

    return Client(name, date, address);
}

Book BookInput(Author author) {
    int year;
    char* name = (char*)calloc(Len, sizeof(char));

    puts("Введите название книги");
    gets_s(name, Len);
    puts("Введите год издания книги");
    do {
        scanf("%d", &year);
        if (year < 1000) {
            puts("А теперь введи нормально");
        }
    } while (year < 1000);
    wait();

    return Book(name, author, year);
}

Operation OperationInput(Book book, Client client) {
    char* move = (char*)calloc(Len, sizeof(char));
    char* date = (char*)calloc(LenDate + 1, sizeof(char));

    puts("Введите тип совершённой операции");
    gets_s(move, Len);
    puts("Введите дату совершения операции");
    gets_s(date, LenDate);

    return Operation(move, date, book, client);
}

Library LibraryInp(Book book, Client client, Operation operation) {
    char* address = (char*)calloc(Len, sizeof(char));

    puts("Введите адрес библиотеки");
    gets_s(address, Len);

    return Library(book, client, operation, address);
}

// Дополнительные функции

void PrintAuthor(Author author) { // вывод информации об авторе
    puts(author.GetName());
    puts(author.GetCountry());
    puts(author.GetDate());
}

void PrintBook(Book book) {
    puts(book.GetName());
    printf("%d\n", book.GetYear());
    puts(book.author.GetCountry());
    puts(book.author.GetName());
    puts(book.author.GetDate());
}

void PrintLibrary(Library library) {
    puts("\nБиблиотека:\n\nПривязанные книги : ");
    for (int i = 0; i < library.NumBooks; i++) {
        printf("\"%s\", автор - %s, год издания - %d\n", library.book[i].GetName(), library.book[i].author.GetName(), library.book[i].GetYear());
    }
    puts("\nПривязанные читатели : ");
    for (int i = 0; i < library.NumReaders; i++) {
        printf("Имя: %s, дата рождения: %s, проживает по адресу - %s\n", library.readers[i].GetName(), library.readers[i].GetDate(), library.readers[i].GetAddress());
    }
    puts("\nОперации в библиотеке : ");
    for (int i = 0; i < library.NumOperations; i++) {
        printf("Книга \"%s\", читатель: %s, Дата совершения операции: %s, Тип операции: %s\n", library.operations[i].book.GetName(), library.operations[i].client.GetName(), library.operations[i].GetDate(), library.operations[i].GetMove());
    }
    puts("");
}

Library AddBookToLibrary(Library library, Book book) {
    library.NumBooks += 1;
    library.book = (Book*)realloc(library.book, sizeof(Book) * library.NumBooks);
    library.book[library.NumBooks - 1] = book;
    return library;
}

Library AddReaderToLibrary(Library library, Client reader) {
    library.NumReaders += 1;
    library.readers = (Client*)realloc(library.readers, sizeof(Client) * library.NumReaders);
    library.readers[library.NumReaders - 1] = reader;
    return library;
}

Library AddOperationToLibrary(Library library, Operation operation) {
    library.NumOperations += 1;
    library.operations = (Operation*)realloc(library.operations, sizeof(Operation) * library.NumOperations);
    library.operations[library.NumOperations - 1] = operation;
    return library;
}