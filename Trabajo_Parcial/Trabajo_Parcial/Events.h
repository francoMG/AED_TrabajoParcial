#pragma once

void Events(vector<int*> memory) {

	int end = false;
	char input;

	while (!end) {

		cout << "1- Ver seccion de memoria" << endl
			<< "2- Salir" << endl;
		cin >> input;

		switch (input) {
		case '1':
		{
			cout << "Ingrese la fila de la memoria: ";
			cin >> input;
			see_section(input, memory);
		}
		case '2':
		{
			end = true;
		}
		default:
			break;
		}
	}
}