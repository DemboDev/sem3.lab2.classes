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
        if (n == '1') {
            library.AddBookToLibrary(BookInput(AuthorInput()));
            library.PrintLibrary();
        }
        if (n == '2') {
            library.AddReaderToLibrary(ClientInput());
            library.PrintLibrary();
        }
        if (n == '3') {
            Book b = BookInput(AuthorInput());
            Client c = ClientInput();
            library.AddBookToLibrary(b);
            library.AddReaderToLibrary(c);
            library.AddOperationToLibrary(OperationInput(b, c));
            library.PrintLibrary();
        }
        if (n == '4') {
            exit = 1;
        }
    } while (exit == 0);

    return 0;
}
