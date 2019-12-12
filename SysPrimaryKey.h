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
class SysPrimaryKey
{

private:

	//Primary key of table
	int mv_PK_ID;
	int mv_Tbl_ID;
	int mv_Col_ID;

public:
	void setPK_ID(int PK_ID);
	void setTbl_ID(int col_tbl);
	void setCol_ID(int mv_col);
	int getTbl_ID();
	SysPrimaryKey(int p_tbl_id);
	SysPrimaryKey();
	~SysPrimaryKey();
};

