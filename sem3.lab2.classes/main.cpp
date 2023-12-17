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
    try {
        Client errorClient("1234");
    }
    catch (const invalid_argument& errorClient) {
        cout << errorClient.what();
    }
    Author author = AuthorInput();
    Book book = BookInput(author);
    Client client = ClientInput();
    Operation operation = OperationInput(book, client);
    Library library = LibraryInp(book, client, operation);
    int exit = 0; char n;
    QueueOfOperations queue;
    do {
        system("cls");
        library.PrintLibrary();
        puts("Библиотека создана. . .");
        puts("Хотите добавить элемент в библиотеку?\n1) Добавить Книгу\n2) Добавить читателя\n3) Добавить операцию\n4) Работа со сборником\n5) Сортировка и вывод операций по порядку дат\n6) Выйти из программы\n");
        n = vvod('1', '6');
        if (n == '1') {
            puts("1) Добавить книгу \n2) Добавить книгу-сборник\n");
            n = vvod('1', '2');
            if (n == '1') {
                Book b = BookInput(AuthorInput());
                library + b;
                library.PrintLibrary();
            }
            else {
                Book b = BookInput(AuthorInput());
                BookCollection bc;
                bc = b;
                library.AddBookCollectionToLibrary(bc);
                library.PrintLibrary();
            }
        }
        else if (n == '2') {
            library.AddReaderToLibrary(ClientInput());
            library.PrintLibrary();
        }
        else if (n == '3') {
            int k;
            puts("Хотите использовать уже существующую книгу?\n1) Да\n2) Нет");
            do {
                scanf("%d", &k);
            } while (k < 1 || k > 2);
            Book b;
            if (k == 1) {
                system("cls");
                library.PrintLibrary();
                puts("Введите номер книги из списка");
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
            puts("Хотите использовать уже существующего читателя?\n1) Да\n2) Нет");
            do {
                scanf("%d", &k);
            } while (k < 1 || k > 2);
            Client c;
            if (k == 1) {
                system("cls");
                library.PrintLibrary();
                puts("Введите номер читателя из списка");
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
        else if (n == '6') {
            int ans;
            puts("Точно?\n1)Да\n2)Нет");
            scanf("%d", &ans);
            if (ans == 1) {
                exit = 1;
            }
        }
        else if (n == '5') {
            system("cls");
            transferElements(library, queue);
            queue.Print();
            _getch();
        }
        else if (n == '4') {
            static Collection collection;
            int choice;
            do {
                system("cls");
                puts("Работа со сборником:\n\n1) Добавить книгу\n2) Вывести сборник\n3) Выход\n");
                choice = vvod('1', '3');
                if (choice == '1') {
                    system("cls");
                    int num;
                    cout << "Введите номер тома (до " << collection.GetNumOfToms() + 1 << ")\n";
                    do {
                        scanf("%d", &num);
                        num -= 1;
                    } while (num < 0 || num > collection.GetNumOfToms());
                    system("cls");
                    library.PrintLibrary();
                    puts("Введите номер книги из списка");
                    int nOfBook;
                    do {
                        scanf("%d", &nOfBook);
                    } while (nOfBook < 1 || nOfBook > library.GetNumBooks());
                    Book b = library.book.at(nOfBook - 1);
                    collection.AddBook(num, b);
                    }
                if (choice == '2') {
                    system("cls");
                    collection.Print();
                    puts("Нажмите любую клавишу для продолжения");
                    _getch();
                    }
            } while (choice != '3');
        }
    } while (exit == 0);

    return 0;
}
