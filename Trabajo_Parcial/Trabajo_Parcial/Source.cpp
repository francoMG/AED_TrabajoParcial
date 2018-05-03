#include <iostream>
#include <map>
#include <string>
#include <conio.h>
#include <iomanip>
#include <vector>
#include <stdio.h>
#include <windows.h>

using namespace std;
#include "Hexadecimal.h"
#include "Events.h"
#include "var.h"

int main() {

	srand(time(NULL));

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0F);//Imprime texto en blanco, ver = (linea 63 Hexadecimal.h)

	int memory_size = 1 << 20;
	unsigned char* memory = new unsigned char[memory_size];

	for (int i = 0; i < memory_size; i++) memory[i] = rand()%127;
	
	vector<vec> vars;

	Events(memory, memory_size, vars);

	delete memory;

	return 0;
}
