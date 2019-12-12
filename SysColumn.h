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
using namespace std;
class SysColumn
{
public:
	SysColumn();
	~SysColumn();
	void SetTblID(int tbl_id);
	int GetTblID();
	void setColumnID(int col_id);
	string GetColumnName();
	void SetColumnName(string col_name);
	string GetDataType();
	void SetDataType(string DataType);
	void SetLength(string length);
	string GetLength();
	void setRequerido(string requerido);
	string GetRequerido();
	int getColID();

private:
	int mv_col_ID;
	int mv_tbl_ID;
	short int mv_col_orden;
	string mv_col_name;
	string mv_col_tipo;
	int mv_col_len;
	bool mv_ind_require;
};

