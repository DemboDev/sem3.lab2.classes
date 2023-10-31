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
        library.PrintLibrary();
        puts("Библиотека создана. . .");
        puts("Хотите добавить элемент в библиотеку?\n1) Добавить Книгу\n2) Добавить читателя\n3) Добавить операцию\n4) Выйти из программы\n");
        n = vvod('1', '4');
        switch (n) {
        case '1':
            library.AddBookToLibrary(BookInput(AuthorInput()));
            library.PrintLibrary();
            break;
        case '2':
            library.AddReaderToLibrary(ClientInput());
            library.PrintLibrary();
            break;
        case '3':
            library.AddOperationToLibrary(OperationInput(BookInput(AuthorInput()), ClientInput()));
            library.PrintLibrary();
            break;
        case '4':
            exit = 1;
            break;
        }
    } while (exit == 0);

    return 0;
}
