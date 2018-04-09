#pragma once

string addCeros(string s, int cant) {

	for (int i = 0; i < cant; i++)
		s.insert(s.begin(), '0');

	return s;
}

string DtoH(int num, int size) {

	string s;
	char buffer[8];
	itoa(num, buffer, 16);

	int aux = num;
	int dig = 0;

	while (aux > 0) {
		aux /= 10;
		dig++;
	}

	for (int i = 0; i < dig; i++) {
		if (!isdigit(buffer[i])) {
			buffer[i] = toupper(buffer[i]);
		}
		s += buffer[i];
	}

	return addCeros(s, size - s.size());
}

void see_section(int fil, vector<int*> memory) {

	fil *= 16;
	int cond = true;

	for (int i = fil; i < fil + (16 * 16) && cond; i += 16) {

		//Imprime filas
		cout << endl << DtoH(i, 8) << " -->";

		for (int j = i; j < i + 16 && cond; j++) {

			if (j < memory.size()) {
				//Imprime Valores
				cout << "  " << DtoH(*memory[j], 2);
			}
			else {
				cond = false;
			}
		}
	}
}