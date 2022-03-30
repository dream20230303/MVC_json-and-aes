#include "DataMg.h"
#include"Data.h"
#include<iostream>
#include<map>
#include<iterator>
DataMg::DataMg()
{
}

DataMg::~DataMg()
{
}

bool DataMg::add(std::map<std::string, DATA>& Mg, DATA &data)
{
    bool flag = false;
    std::string id = data.GetID();
    if (id.length() != 6) 
    { 
        std::cout << "���ʧ��" << std::endl;
        return flag; 
    }
    Mg.insert(std::make_pair(id,data));
    std::cout << "��ӳɹ�" << std::endl;
    flag = true;
    return flag;
}

bool DataMg::del(std::map<std::string, DATA>& Mg, DATA &data)
{
    bool flag = false;
    std::string id = data.GetID();
    std::map<std::string, DATA>::iterator iter;
    iter=Mg.find(id);
    if (iter != Mg.end())
    {
        Mg.erase(id);
        flag = true;
        
    }
  return flag;
}

bool DataMg::update(std::map<std::string, DATA>& Mg, DATA &data)
{
    bool flag = false;
    std::string id = data.GetID();
    std::map<std::string, DATA>::iterator iter;
    iter = Mg.find(id);
    if (iter != Mg.end())
    {
        iter->second = data; 
        flag = true;
    }
   
    return flag;
}

bool DataMg::find(std::map<std::string, DATA>& Mg, DATA &data)
{
    bool flag = false;
    std::string id = data.GetID();
    std::map<std::string, DATA>::iterator iter;
    iter = Mg.find(id);
    if (iter != Mg.end())
    {
        std::cout << "�ɹ��ҵ�" << std::endl;
        flag = true;
    }
    return flag;
}

bool DataMg::showall(std::map<std::string, DATA>& Mg, DATA& data)
{
    //std::cout << "Id" << "  " << "Name" << "  " << "Age" << "  " << "Sex" << "  " << "Department" << "  " << "Rank"
    //    << "  " << "Wage" << "  " << "WorkBeginTime" << std::endl;
    std::cout << "����" << "   " << "����" << "   " << "�Ա�" << "   " << "����" << "   " << "����" << "   " << "ְ��" << "   " << "н��" << "   " << "��ְʱ��" << std::endl;

    for ( auto p : Mg)
    {
        //std::cout << p.second.GetID() << "  " << p.second.GetName() << "  " << p.second.GetAge() << "  " << p.second.GetSex()
        //    << "  " << p.second.GetDepartment() << "  " << p.second.GetRank()
        //    << "  " << p.second.GetWage() << "  " << p.second.GetWorkBeginYear()<<"��"<<p.second.GetWorkBeginMonth()<<"��"<<p.second.GetWorkBeginday()<<"��" << std::endl;
        std::cout << p.second.GetName() << "   " << p.second.GetAge() << "   " << p.second.GetSex() << "   " << p.second.GetID() << "   " << p.second.GetDepartment() << "   "
            << p.second.GetRank() << "   " << p.second.GetWage() << "   " 
            << p.second.GetWorkBeginYear() << "��" <<p.second.GetWorkBeginMonth() << "��"<<p.second.GetWorkBeginday()<<"��"<< std::endl;

    }

    return true;
}
