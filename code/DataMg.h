#ifndef DATAMG_H_
#define DATAMG_H_
#include"Data.h"
#include<iostream>
#include<map>
class DataMg
{
public:
	DataMg();
	~DataMg();
	//ÔöÉ¾¸Ä²é
	bool add(std::map<std::string,DATA> &Mg,DATA &data);
	bool del(std::map<std::string, DATA>& Mg, DATA &data);
	bool update(std::map<std::string, DATA>& Mg, DATA &data);
	bool find(std::map<std::string, DATA>& Mg, DATA &data);
	bool showall(std::map<std::string, DATA>& Mg, DATA& data);

private:

};
#endif // !DATAMG_H_
