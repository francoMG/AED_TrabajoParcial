#pragma once

void Events(vector<int*> memory) {

	int end = false;
	string input;

	while (!end) {

		cin.clear();

		cout << "\n 1- VER SECCION DE MEMORIA"
			<< "\n Q- SALIR" << endl << endl
			<< " >>> ";

		cin >> input;

		if (toupper(input[0]) == 'Q') {

			end = true;
		}
		else if (input[0] == '1') {

			cout << "\nIngrese la direccion de memoria (hex): ";

			cin >> input;
			see_section( input, memory);
		}
	}
}