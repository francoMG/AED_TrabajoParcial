#include <iostream>
#include <conio.h>
#include <string>
#include <iomanip>
#include <vector>
#include <stdio.h>

using namespace std;

#include "Hexadecimal.h"

int main() {

	srand(time(NULL));

	//es dinamico para que la memoria no se copie tantas veces
	vector<int*> memory;

	for (int i = 0; i < 2048; i++)
		memory.push_back(new int(i % 256));

	/* Reporte de toda la memoria:*/
	for (int i = 0; i < memory.size() / 16; i += 16)
		see_section(i, memory);


	//Roperte de 16 filas apartir de la fila 8:
	//see_section(8, memory);



	//eliminar memoria
	while (memory.size() > 0) {
		delete memory[0];
		memory.erase(memory.begin());
	}

	_getch();
	return 0;
}
