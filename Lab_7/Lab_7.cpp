#include <cmath>  
#include <iostream>
#include <algorithm> 


using namespace std;
#define Dl 10

//Структура двусвязного списка
struct Dubl_list {
    int value;
    Dubl_list* prev;
    Dubl_list* next;

    Dubl_list(int val) : value(val), prev(nullptr), next(nullptr) {}
};


void bubbleSort(int* arr, int n);

int main() {
    setlocale(LC_ALL, "RU");
    srand(time(NULL));


    cout << "Выберите вариант заполнения массива" << endl;
    cout << "1.Статический массив, индексная адресация;" << endl;
    cout << "2.Статический массив, адресация с помощью указателя" << endl;
    cout << "3.Динамический массив, индексная адресация;" << endl;
    cout << "4.Динамический массив, адресация с помощью указателя " << endl;
    cout << "5.Объединение двух упорядоченных по возрастанию массивов" << endl;
    cout << "6.Программа создания двусвязного самоадресуемого списка" << endl;

    int num;
    cin >> num;

    cout << endl;
    if (num == 1) {
        
        int mas[Dl];
        for (int i = 0; i < Dl; i++) {
            mas[i] = 1 + rand() % 100;
        }
        for (int i = 0; i < Dl; i++) {
            cout << mas[i] << " ";
        }
        cout << endl;
    }
    else if (num == 2) {
        int mas[Dl];
        int* el;
        el = mas;

        for (int i = 0; i < Dl; i++) {
            *el = 1 + rand() % 100;
            el++;
        }
        for (int i = 0; i < Dl; i++) {
            cout << mas[i] << " ";
        }
        cout << endl;
    }
    else if (num == 3) {
        int* mas;
        mas = new int[Dl];

        for (int i = 0; i < Dl; i++) {
            mas[i] = 1 + rand() % 100;
        }
        for (int i = 0; i < Dl; i++) {
            cout << mas[i] << " ";
        }
        cout << endl;
        delete[] mas;
    }
    else if(num == 4){
        int* mas, *el;
        mas = new int[Dl];
        el = mas;

        for (int i = 0; i < Dl; i++) {
            *el = 1 + rand() % 100;
            el++;
        }
        for (int i = 0; i < Dl; i++) {
            cout << mas[i] << " ";
        }
        cout << endl;

        delete[] mas;
    }
    else if (num == 5) {

        int dl_1, dl_2;
        int* mas_1, * mas_2;
        
        cout << "Введите размеры массивов" << endl;
        cin >> dl_1;
        cin >> dl_2;

        mas_1 = new int[dl_1];
        mas_2 = new int[dl_2];


        //Заполнение массивов(не упорядоченны)
        for (int i = 0; i < dl_1; i++) {
            mas_1[i] = 1 + rand() % 100;
        }
        for (int i = 0; i < dl_2; i++) {
            mas_2[i] = 1 + rand() % 100;
        }
        
        cout << endl;
        //Функция сортировки по отдельности
        bubbleSort(mas_1, dl_1);
        bubbleSort(mas_2, dl_2);
        
        for (int i = 0; i < dl_1; i++) {
            cout << mas_1[i] << " ";
        }
        cout << endl;
        for (int i = 0; i < dl_2; i++) {
            cout << mas_2[i] << " ";
        }
        cout << endl;



        //Объединение массивов
        int* uk;
        int* all_mas;
        int dl_mas,n, i, j;

        dl_mas = dl_1 + dl_2;

        all_mas = new int[dl_mas];
        uk = mas_2;

        n = 0; i = 0; j = 0;


        while (i < dl_1 && j < dl_2) {
            if (mas_1[i] <= *uk) {

                if (mas_1[i] < *uk) {
                    all_mas[n++] = mas_1[i++];
                }
                else {
                    all_mas[n++] = mas_1[i++];
                    all_mas[n++] = *uk;
                    uk++;
                    j++;
                }
            }
            else {
                all_mas[n++] = *uk;
                uk++;
                j++;
            }
        }

        while (i < dl_1) {
            all_mas[n++] = mas_1[i++];
        }

        while (j < dl_2) {
            all_mas[n++] = *uk;
            j++;
            uk++;
        }

        cout << "\n" << endl;


        for (int i = 0; i < dl_mas; i++) {
            cout << all_mas[i] << " ";
        }

        cout << "\n" << endl;
        cout << i << endl;
        cout << j << endl;


        delete[] mas_1; delete[] mas_2; delete[] all_mas;
    }
    else {
        cout << "Двусвязный список" << endl;

        Dubl_list* head = new Dubl_list(1);
        Dubl_list* current = head;

        for (int i = 0; i <= 10; i++) {
            Dubl_list* newVal = new Dubl_list(i);

            current->next = newVal;
            newVal->prev = current;

            current = newVal;
        }

        Dubl_list* tail = current;

        //Вывод списка
        current = head;
        while (current != nullptr) {
            cout << current->value << " ";

            current = current->next;
        }
    }


    return 0;
}







void bubbleSort(int* arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Обмен элементов
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

