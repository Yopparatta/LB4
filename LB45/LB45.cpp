#include <iostream>
#include <list>

using namespace std;


bool func(list<int>& program,list<int>& computer) {
	if (program.end() == program.begin()) return true;
	list<int>::iterator progIter=program.end();
	progIter--;
	list<int>::iterator compIter = computer.end();
	compIter--;
	if (*progIter <= *compIter) {
		*compIter -= *progIter;
		program.pop_back();
		computer.sort();
		func(program, computer);
	}
	else if (*compIter-*progIter<0) return false;
	if (program.end() == program.begin()) return true;
}

int main(void)
{
	srand(time(0));
	setlocale(LC_ALL,"Russian");
	int pc,n;
	list <int> computer;
	list <int> program;
	cout << "Введите количество компьютеров и количество программ\n";
	cin >> pc >> n;
	cout << endl;
	for (int i = 0; i < pc; i++) {
		computer.push_back(rand()%10+1);
	}
	for (int i = 0; i < n; i++) {
		program.push_back(rand() % 10 + 1);
	}
	computer.sort();
	program.sort();
	for (int i : computer) {
		cout << i << endl;
	}
	cout << endl;
	for (int i : program) {
		cout << i << endl;
	}
	cout << endl << func(program, computer) << endl;
}
