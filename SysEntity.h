/*
Miguel Sanchez
CH-7491
Asignatura Estructura de Datos
Semestre 2019-2
Universidad Autonoma de Santo Domingo UASD
para mas informacion visitar mi GitHub
https://github.com/MiguelSanchezCuello
me pueden contactar a traves del correo electronico
miguelsc10@hotmail.com
o a traves del sitio web
https://www.deolink.com
*/


#pragma once
#include <string>
#include <vector>
#include "SysColumn.h"
#include "SysPrimaryKey.h"
#include "SysForeignKey.h"


using namespace std;

class SysEntity
{
public:
	SysEntity();
	SysEntity(string nombreTabla);
	~SysEntity();
	bool TablaExiste(string nameTable);
	bool ForeignKeyExiste(int tbl_id);
	// verifica si un id existe en los registros de la Entidad.
	// retorna el id del dato.
	int datoExiste(int id); 
	// Verifica si un dato existe en los registros de la Entidad.
	// retorna el id del dato.
	int datoExiste(string dato); 
	SysColumn cols;
	SysForeignKey forkeys;
	void Alta(std::vector<std::string> data); // Enviar a Tabla.csv
	vector<string> registros;
	void verRegistros();

private:
	string nombreEntidad;
	int mv_tbl_ID; // Guarda el ID de la tabla
	string mv_action_Msj;
	vector<string> getSplit(const string &p_string, char p_delim);
	void CargarColumnas();
	// Almacena las columnas de la Entidad.
	vector<SysColumn> objAllCols;
	// Almacena todas las llaves foraneas de la Entidad.
	vector<SysForeignKey> objAllFk;
	
	vector<string> PrepararData(); // prepara la data a ingresar de alta
	vector<string> dataAlta; // vector que contiene la data a la cual se dara alta.
	void obtenerRegistros();// carga los registros al archivo
	
	void CargarForeignKeys();
	void CargarPrimaryKey();
	// Representacion de la llave primaria de la Entidad.
	SysPrimaryKey objPk;

};

