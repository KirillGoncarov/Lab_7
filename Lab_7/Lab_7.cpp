#include <cmath>  
#include <iostream>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996) 
using namespace std;

int main(){
    setlocale(LC_ALL, "Russian");
    //II.1.	ВЫЧИСЛЕНИЕ ЗНАЧЕНИЙ ФУНКЦИИ. 
    double step,f,start;
    printf("Введите число в диапозоне (0,4]\n");
    scanf("%lf", &start);
    
    if (start > 4.0 || start <= 0.0) {
        printf("Выход за диапозон");
        return 0;
    }
    else {       
    }

    printf("");
    step = (4.0 - start)/10.0;
    f = start + step;
    for (int i = 0; i < 10; i++) {
        double znach;
        f += step;
        znach = sin(f) / f;
        printf("%f\n", znach);
       
    }
    //II.2.	ЧИСЛА ФИБОНАЧЧИ
    int Max_value;

    printf("Введите максимально допустимую сумму\n");
    scanf("%d", &Max_value);

    if (Max_value < 0) {
        printf("Недопустимое значение");
        return 0;

    }
    else {
        if (Max_value == 0) {
            printf("N = 1, S = 0\n");
        }
        else if (Max_value == 1) {
            printf("N = 2, S = 1\n");
        }
        else {
            int a_1, a_2, a_3;
            int sum;
            int col;
            a_1 = 0;
            a_2 = 1;
            a_3 = 0;
            sum = 0;
            col = 1;
            while (sum <= Max_value) {
                sum += a_2;
                a_3 = a_1 + a_2;
                a_1 = a_2;
                a_2 = a_3;
                col += 1;
            }
            
            printf("N = %d S = %d\n", col, sum);

        }
        
    }
    //П.3. КРЕДИТНЫЕ ПЛАТЕЖИ. 
    int procent, sum_kredi;
    int time;
    printf("Введите сумму кредита\n");
    scanf("%d", &sum_kredi);

    printf("срок\n");
    scanf("%d", &time);
    
    printf("Процентная ставка\n");
    scanf("%d", &procent);

    double month_pro = (static_cast<double> (procent) / static_cast<double> (time)) / 100;
    double all_procent;


    printf("---------------------------------------\n");
    printf("\t Долг\t\t Процент\t\t Платеж\n");
    printf("---------------------------------------\n");
    double sum_kredit = static_cast<double> (sum_kredi);
    double month_pay = (sum_kredit / time);
    all_procent = 0.0;
    for (int i = 1; i <= time; i++) {
        double pay,yet_pay;
        pay = static_cast<double>(sum_kredit) * month_pro;
        pay = round(pay * 100) / 100;
        yet_pay = month_pay + pay;
        printf("%d\t%.2f\t%.2f\t\t%.2f\n",i, static_cast<double>(sum_kredit), pay, yet_pay);
        sum_kredit += pay;
        sum_kredit -= yet_pay;
        all_procent += pay;

    }
    printf("---------------------------------------\n");
    printf("Всего процентов: %.2f", all_procent);


}

