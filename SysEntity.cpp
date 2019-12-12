#include "SysEntity.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;
// Constructor que recibe el nombre de la tabla para crear la Entidad.
SysEntity::SysEntity(string nombreTabla)
{
	// Lo primero que debe hacer es verificar si la tabla existe.
	if (TablaExiste(nombreTabla))
	{
		
		// Si existe carga los atributos de la Entidad.
		CargarColumnas();
		CargarPrimaryKey();

		if (ForeignKeyExiste(mv_tbl_ID)) {
			CargarForeignKeys(); // Carga las llaves Foraneas de la Entidad.
		}
		obtenerRegistros();
		//verRegistros();
		int val = 0;
		/*cout << "\nIngresar datos a esta Entidad?\n\t1-Si\n\tCualquier otro dato - No\n";
		cin >> val;
		if (val == 1) {
			//dataAlta = PrepararData(); // Prepara la data a ser ingresada
			//this->Alta(dataAlta);
		}*/
		
	};
}

SysEntity::~SysEntity() {} // Destructor


// Metodo que verifica la existencia de la tabla.
bool SysEntity::TablaExiste(string nombreTabla)
{	
	mv_action_Msj = "La tabla no existe"; // Hasta ahora la variable no se esta utilizando BORRAR MAS TARDE
	ifstream reads("..\\SGBDMiguelSanchez\\SysFiles\\SysTable.csv", ios::in);
	string temp;
	//Para leer el encabezado del archivo(Que no es la data)
	getline(reads, temp);
	ifstream subLector(temp);//A este punto la variable Temp tiene la primera linea.
	vector<string> allTableNames;
	
	// Lee desde la segunda linea del archivo, separa los campos y va agregando
	// al vector todos los nombres de tablas (allTableNames).
	while (reads) {
		reads >> temp;
		vector<string> aux;
		aux = getSplit(temp, ',');
		allTableNames.push_back(aux[1]);
	}

	// Itera el vector de todas las tablas y lo compara con la tabla ingresada.
	for (int i = 0; i < allTableNames.size(); i++)	{
		if (allTableNames[i] == nombreTabla) {
			//Para tener disponible el ID de la tabla
			mv_tbl_ID = i + 1;
			

			// Cierre de los streams de lectura.
			subLector.close(); 
			reads.close();
			nombreEntidad = nombreTabla;
			return true;
		}
	}
	// Cierre de los streams de lectura.
	subLector.close();
	reads.close();
	return false;
} // Fin del metodo TablaExiste.

// Metodo que recibe una cadena, separada con un caracter especial y devuelve un vector de los elementos separados.
vector<string> SysEntity::getSplit(const string &p_string, char p_delim){
	vector<string> result;
	stringstream ss(p_string);
	string item;
	while (getline(ss, item, p_delim)){
		//item.pop_back(); Fallido
		result.push_back(item);
	}
	return result;
} // Fin del metodo getSplit.

// Metodo que carga todas las columnas de la entidad.
void SysEntity::CargarColumnas(){

	ifstream reader("..\\SGBDMiguelSanchez\\SysFiles\\SysColumn.csv", ios::in);
	string temp;
	//Read the headders of the files
	ifstream subLector(temp);//read actual line 
	getline(reader, temp);
	string auxiliar;
	//Read of files
	while (reader)
	{
		reader >> temp;
		vector<string> aux;
		aux = getSplit(temp, ',');

		cols.SetTblID(stoi(aux[0]));
		cols.setColumnID(stoi(aux[1]));
		cols.SetColumnName(aux[2]);
		cols.SetDataType(aux[3]);
		cols.SetLength(aux[4]);
		cols.setRequerido(aux[5]);

		if (this->mv_tbl_ID == cols.GetTblID())
		{
			objAllCols.push_back(cols);
		}
		//break;
	}
	
	subLector.close();
} // Fin del metodo que carga las columnas de la entidad.

// Metodo que carga la llave primaria de la entidad.
void SysEntity::CargarPrimaryKey()
{
	ifstream reader("..\\SGBDMiguelSanchez\\SysFiles\\SysPrimaryKey.csv", ios::in);
	string temp;
	//Read the headders of the files
	ifstream subLector(temp);//read actual line 
	getline(reader, temp);
	string auxiliar;
	//Read of files
	while (reader)
	{
		reader >> temp;
		vector<string> aux;
		aux = getSplit(temp, ',');

		objPk.setTbl_ID(stoi(aux[1]));

		if (this->mv_tbl_ID == objPk.getTbl_ID())
		{
			objPk.setPK_ID(stoi(aux[0]));
			objPk.setCol_ID(stoi(aux[2]));
			break;	
		}
	}
	subLector.close();
} // Fin del metodo que carga la llave primaria.


// Metodo que verifica la existencia de llaves foraneas en la tabla.
bool SysEntity::ForeignKeyExiste(int tbl_id)
{
	mv_action_Msj = "Esta tabla no tiene llaves foraneas."; // Hasta ahora la variable no se esta utilizando BORRAR MAS TARDE
	ifstream reads("..\\SGBDMiguelSanchez\\SysFiles\\SysForeignKey.csv", ios::in);
	string temp;
	//Para leer el encabezado del archivo(Que no es la data)
	getline(reads, temp);
	ifstream subLector(temp);//A este punto la variable Temp tiene la primera linea.
	vector<string> allForeignKeys;

	// Lee desde la segunda linea del archivo, separa los campos y va agregando
	// al vector todos las llaves foraneas (allForeignKeys).
	while (reads) {
		reads >> temp;
		vector<string> aux;
		aux = getSplit(temp, ',');
		allForeignKeys.push_back(aux[1]);
		// Recordemos que en cada linea del archivo
		// 0 = FKID, 1 = TablaHija, 2 =ColHija, 3= TablaPadre, 4= ColPadre, 5= FKNombre.
		// Tomamos el campo tabla hija para comparar y si es hija en alguna otra tabla significa 
		// que el primarykey de la otra tabla esta en esta tabla como foreignkey.
	}

	// Itera el vector de todas las claves foraneas y lo compara con la tabla ingresada.
	for (int i = 0; i < allForeignKeys.size(); i++) {
		if (stoi(allForeignKeys[i]) == tbl_id) {
			//Solo para saber que existe.
			// Cierre de los streams de lectura.
			subLector.close();
			reads.close();
			return true;
		}
	}
	// Cierre de los streams de lectura.
	subLector.close();
	reads.close();
	cout << "\nNo tiene llaves foraneas";
	return false;
} // Fin del metodo ForeignKeyExiste.


// Prepara el vector de datos a ser ingresados en el alta.
/*vector<string> SysEntity::PrepararData()
{
	vector<string> data;
	string value;
	for (int i = 0; i < objAllCols.size(); i++) {
		cout << "Ahora ingresaremos el dato para " + objAllCols[i].GetColumnName() + ", debe ingresar un dato tipo \""+ objAllCols[i].GetDataType()+"\""
			+", la longitud maxima de caracteres es: "+ objAllCols[i].GetLength() + ", ¿Es el dato obligatorio?: " + objAllCols[i].GetRequerido() + ".\n";
		cin >> value;

		for (int m = 0; m < objAllFk.size(); m++) {
			// Si el ID almacenado en la columna es igual a un IDColHijo en los FKs de la entidad.
			// entonces es el campo coincidente. La relacion FK en esta tabla y Padre en la otra se cumple.
			//if (objAllCols[i].getColID() == objAllFk[m].getColChildID) { 
				//SysEntity aux(objAllFk[m].getTblParentID);
				// recibe el id de la tabla para crear la entidad y llenar el vector de registros.
				// luego ha de tomar el nombre del FK y buscara en el vector, donde la columna tenga el nombre de la columna que se esta trabajando
				// y verificara si el dato existe, si existe retorna el id, si no existe( se podria iniciar un proceso de alta ).

			}
		}
		
		
		
		
		data.push_back(value);
	}

	//return data;
}*/

void SysEntity::obtenerRegistros()
{
	ifstream reader("..\\SGBDMiguelSanchez\\SysFiles\\Tablas\\"+ nombreEntidad +".csv", ios::in);
	string temp;
	//Read the headders of the files
	ifstream subLector(temp);//read actual line 
	getline(reader, temp);
	string auxiliar;
	//Read of files
	while (reader)
	{
		reader >> temp;

		// Agrega la cadena sin split al vector de registros.
		registros.push_back(temp);	
	}
	subLector.close();
}

void SysEntity::verRegistros()
{
	for (int i = 0; i < objAllCols.size(); i++) {
		cout << objAllCols[i].GetColumnName() << '\t';
	}
	cout << endl;
	for (int i = 0; i < registros.size() -1; i++) {
		vector<string> aux = getSplit(registros[i], ',');
		
		for (int j = 0; j < aux.size(); j++)
			cout << aux[j] << '\t';
		cout << endl;
	}
}

// Metodo que carga todas las llaves foraneas de la entidad.
void SysEntity::CargarForeignKeys() {

	ifstream reader("..\\SGBDMiguelSanchez\\SysFiles\\SysForeignKey.csv", ios::in);
	string temp;
	//Read the headders of the files
	ifstream subLector(temp);//read actual line 
	getline(reader, temp);
	string auxiliar;
	//Read of files
	while (reader)
	{
		reader >> temp;
		vector<string> aux;
		aux = getSplit(temp, ',');

		forkeys.setFKID(stoi(aux[0]));
		forkeys.setTblChildID(stoi(aux[1]));
		forkeys.setColChildID(stoi(aux[2]));
		forkeys.setTblParentID(stoi(aux[3]));
		forkeys.setColParentID(stoi(aux[4]));
		forkeys.setFKTblName(aux[5]);
		
		// Recordemos que en cada linea del archivo
		// 0 = FKID, 1 = TablaHija, 2 =ColHija, 3= TablaPadre, 4= ColPadre, 5= FKNombre.
		// Tomamos el campo hija para comparar y si es hija en alguna otra tabla significa 
		// que el primarykey de la otra tabla esta en esta tabla como foreignkey.
		
		if (this->mv_tbl_ID == forkeys.getTblChildID())
		{
			objAllFk.push_back(forkeys);
		}
		//break;
	}
	subLector.close();
} // Fin del metodo que carga las llaves foraneas.


// Metodo para dar alta al vector de data
void SysEntity::Alta(vector<string> data)
{
	ofstream archivo;
	string fileLocation = "..\\SGBDMiguelSanchez\\SysFiles\\Tablas\\";
	archivo.open(fileLocation + this->nombreEntidad + ".csv", std::ios::out | std::ios::app);

	string auxString;
	if (!archivo.fail()) {
		for (int i = 0; i < data.size(); ++i) {
			auxString += data[i] + ",";
		}
		auxString.pop_back();
		archivo << auxString << "\n";
	}
	archivo.close();
	registros.clear();
	obtenerRegistros();
} 