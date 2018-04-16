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

	int memory_size = 1 << 20;
	char* memory = new char[memory_size];

	for (int i = 0; i < memory_size; i++) memory[i] = i % 127;

	Events(memory, memory_size);

	delete memory;

	return 0;
}