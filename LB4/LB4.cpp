#include <iostream>
#include <vector>
#include <math.h>

using namespace std;


void ShakerSort(vector<int>& values) {
    if (values.empty()) {
        return;
    }
    int left = 0;
    int right = values.size() - 1;
    while (left <= right) {
        for (int i = right; i > left; --i) {
            if (values[i - 1] > values[i]) {
                swap(values[i - 1], values[i]);
            }
        }
        ++left;
        for (int i = left; i < right; ++i) {
            if (values[i] > values[i + 1]) {
                swap(values[i], values[i + 1]);
            }
        }
        --right;
    }
}

int main()
{
    setlocale(LC_ALL,"Russian");
    vector<int> array = { -1 ,  2 , -3 ,  4 ,  7 ,  6, 3  };
    int sum = 0, min=10,max=0,index=0,proizv=1,indmin=0,indmax=0;
    for (int i : array) {
        if (i > 0) {
            sum += i;
        }
        if (min > abs(i)) { min = abs(i); indmin = index; }
        if (max < abs(i)) { max = abs(i); indmax = index; }
        index++;
    }

    if (min < max) {
        for (index = indmin; index <= indmax; index++)
        {
            proizv*=array[index];
        }
    }
    else {
        for (index = indmax; index <= indmin; index++)
        {
            proizv *= array[index];
        }
    }
    ShakerSort(array);


    cout << "Сумма всех положительных элементов\n" << sum << endl;
    cout << "Произведение элементов, находящихся между наибольшим и наименьшим по модулю\n" << proizv << endl << "Отсортированный массив\n";
    for (auto i : array) cout << i << endl;





}
