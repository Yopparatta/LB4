#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    setlocale(LC_ALL,"Russian");
    unsigned int a = 2, b = 21740, p = 30323, x, k, i = 1, j = 1;
    k = (int)sqrt(p) + 1;
    for (i = 1; i < k; i++) {




        for (j = 1; j < k; j++) {
            if (((unsigned int)pow(a, i) * b % p) == ((unsigned int)pow(a, j * k) % p)) {
                break;
            }
        }
        if (((unsigned int)pow(a, i) * b % p) == ((unsigned int)pow(a, j * k) % p)) {
            cout << (unsigned int)pow(a, i) * b << "\t" << (unsigned int)pow(a, j * k) << endl;
            break;
        }



    }
    x = k * i - j;
    cout << x;
    long degree;
    degree = x;
    x = 2;
        long prost=30323;
        long s = 1;
        cout << "Введите X, его степень и простое число" << endl;
        cout << "Остаток от деления " << x << " В степени " << degree << " на " << prost << endl;
        degree = degree % (prost - 1);
        for (int i = 1; i <= degree; i++)
        {
            s = (s * x) % prost;
        }
        cout << s;

}