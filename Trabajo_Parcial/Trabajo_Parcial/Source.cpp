#include <iostream>
#include <string>
#include <conio.h>
#include <iomanip>
#include <vector>
#include <stdio.h>

using namespace std;

#include "Hexadecimal.h"
#include "Events.h"

int main() {

	srand(time(NULL));

	//Es dinamico para que la memoria no se copie tantas veces
	vector<int*> memory(1000);//Cambiar a 1000000 para la presentacion

	//Inicializar con valores aleatorios para la presentacion
	for (int i = 0; i < memory.size(); i++) {
		memory[i] = new int;
		*memory[i] = i % 256;
	}



	//Reporte de toda la memoria: NO HACER PQ SE DEMORA MUCHO :V
	//for (int i = 0; i < memory.size() / 16; i += 16)
	//	see_section(i, memory);

	Events(memory);

	//Liberar memoria
	while (memory.size() > 0) {
		delete memory[0];
		memory.erase(memory.begin());
	}

	return 0;
}