#include <cmath>  
#include <iostream>

using namespace std;

#define Dl 10

int main() {
    setlocale(LC_ALL, "RU");
    srand(time(NULL));


    cout << "Выберите вариант заполнения массива" << endl;
    cout << "1.статический массив, индексная адресация;" << endl;
    cout << "2.статический массив, адресация с помощью указателя" << endl;
    cout << "3.динамический массив, индексная адресация;" << endl;
    cout << "4.динамический массив, адресация с помощью указателя " << endl;

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


    return 0;
}
