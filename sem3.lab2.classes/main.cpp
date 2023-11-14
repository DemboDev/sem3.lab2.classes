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
        puts("���������� �������. . .");
        puts("������ �������� ������� � ����������?\n1) �������� �����\n2) �������� ��������\n3) �������� ��������\n4) ����� �� ���������\n");
        n = vvod('1', '4');
        if (n == '1') {
            Book b = BookInput(AuthorInput());
            library + b;
            library.PrintLibrary();
        }
        if (n == '2') {
            library.AddReaderToLibrary(ClientInput());
            library.PrintLibrary();
        }
        if (n == '3') {
            int k;
            puts("������ ������������ ��� ������������ �����?\n1) ��\n2) ���");
            do {
                scanf("%d", &k);
            } while (k < 1 || k > 2);
            Book b;
            if (k == 1) {
                system("cls");
                library.PrintLibrary();
                puts("������� ����� ����� �� ������");
                int nOfBook;
                do {
                    scanf("%d", &nOfBook);
                } while (nOfBook < 1 || nOfBook > library.GetNumBooks());
                b = library.book.at(nOfBook - 1);
            }
            else {
                b = BookInput(AuthorInput());
                library.AddBookToLibrary(b);
            }
            puts("������ ������������ ��� ������������� ��������?\n1) ��\n2) ���");
            do {
                scanf("%d", &k);
            } while (k < 1 || k > 2);
            Client c;
            if (k == 1) {
                system("cls");
                library.PrintLibrary();
                puts("������� ����� �������� �� ������");
                int nOfReader;
                do {
                    scanf("%d", &nOfReader);
                } while (nOfReader < 1 || nOfReader > library.GetNumReaders());
                c = library.readers.at(nOfReader - 1);
            }
            else {
                c = ClientInput();
                library.AddReaderToLibrary(c);
            }
            library.AddOperationToLibrary(OperationInput(b, c));
            library.PrintLibrary();
        }
        if (n == '4') {
            exit = 1;
        }
    } while (exit == 0);

    return 0;
}
