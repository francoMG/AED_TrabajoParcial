#pragma once

void Events(unsigned char *memory, int memory_size, map<string, unsigned char> &vars) {

	int end = false;
	string input;

	while (!end) {

		cin.clear();

		cout << "\n 1- VER SECCION DE MEMORIA"
			<< "\n 2- INGRESAR VALOR EN LA MEMORIA"
			<< "\n %- SALIR"
			<< "\n\n >>> ";

		cin >> input;
		
		//Ver seccion de memoria
		if (input == "1") {

			cout << "\nIngrese la direccion (hex): ";

			cin >> input;
			seeSection(input, memory, memory_size);
		}

		//Ingresar valor en la memoria
		else if (input[0] == '2') {
			
			int tp, dir, val;
			cout << "\nSeleccione el tipo de dato:\n"
				<<"\n 1- INT"
				<<"\n 2- CHAR"
				<<"\n 3- DOUBLE"
				<<"\n 4- FLOAT"
				<<"\n 5- BOOL"
				<< "\n\n >>> ";
			cin >> tp;
			
			cout << "\nIngrese el valor: "
				<< "\n\n >>> ";
			cin >> val;

			cout << "\nIngrese la direccion (hex): "
				<< "\n\n >>> ";
			cin >> hex >> dir >> dec;

			writeVar(memory, dir, (unsigned char *)&val,
				((tp == 1) * sizeof(int)) + ((tp == 2) * sizeof(char)) + ((tp == 3) * sizeof(double)) +
				((tp == 4) * sizeof(float)) + ((tp == 5) * sizeof(bool))
			);
		}

		//Salir
		else {

			end = true;
		}
	}
}
