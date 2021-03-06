#pragma once

string addCeros(string s, int cant) {

	for (int i = 0; i < cant; i++)
		s.insert(s.begin(), '0');

	return s;
}

string decToHex(int num, int size) {

	string s;
	char buffer[8] = { 0,0,0,0,0,0,0,0 };
	itoa(num, buffer, 16);

	int dig;
	for (dig = 7; dig >= 0; dig--) {
		if (buffer[dig] != 0)
			break;
	}
	dig++;

	for (int i = 0; i < dig; i++) {
		if (!isdigit(buffer[i])) {
			buffer[i] = toupper(buffer[i]);
		}
		s += buffer[i];
	}

	return addCeros(s, size - s.size());
}

void seeSection(string dir, unsigned char *memory, int memory_size) {

	int d_val = stoi(dir, nullptr, 16);

	dir[dir.size() - 1] = '0';//Para que se vea ordenado. A0F7 => A0F0

	int fil = stoi(dir, nullptr, 16);

	cout << "\n             00 01 02 03 04 05 06 07  08 09 0A 0B 0C 0D 0E 0F\n" <<
		"             ^^ ^^ ^^ ^^ ^^ ^^ ^^ ^^  ^^ ^^ ^^ ^^ ^^ ^^ ^^ ^^";

	for (int i = fil; i < fil + (16 * 16) && i < memory_size; i += 16) {

		//Imprime direccion de la fila
		cout << "\n" << decToHex(i, 8) << " >>>";

		//Imprime valor en hex
		for (int j = i; j < i + 16 && j < memory_size; j++) {

			if (j % 8 == 0) {

				cout << " ";
			}

			if (j != d_val) {

				cout << decToHex((int)memory[j], 2) << " ";
			}
			else {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0A);//Imprime texto en verde
				cout << decToHex((int)memory[j], 2) << " ";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0F);//Regresa a la impresion en blanco
			}
		}

		cout << ">>> ";

		//imprime valor en ascii
		for (int j = i; j < i + 16 && j < memory_size; j++) {

			if (memory[j] > 32 && memory[j] < 127) {
				if (j != d_val) {

					cout << memory[j];
				}
				else {
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0A);//Imprime texto en verde
					cout << memory[j];
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0F);//Regresa a la impresion en blanco
				}
			}
			else {
				if (j != d_val) {

					cout << ".";
				}
				else {
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0A);//Imprime texto en verde
					cout << ".";
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0F);//Regresa a la impresion en blanco
				}
			}
		}
	}

	cout << "\n";
}

void writeVar(unsigned char *memory, int dir, unsigned char *var, int size) {

	for (int i = 0; i < size; i++)
		memory[dir + i] = var[i];
}
