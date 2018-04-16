#pragma once

void Events(char *memory, int memory_size) {

	int end = false;
	string input;

	while (!end) {

		cin.clear();

		cout << "\n 1- VER SECCION DE MEMORIA"
			<< "\n Q- SALIR"
			<< "\n %- OTHER"
			<< "\n\n >>> ";

		cin >> input;

		if (toupper(input[0]) == 'Q') {

			end = true;
		}
		else if (input[0] == '1') {

			cout << "\nIngrese la direccion de memoria (hex): ";

			cin >> input;
			see_section( input, memory, memory_size);
		}
		else {
			end = true;
		}
	}
}