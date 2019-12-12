#include "SysColumn.h"


using namespace std;

SysColumn::SysColumn()
{
}


SysColumn::~SysColumn()
{
}

void SysColumn::SetTblID(int tbl_id)
{
	this->mv_tbl_ID = tbl_id;
}

int SysColumn::GetTblID()
{
	return mv_tbl_ID;
}

void SysColumn::setColumnID(int col_id)
{
	this->mv_col_ID = col_id;
}

string SysColumn::GetColumnName()
{
	return mv_col_name;
}

void SysColumn::SetColumnName(string col_name)
{
	this->mv_col_name = col_name;
}

string SysColumn::GetDataType()
{
	return mv_col_tipo;
}

void SysColumn::SetDataType(string DataType)
{
	this->mv_col_tipo = DataType;
}

void SysColumn::SetLength(string length)
{
	this->mv_col_len = stoi(length);
}

string SysColumn::GetLength()
{
	return to_string(mv_col_len);
}

void SysColumn::setRequerido(string requerido)
{
	// False, que no puede ser nulo, por ende es requerido True.
	if (requerido == "FALSE")
	{
		this->mv_ind_require = true;
	} else
	{
		this->mv_ind_require = false;
	}
	

}

string SysColumn::GetRequerido()
{
	string aux = "TRUE";
	if (mv_ind_require == true) {
		aux = "FALSE";
	}
	return aux;
}

int SysColumn::getColID()
{
	return mv_col_ID;
}
