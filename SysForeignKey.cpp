#include "SysForeignKey.h"



SysForeignKey::SysForeignKey()
{
}

int SysForeignKey::getFKID()
{
	return mv_FK_ID;
}

int SysForeignKey::getTblParentID()
{
	return mv_Tbl_Parent_id;
}

int SysForeignKey::getTblChildID()
{
	return mv_Tbl_Child_id;
}

int SysForeignKey::getColParentID()
{
	return mv_Col_Parent_id;
}

int SysForeignKey::getColChildID()
{
	return mv_Col_Child_id;
}

string SysForeignKey::getFKTblName()
{
	return mv_FK_tbl_name;
}

void SysForeignKey::setFKID(int fk_id)
{
	this->mv_FK_ID = (fk_id);
}

void SysForeignKey::setTblParentID(int id)
{
	this->mv_Tbl_Parent_id = id;
}

void SysForeignKey::setTblChildID(int id)
{
	this->mv_Tbl_Child_id = id;
}

void SysForeignKey::setColParentID(int id)
{
	this->mv_Col_Parent_id = id;
}

void SysForeignKey::setColChildID(int id)
{
	this->mv_Col_Child_id = id;
}

void SysForeignKey::setFKTblName(string tbl_name)
{
	this->mv_FK_tbl_name = tbl_name;
}


SysForeignKey::~SysForeignKey()
{
}
