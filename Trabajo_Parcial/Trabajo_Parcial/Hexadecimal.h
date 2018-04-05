#pragma once

/*
Funte: http://www.solveet.com/exercises/decimal-a-hexadecimal-/605/solution-3229
*/

string DtoH(short num) {

	string res;

	int num3 = 0, num4 = 0, contador = 0;
	char letra;
	char numero_String[100];
	float num2 = 1;
	static int indice;
	num2 = num;
	while (num2 >= 1) {
		num2 = num2 / 16;
		contador++;
	}

	string numero_hex = "null";

	for (indice = 0; indice < contador; indice++) {
		num3 = num / 16;
		num4 = num % 16;
		if (num4 < 10) {
			sprintf(numero_String, "%d", num4);
			numero_hex[contador - indice - 1] = *numero_String;
		}
		else {
			switch (num4) {
			case 10:
				letra = 'A';
				break;
			case 11:
				letra = 'B';
				break;
			case 12:
				letra = 'C';
				break;
			case 13:
				letra = 'D';
				break;
			case 14:
				letra = 'E';
				break;
			case 15:
				letra = 'F';
				break;
			}
			numero_hex[contador - indice - 1] = letra;
		}
		num = num3;
	}

	for (indice = 0; indice < contador; indice++)
		res += numero_hex[indice];

	return res;
}
