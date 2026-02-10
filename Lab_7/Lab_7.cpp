#include <cmath>  
#include <iostream>
#include <cstdio>  

using namespace std;

int main(){
    setlocale(LC_ALL, "Russian");
    //II.1.	ВЫЧИСЛЕНИЕ ЗНАЧЕНИЙ ФУНКЦИИ. 
    double step,f,start;
    start = 0.0;
    printf("Введите число в диапозоне (0,4]\n");
    cin >> start;
    printf("");
    step = start/10.0;
    f = start;
    for (int i = 0; i < 10; i++) {
        double znach;
        f += step;
        znach = sin(f) / f;
        printf("%f\n", znach);
       
    }
}

