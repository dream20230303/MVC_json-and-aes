#ifndef VIEW_H_
#define VIEW_H_
#include<map>
#include<iostream>
#include"Data.h"
#include"DataMg.h"

class View
{
public:
	View();
	~View();

	void meun();

	void add(std::map<std::string, DATA>& Mg, DATA& data);
	void del(std::map<std::string, DATA>& Mg, DATA& data);
	void update(std::map<std::string, DATA>& Mg, DATA& data);
	void find(std::map<std::string, DATA>& Mg, DATA& data);
	void showall(std::map<std::string, DATA>& Mg, DATA& data);
};

#endif // !VIEW_H_
