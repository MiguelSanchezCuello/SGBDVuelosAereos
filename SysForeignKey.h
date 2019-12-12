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
class SysForeignKey
{
private: 
	int mv_FK_ID;
	int mv_Tbl_Parent_id;
	int mv_Tbl_Child_id;
	int mv_Col_Parent_id;
	int mv_Col_Child_id;
	string mv_FK_tbl_name;

public:
	SysForeignKey();
	SysForeignKey(int table_id);
	int getFKID();
	int getTblParentID();
	int getTblChildID();
	int getColParentID();
	int getColChildID();
	string getFKTblName();
	void setFKID(int fk_id);
	void setTblParentID(int id);
	void setTblChildID(int id);
	void setColParentID(int id);
	void setColChildID(int id);
	void setFKTblName(string tbl_name);
	~SysForeignKey();
};

