#include "View.h"
#include"Data.h"
#include"DataMg.h"
#include<iostream>
#include<map>
#include<iterator>
View::View()
{
}

View::~View()
{
}

void View::meun()
{
	std::cout << "   菜单   " << std::endl;
	std::cout << "  1.增加  " << std::endl;
	std::cout << "  2.删除  " << std::endl;
	std::cout << "  3.修改  " << std::endl;
	std::cout << "  4.查找  " << std::endl;
	std::cout << "  5.显示  " << std::endl;
	std::cout << "  6.读取加密文件转化为json流到内存中" << std::endl;
	std::cout << "  7.将内存中的文件保存到json流，加密保存到本地" << std::endl;
	std::cout << "  8.http实现 " << std::endl;
	std::cout << "  -------删除 查找 只需填写对id即可  " << std::endl;
	std::cout << "  请输入选择的功能：  " << std::endl;
}

void View::add(std::map<std::string, DATA>& Mg, DATA& data)
{
	DataMg MG;
	MG.add(Mg, data);
}

void View::del(std::map<std::string, DATA>& Mg, DATA& data)
{
	
	DataMg MG;
	MG.del(Mg, data);

}

void View::update(std::map<std::string, DATA>& Mg, DATA& data)
{
	DataMg MG;
	MG.update(Mg, data);
}

void View::find(std::map<std::string, DATA>& Mg, DATA& data)
{
	DataMg MG;
	MG.find(Mg, data);
}

void View::showall(std::map<std::string, DATA>& Mg, DATA& data)
{
	DataMg MG;
	MG.showall(Mg, data);
}
