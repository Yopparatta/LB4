#include <iostream>
#include <random>
#include <vector>
#include <math.h>

using namespace std;

static mt19937_64 rng;

int main()
{
    setlocale(LC_ALL,"Russian");
    int n;
    unsigned int ciferka;
    cout << "Введите количество элементов в массиве\n";
    cin >> n;
    vector<vector<int>> out_line;
    vector<int> tmp;
    bool is_first_zero;
    for (int i = 0; i < n; i++)
    {
        tmp = {};
        for (int i = 0; i < rng() % 9 + 1; i++)
        {
            tmp.push_back(rng() % 9 + 1);
        }
        tmp.push_back(0);
        out_line.push_back(tmp);
    }
    for (size_t i = 0; i < out_line.size(); i++)
    {

        for (int item : out_line[i]) {
            cout << item;
        }
        cout << endl;
    }
    cout << "Перевернутый массив\n";
    reverse(out_line.begin(), out_line.end());
    for (size_t i = 0; i < out_line.size(); i++)
    {
        reverse(out_line[i].begin(), out_line[i].end());
        is_first_zero = true;
        for (int item : out_line[i]) {
            if (item != 0) {
                is_first_zero = false;
                cout << item;
                continue;
            }
            if (!is_first_zero)
                cout << item;
        }
        cout << endl;
    }

}
