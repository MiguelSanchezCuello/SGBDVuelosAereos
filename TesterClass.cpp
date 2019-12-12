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
