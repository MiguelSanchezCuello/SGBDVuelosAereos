/* Esta clase sirve para hacer pruebas. El sistema es un trabajo en progreso
 La prueba desplegada consiste en:
 - Crear una Entidad en memoria "Tique" y crear un vector que contiene la data de un registro
   enviar el vector de data a la entidad como un Alta.
 Lo que hace el programa durante la prueba:
 - Carga la Entidad Tique en memoria leyendo la informacion desde los archivos 
 	SysTable.csv, 
	SysColumn.csv, 
	SysPrimaryKey.csv y 
	SysForeignKey.csv
   define la Entidad y manipula la funcionalidad del tipo en memoria.
 - Para dar el alta el programa busca la Tabla especifica de la entidad en el subfolder Tablas
 - Para leer los datos el programa hace las verificaciones especificas de entidad y busca las tablas
   y muestra los registros pertenecientes a la entidad. 
   
*/ 

#pragma once
#include "TesterClass.h"
#include "SysEntity.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
	//cout << "Hola mundo";
	vector<string> dataTest;
	string data;
	SysEntity entidad("Tique");

	
	cout << "Bienvenido al sistema de vuelos aereos" << endl;
	cout << "En esta fase de pruebas vamos a dar un alta a Tique: " << endl;
	cout << "Ingrese el ID del Tique: " << endl;;
	getline(cin, data);
	dataTest.push_back(data);
	cout << "Ingrese La fecha del tique: " << endl;
	getline(cin, data);
	dataTest.push_back(data);
	cout << "Ingrese el numero de asiento: "<< endl;
	getline(cin, data);
	dataTest.push_back(data);
	cout << "La Clase: " << endl;
	getline(cin, data);
	dataTest.push_back(data);
	cout << "Ingrese el ID del pasajero: " << endl;
	getline(cin, data);
	dataTest.push_back(data);
	cout << "Ingrese el ID del vuelo: " << endl;
	getline(cin, data);
	dataTest.push_back(data);

	cout << "ingresando los datos en la tabla de registros de la entidad." << endl;
	entidad.Alta(dataTest);
	
	cout << endl << "AHORA SE MUESTRAN LOS REGISTROS ALMACENADOS" << endl;
	entidad.verRegistros();




	/*
	
	dataTest.push_back("4");
	dataTest.push_back("00112345651");
	dataTest.push_back("Oscar Martinez");
	dataTest.push_back("RD556531");
	dataTest.push_back("4");

	entidad.Alta(dataTest);
	*/
	
	int test;

	/*
	vector<string> prueba;
	prueba.push_back("3");
	prueba.push_back("22412345651");
	prueba.push_back("Jose");
	prueba.push_back("Sanchez");
	prueba.push_back("RD6544515");
	prueba.push_back("3");
	entidad.Alta(prueba);
	*/
	cin >> test; // Para pausar durante pruebas

}

TesterClass::TesterClass()
{
}


TesterClass::~TesterClass()
{
}
