#pragma once
#define Len 30
#define LenDate 11
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

// ������

class Author {
public:
    char* name;
    char* date;
    char* country;
};

class Client {
public:
    char* name;
    char* date;
    char* address;
};

class Book {
public:
    char* name;
    struct Author author;
    int year;
};

class Operation {
public:
    char* move;
    char* date;
    struct Book book;
    struct Client client;
};

class Library {
public:
    int NumBooks = 1;
    int NumReaders = 1;
    int NumOperations = 1;
    struct Book* book;
    struct Client* readers;
    struct Operation* operations;
    char* address;
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

Author AuthorInit(char* name, char* date, char* country) { // ������������� ������
    Author buf;
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
            buf.name = name;
            buf.date = date;
            buf.country = country;
        }
    }
    return buf;
}

Author AuthorInput() { // ���� ������
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

    Author buffer = AuthorInit(name, date, country);
    return buffer;
}

Client ClientInit(char* name, char* date, char* address) {
    Client buf;

    if (strlen(name) == 0 || strlen(date) != LenDate - 1 || strlen(address) == 0) {
        exit(-1);
    }
    else {
        buf.name = name;
        buf.date = date;
        buf.address = address;
    }
    return buf;
}

Client ClientInput() { // ���� ������� (��������)
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

    Client buf = ClientInit(name, date, address);
    return buf;
}

Book BookInit(char* name, Author author, int year) {
    Book buf;

    if (strlen(name) == 0 || year < 1000) {
        exit(-1);
    }
    else {
        buf.name = name;
        buf.author = author;
        buf.year = year;
    }
    return buf;
}

Book BookInput(Author author) {
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

    Book buf = BookInit(name, author, year);
    return buf;
}

Operation OperationInit(char* move, char* date, Book book, Client client) {
    Operation buf;

    if (strlen(move) == 0 || strlen(date) != LenDate - 1) {
        exit(-1);
    }
    else {
        buf.book = book;
        buf.client = client;
        buf.move = move;
        buf.date = date;
    }

    return buf;
}

Operation OperationInput(Book book, Client client) {
    char* move = (char*)calloc(Len, sizeof(char));
    char* date = (char*)calloc(LenDate + 1, sizeof(char));

    puts("������� ��� ����������� ��������");
    gets_s(move, Len);
    puts("������� ���� ���������� ��������");
    gets_s(date, LenDate);

    Operation buf = OperationInit(move, date, book, client);
    return buf;
}

Library LibraryInit(Book book, Client client, Operation operation, char* address) {
    if (strlen(address) == 0) {
        exit(-1);
    }
    else {
        Library buf;
        buf.address = address;

        buf.book = (Book*)malloc(sizeof(Book));
        buf.book[buf.NumBooks - 1] = book;

        buf.operations = (Operation*)malloc(sizeof(Operation));
        buf.operations[buf.NumOperations - 1] = operation;

        buf.readers = (Client*)malloc(sizeof(Client));
        buf.readers[buf.NumReaders - 1] = client;

        return buf;
    }
}

Library LibraryInp(Book book, Client client, Operation operation) {
    char* address = (char*)calloc(Len, sizeof(char));

    puts("������� ����� ����������");
    gets_s(address, Len);

    Library buf = LibraryInit(book, client, operation, address);
    return buf;
}

// �������������� �������

void PrintAuthor(Author author) { // ����� ��������� �� ������
    puts(author.name);
    puts(author.date);
    puts(author.country);
}

void PrintBook(Book book) {
    puts(book.name);
    printf("%d\n", book.year);
    puts(book.author.country);
    puts(book.author.name);
    puts(book.author.date);
}

void PrintLibrary(Library library) {
    puts("\n����������:\n\n����������� ����� : ");
    for (int i = 0; i < library.NumBooks; i++) {
        printf("\"%s\", ����� - %s, ��� ������� - %d\n", library.book[i].name, library.book[i].author.name, library.book[i].year);
    }
    puts("\n����������� �������� : ");
    for (int i = 0; i < library.NumReaders; i++) {
        printf("���: %s, ���� ��������: %s, ��������� �� ������ - %s\n", library.readers[i].name, library.readers[i].date, library.readers[i].address);
    }
    puts("\n�������� � ���������� : ");
    for (int i = 0; i < library.NumOperations; i++) {
        printf("����� \"%s\", ��������: %s, ���� ���������� ��������: %s, ��� ��������: %s\n", library.operations[i].book.name, library.operations[i].client.name, library.operations[i].date, library.operations[i].move);
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