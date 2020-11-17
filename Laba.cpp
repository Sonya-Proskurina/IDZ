#include <stdio.h>
#include <conio.h>
#include<windows.h>
#include<math.h>
#include <string.h>
struct file {
    double size;
    char name[100];
    char expansion[100];
};
void newString(char* arr) {
    int num = 0, ch;
    while (true) {
        ch = getchar();
        if (ch == int('\n')) break;
        arr[num] = char(ch);
        num++;}
    arr[num] = '\0';
}
int myStrcmp(char arr1[], char arr2[]) {
    int good;
    bool f = true;
    if (sizeof(arr1) != sizeof(arr2)) return 1;
    else {
        for (int i = 0; i < sizeof(arr1); i++) {
            if (arr1[i] != arr2[i]) f = false;
        }
        if (f) return 0;
        else return 1;
    }
}
void contrastChar(char* arr1, char* arr2) {
    char a[100];
    for (int i = 0; i < 100; i++) {
        a[i] = arr1[i];
        arr1[i] = arr2[i];
        arr2[i] = a[i];
    }
}
void contrastD(double* a1, double* a2) {
    double a;
    a = *a1;
    *a1 = *a2;
    *a2 = a;
}

void lr1a(float a,float b) {
    float c, d;
    c = (a + b) / 2;
    d = sqrt(a * b);
    printf("Среднее арифметическое: %f\n", c);
    printf("Среднее геометрическое: %f\n", d);
}
void lr1b(float a) {
    float y;
    if (a <= -1) y = 1 / (a * a);
    else if (a <= 2) y = a * a;
    else y = 4;
    printf("f(a)= %f\n", y);
}
void lr2a(float a,int n) {
    float p = 1;
    for (int i = 0; i <= n; i++) {
        p *= a - n * i;
    }
    printf("Ответ: %f\n", p);
}
void lr2b(int n) {
    int k = 0, a1, a2, a3;
    if (n >= 3) {
        printf("Введите числа: ");
        scanf_s("%d", &a1);
        scanf_s("%d", &a2);
        scanf_s("%d", &a3);
        if (float(a2) < (a1 + a3) / 2.) k++;
        for (int i = 0; i < n - 3; i++) {
            a1 = a2;
            a2 = a3;
            scanf_s("%d", &a3);
            if (float(a2) < (a1 + a3) / 2.) k++;
        }
    }
    printf("Ответ: %d\n", k);
}
void lr3() {
    float S = 27.6;
    float sum = 0;
    float x[14];
    float y[14];
    printf("Введите первый элемент: ");
    scanf_s("%f", &x[0]);
    sum += x[0];
    for (int i = 1; i < 14; i++) {
        x[i] = x[i - 1] + S;
        sum += x[i];
    }
    printf("Ответ на пункт 2: %e\n", (sum / 14.));
    for (int i = 0; i < 14; i++) {
        if (x[i] < 15) y[i] = 13 * x[i] * x[i];
        else if (x[i] <= 70) y[i] = (6 - x[i]) / (x[i] * x[i] + 5);
        else y[i] = sqrtf(x[i] + 1);
        printf("y%d  %.3f\n", i, y[i]);
    }
}
void lr4(int n) {
    int k = 0;
    char s[100];
    char sA[100];
    bool go = false;
    bool on = false;
    bool yes = false;
    printf("Введите строку: ");
    for (int i = 0; i <= n; i++)
    {
        s[i] = char(getchar());
        if (s[i] == 'a' && !on) {
            go = true;
            yes = true;
            sA[k] = s[i];
            k++;
            continue;
        }
        if (s[i] == ' ' && go) { go = false; on = true; }
        if (go) {
            sA[k] = s[i];
            k++;
        }

    }
    if (yes)
    printf("Любое слово, начинающееся с а: ");
    else    printf("Нет слов начинающееся с а");
    for (int i = 0; i < k; i++) printf("%c", sA[i]);
    printf("\n");
}
void lr5() {
    int  N, order, a1, a2;
    double n2;
    char s3[100];
    bool good = true;
    struct file arr[100];
    printf("Введите количество вводимых эллементов:\n");
    scanf_s("%d", &N);
    getchar();
    for (int i = 0; i < N; i++) {
        printf("Введите наименование:\n");
        newString(arr[i].name);
        printf("Введите расширение:\n");
        newString(arr[i].expansion);
        printf("Введите размер:\n");
        scanf_s("%lf", &arr[i].size);
        getchar();
    }
    printf("Введите номер задания (2-6):\n");
    scanf_s("%d", &order);
    switch (order)
    {
    case 2:
        printf("Введите индекс элемента (0-%d):\n", N - 1);
        scanf_s("%d", &order);
        printf("Введите номер операции, 1 – установка, 2 – получение:\n");
        scanf_s("%lf", &n2);
        if (n2 == 1) {
            printf("Введите новое наименование:\n");
            newString(arr[order].name);
            printf("Введите новое расширение:\n");
            newString(arr[order].expansion);
            printf("Введите новый размер:\n");
            scanf_s("%lf", &arr[order].size);
        }
        else {
            printf("Элемент с индексом %d: наименование- %s, расширение- %s, размер-%lf\n", order, arr[order].name, arr[order].expansion, arr[order].size);

        }
        break;
    case 3:
        printf("Введите номер поля, по которому осуществляется поиск (0- наименование, 1-расширение, 2-размер):\n");
        scanf_s("%d", &order);
        getchar();
        printf("Введите значение:\n");
        if (order == 0 || order == 1) {
            newString(s3);
            if (order == 0) {
                for (int i = 0; i < N; i++) {
                    if (myStrcmp(s3, arr[i].name) == 0) {
                        good = false;
                        printf("Элемент найден. Индекс элемента: %d, значения полей: {%s, %s, %lf}\n", i, s3, arr[i].expansion, arr[i].size);
                    }
                }
            }
            if (order == 1) {
                for (int i = 0; i < N; i++) {
                    if (myStrcmp(s3, arr[i].expansion) == 0) {
                        good = false;
                        printf("Элемент найден. Индекс элемента: %d, значения полей: {%s, %s, %lf}\n", i, arr[i].name, arr[i].expansion, arr[i].size);
                    }
                }
            }
        }
        else {
            scanf_s("%lf", &n2);
            for (int i = 0; i < N; i++) {
                if (n2 == arr[i].size) {
                    good = false;
                    printf("Элемент найден. Индекс элемента: %d, значения полей: {%s, %s, %lf}\n", i, arr[i].name, arr[i].expansion, arr[i].size);
                }
            }
        }
        if (good) printf("Элемент не найден\n");
        break;

    case 4:
        while (true)
        {
            printf("Введите индекс элемента №1\n");
            scanf_s("%d", &a1);
            if (a1 >= 0 && a1 <= N - 1) break;
            printf("Ошибка: индекс элемента не может быть меньше 0 или больше %d\n", N - 1);
        }
        while (true)
        {
            printf("Введите индекс элемента №2\n");
            scanf_s("%d", &a2);
            if (a2 >= 0 && a2 <= N - 1 && a1 != a2) break;
            else if (!(a2 >= 0 && a2 <= N - 1))
                printf("Ошибка: индекс элемента не может быть меньше 0 или больше %d\n", N - 1);
            else printf("Ошибка: индексы не должны совпадать!\n");
        }
        printf("Исходный массив:\n{");
        for (int i = 0; i < N; i++) {
            printf("{%s, %s, %lf}, ", arr[i].name, arr[i].expansion, arr[i].size);
        }
        printf("}\n");
        contrastChar(arr[a1].name, arr[a2].name);
        contrastChar(arr[a1].expansion, arr[a2].expansion);
        contrastD(&arr[a1].size, &arr[a2].size);
        printf("Результирующий массив:\n{");
        for (int i = 0; i < N; i++) {
            printf("{%s, %s, %lf}, ", arr[i].name, arr[i].expansion, arr[i].size);
        }
        printf("}\n");
        break;

    case 5:
        printf("Введите номер поля, по которому будет выполнена сортировка (0- наименование, 1-расширение, 2-размер):\n");
        scanf_s("%d", &order);
        printf("Исходный массив:\n{");
        for (int i = 0; i < N; i++) {
            printf("{%s, %s, %lf}, ", arr[i].name, arr[i].expansion, arr[i].size);
        }
        printf("}\n");
        if (order == 0) {
            for (int i = 0; i < N - 1; i++) {
                for (int j = 0; j < N - 1 - i; j++) {
                    if (arr[j].name < arr[j + 1].name) {
                        contrastChar(arr[j].name, arr[j + 1].name);
                        contrastChar(arr[j].expansion, arr[j + 1].expansion);
                        contrastD(&arr[j].size, &arr[j + 1].size);
                    }
                }
            }
        }
        else if (order == 1) {
            for (int i = 0; i < N - 1; i++) {
                for (int j = 0; j < N - 1 - i; j++) {
                    if (arr[j].expansion < arr[j + 1].expansion) {
                        contrastChar(arr[j].name, arr[j + 1].name);
                        contrastChar(arr[j].expansion, arr[j + 1].expansion);
                        contrastD(&arr[j].size, &arr[j + 1].size);
                    }
                }
            }
        }
        else {
            for (int i = 0; i < N - 1; i++) {
                for (int j = 0; j < N - 1 - i; j++) {
                    if (arr[j].size < arr[j + 1].size) {
                        contrastChar(arr[j].name, arr[j + 1].name);
                        contrastChar(arr[j].expansion, arr[j + 1].expansion);
                        contrastD(&arr[j].size, &arr[j + 1].size);
                    }
                }
            }
        }
        printf("Массив, отсортированный по полю %d: \n{", order);
        for (int i = 0; i < N; i++) {
            printf("{%s, %s, %lf}, ", arr[i].name, arr[i].expansion, arr[i].size);
        }
        printf("}\n");
        break;
    case 6:
        printf("Введите начало диапазона (0-%d): \n", N - 1);
        scanf_s("%d", &a1);
        printf("Введите конец диапазона (если хотите вывести один элемент введите первое число еще раз): \n");
        scanf_s("%d", &a2);
        for (int i = a1; i <= a2; i++) {
            printf("Элемент с индексом %d: наименование- %s, расширение- %s, размер- %lf\n", i, arr[i].name, arr[i].expansion, arr[i].size);
        }
        break;
    }
}
int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    int go,num=0;
    bool f = true;
    float a,b;
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    system("color 04");
    printf("\n");
    printf("\n");
    printf("\n");
    for (int i = 0; i < 40; i++) {
        printf(" ");
    }
    printf("Липецкий государственный технический университет\n\n");
    for (int i = 0; i < 45; i++) {
        printf(" ");
    }
    printf("Факультет автоматизации и информатики\n\n");
    for (int i = 0; i < 42; i++) {
        printf(" ");
    }
    printf("Кафедра автоматизированных систем управления\n\n\n");
    for (int i = 0; i < 48; i++) {
        printf("-");
    }
    SetConsoleTextAttribute(hConsole, (WORD)(12));
    printf("ИНДИВИДУАЛЬНОЕ ДОМАШНЕЕ ЗАДАНИЕ");
    for (int i = 0; i < 41; i++) {
        printf("-");
    }
    printf("\n\n\n");
    for (int i = 0; i < 51; i++) {
        printf(" ");
    }
    SetConsoleTextAttribute(hConsole, (WORD)(14));
    printf("по курсу Программирование\n\n");
    for (int i = 0; i < 55; i++) {
        printf(" ");
    }
    printf("Изучение функций\n\n\n");
    SetConsoleTextAttribute(hConsole, (WORD)(5));
    for (int i = 0; i < 30; i++) {
        printf(" ");
    }
    printf("Студент   Проскурина С.А.");
    for (int i = 0; i < 14; i++) {
        printf(" ");
    }
    printf("Руководитель   Журавлева М.Г.\n\n\n\n");
    for (int i = 0; i < 57; i++) {
        printf(" ");
    }
    printf("Липецк, 2020\n\n");
    SetConsoleTextAttribute(hConsole, (WORD)(1));
    while (true)
    {
        for (int i = 0; i < 47; i++) {
            printf(" ");
        }
        printf("--->Для начала работы введите 1<---\n\n");
        for (int i = 0; i < 57; i++) {
            printf(" ");
        }
        scanf_s("%d", &go);
        if (go == 1) break;
    }
    system("cls");
    while (f)
    {
        printf("МЕНЮ:\n\n");
        printf("1)a.Программирование линейных и условных алгоритмов\n\n");
        printf("2)б.Программирование линейных и условных алгоритмов\n\n");
        printf("3)а.Программирование циклических алгоритмов\n\n");
        printf("4)б.Программирование циклических алгоритмов\n\n");
        printf("5)Обработка массивов значений\n\n");
        printf("6)Обработка строковых значений\n\n");
        printf("7)Обработка элементов структур\n\n");
        printf("8)Выход\n\n");
        printf("Введите номер пункта: ");
        scanf_s("%d", &num);
        switch (num)
        {
        case 1: 
            printf("Введите два числа: ");
            scanf_s("%f%f", &a, &b);
            lr1a(a,b);
            break;
        case 2:
            printf("Введите а: ");
            scanf_s("%f", &a);
            lr1b(a);
            break;
        case 3:
            printf("Введите а: ");
            scanf_s("%f", &a);
            printf("Введите n: ");
            scanf_s("%d", &go);
            lr2a(a,go);
            break;
        case 4:
            printf("Введите n: ");
            scanf_s("%d", &go);
            lr2b(go);
            break;
        case 5:
            lr3();
            break;
        case 6:
            printf("Введите n: ");
            scanf_s("%d", &go);
            lr4(go);
            break;
        case 7:
            lr5();
            break;
        case 8:
            f = false;
            break;
        default:
            printf("\n");
            printf("Данный номер не найден\n\n");
            break;
        }
        _getch();
        printf("\n\n"); 
    }
    _getch();
    return 0;
}