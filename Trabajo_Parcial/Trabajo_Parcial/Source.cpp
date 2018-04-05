#include <iostream>
#include <conio.h>
#include <string>
#include <iomanip>
#include <vector>
#include <stdio.h>

using namespace std;

#include "Hexadecimal.h"

int main() {

	vector<short> memory;

	for (int i = 0; i < 1000; i++)
		memory.push_back(rand() % 256);

	int a = 1;
	cout << "  ";
	for (int i = 0; i < memory.size(); i++) {
		if (a == 16) { a = 1; cout << endl; }
		cout << DtoH(memory[i]) << setw(4);
		a++;
	}

	_getch();
	return 0;
}
