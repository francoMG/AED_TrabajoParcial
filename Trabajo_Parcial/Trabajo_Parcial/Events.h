#pragma once

void Events(unsigned char *memory, int memory_size, vector<var> &vars) {

	int end = false;
	string input;

	while (!end) {

		cin.clear();

		cout << "\n 1- VER SECCION DE MEMORIA"
			<< "\n 2- INGRESAR VALOR EN LA MEMORIA"
			<< "\n 3- DECLARAR ARREGLO"
			<< "\n 4- DECLARAR PUNTERO"
			<< "\n %- SALIR"
			<< "\n\n >>> ";

		cin >> input;
		
		if (input == "1") { //Ver seccion de memoria

			cout << "\nIngrese la direccion (hex): ";

			cin >> input;
			seeSection(input, memory, memory_size);
		}
		
		else if (input[0] == '2') { //Ingresar valor en la memoria
			
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
			
			tp = ((tp == 1) * sizeof(int)) + ((tp == 2) * sizeof(char)) + ((tp == 3) * sizeof(double)) +
				((tp == 4) * sizeof(float)) + ((tp == 5) * sizeof(bool));
			
			writeVar(memory, dir, (unsigned char *)&val, tp);
		}

		else if (input[0] == '3') { //Declarar arreglo
			
			string nv;
			int tp, ta, val;

			cout << "\nSeleccione el tipo de dato:\n"
				<< "\n 1- INT"
				<< "\n 2- CHAR"
				<< "\n 3- DOUBLE"
				<< "\n 4- FLOAT"
				<< "\n 5- BOOL"
				<< "\n\n >>> ";
			
			cin >> tp;

			cout << "\n Ingrese el nombre de la varible: "
				<< "\n\n >>>";
			cin >> nv;

			cout << "\n Ingrese el tamanio del arreglo: "
				<< "\n\n >>>";
			cin >> ta;
			
			tp = ((tp == 1) * sizeof(int)) + ((tp == 2) * sizeof(char)) + ((tp == 3) * sizeof(double)) +
				((tp == 4) * sizeof(float)) + ((tp == 5) * sizeof(bool));
			
			for (int i = 0; i < ta; i++) {
				
				vars.push_back(var(nv+to_string(i)), tp,selfAssign(vars));///////////////////////////////
				
				cout << "\nIngrese el valor " << i << " del arreglo: "
					<< "\n\n >>> ";
				
				cin >> val;
				writeVar(memory, vars[vars.size()-1].dir, (unsigned char *)&val, tp);
			}
		}

		else if (input[0] == '4') { //Declarar arreglo
			
			string nv;
			int tp, val;
			
			cout << "\n Ingrese el nombre de la varible: "
				<< "\n\n >>>";
			cin >> nv;

			cout << "\nSeleccione el tipo de dato:\n"
				<< "\n 1- INT"
				<< "\n 2- CHAR"
				<< "\n 3- DOUBLE"
				<< "\n 4- FLOAT"
				<< "\n 5- BOOL"
				<< "\n\n >>> ";
			cin >> tp;

			cout << "\nIngrese el valor: "
				<< "\n\n >>> ";
			cin >> val;
		}
		
		else { //Salir

			end = true;
		}
	}
}

int selfAssign(vector<var> &vars){
	
	return vars[vars.size()-1].dir + vars[vars.size()-1].tp;
}

