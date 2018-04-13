#pragma once

string addCeros(string s, int cant) {

	for (int i = 0; i < cant; i++)
		s.insert(s.begin(), '0');

	return s;
}

string DtoH(int num, int size) {

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

void see_section(string dir, vector<int*> memory) {

	cout << dir << endl;
	dir[dir.size() - 1] = '0';//Para que se vea ordenado. A0F7 => A0F0
	cout << dir << endl;
	int fil = stoi(dir, nullptr, 16);
	int cond = true;

	for (int i = fil; i < fil + (16 * 16) && cond; i += 16) {

		//Imprime direccion de la fila
		cout << endl << DtoH(i, 8) << " >>> ";

		for (int j = i; j < i + 16 && cond; j++) {

			if (j < memory.size()) {
				//Imprime valor en hex
				cout << " " << DtoH(*memory[j], 2);
			}
			else {
				cond = false;
			}
		}

		cout << " >>> ";
		cond = true;

		for (int j = i; j < i + 16 && cond; j++) {

			if (j < memory.size()) {
				//imprime valor en ascii
				if (isalpha(*memory[j]) || isdigit(*memory[j])) {
					cout << (char)*memory[j];
				}
				else {
					cout << ".";
				}
			}
			else {
				cond = false;
			}
		}
	}

	cout << "\n";
}