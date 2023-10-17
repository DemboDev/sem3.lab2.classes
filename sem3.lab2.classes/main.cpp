#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <conio.h>
#include "Lib.h"

int main()
{
    setlocale(LC_ALL, "rus");
    SetConsoleCP(1251);
    Author author = AuthorInput();
    Book book = BookInput(author);
    Client client = ClientInput();
    Operation operation = OperationInput(book, client);
    Library library = LibraryInp(book, client, operation);
    int exit = 0; char n;
    do {
        system("cls");
        PrintLibrary(library);
        puts("Библиотека создана. . .");
        puts("Хотите добавить элемент в библиотеку?\n1) Добавить Книгу\n2) Добавить читателя\n3) Добавить операцию\n4) Выйти из программы\n");
        n = vvod('1', '4');
        switch (n) {
        case '1':
            library = AddBookToLibrary(library, BookInput(AuthorInput()));
            PrintLibrary(library);
            break;
        case '2':
            library = AddReaderToLibrary(library, ClientInput());
            PrintLibrary(library);
            break;
        case '3':
            library = AddOperationToLibrary(library, OperationInput(BookInput(AuthorInput()), ClientInput()));
            PrintLibrary(library);
            break;
        case '4':
            exit = 1;
            break;
        }
    } while (exit == 0);

    return 0;
}
