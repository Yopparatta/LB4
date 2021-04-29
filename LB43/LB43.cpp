#include <iostream>
#include <math.h>
#include <vector>
#include <random>

using namespace std;

static minstd_rand0 rng;

const int A = 1;
const int B = 100;

int f() { return rng() % (B - A) + A; }

void Eacharray(int n, vector<int> nCount) {
    double Xi=0;
    for (int i = 0; i < n; i++) {
        nCount.push_back(f());
    }
    for (int i : nCount) cout << i << " ";
    cout << endl;
    double dPTeor = 1.0 / n;
   // cout << dPTeor << endl;
    for (int i = 0; i < n; i++) {
        Xi += pow(dPTeor - ((double)nCount[i] / n), 2) / ((double)nCount[i] / n);
    }
    cout << endl << Xi << endl;
}

int main() {
    double Xi = 0;
    vector<int> nCount50,nCount100,nCount1000;
    Eacharray(50, nCount50);
    Eacharray(100, nCount100);
    Eacharray(1000, nCount1000);
}