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
	std::cout << "   �˵�   " << std::endl;
	std::cout << "  1.����  " << std::endl;
	std::cout << "  2.ɾ��  " << std::endl;
	std::cout << "  3.�޸�  " << std::endl;
	std::cout << "  4.����  " << std::endl;
	std::cout << "  5.��ʾ  " << std::endl;
	std::cout << "  6.��ȡ�����ļ�ת��Ϊjson�����ڴ���" << std::endl;
	std::cout << "  7.���ڴ��е��ļ����浽json�������ܱ��浽����" << std::endl;
	std::cout << "  8.httpʵ�� " << std::endl;
	std::cout << "  -------ɾ�� ���� ֻ����д��id����  " << std::endl;
	std::cout << "  ������ѡ��Ĺ��ܣ�  " << std::endl;
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
