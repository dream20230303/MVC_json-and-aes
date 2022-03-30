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
        std::cout << "添加失败" << std::endl;
        return flag; 
    }
    Mg.insert(std::make_pair(id,data));
    std::cout << "添加成功" << std::endl;
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
        std::cout << "成功找到" << std::endl;
        flag = true;
    }
    return flag;
}

bool DataMg::showall(std::map<std::string, DATA>& Mg, DATA& data)
{
    //std::cout << "Id" << "  " << "Name" << "  " << "Age" << "  " << "Sex" << "  " << "Department" << "  " << "Rank"
    //    << "  " << "Wage" << "  " << "WorkBeginTime" << std::endl;
    std::cout << "姓名" << "   " << "年龄" << "   " << "性别" << "   " << "工号" << "   " << "部门" << "   " << "职级" << "   " << "薪资" << "   " << "入职时间" << std::endl;

    for ( auto p : Mg)
    {
        //std::cout << p.second.GetID() << "  " << p.second.GetName() << "  " << p.second.GetAge() << "  " << p.second.GetSex()
        //    << "  " << p.second.GetDepartment() << "  " << p.second.GetRank()
        //    << "  " << p.second.GetWage() << "  " << p.second.GetWorkBeginYear()<<"年"<<p.second.GetWorkBeginMonth()<<"月"<<p.second.GetWorkBeginday()<<"日" << std::endl;
        std::cout << p.second.GetName() << "   " << p.second.GetAge() << "   " << p.second.GetSex() << "   " << p.second.GetID() << "   " << p.second.GetDepartment() << "   "
            << p.second.GetRank() << "   " << p.second.GetWage() << "   " 
            << p.second.GetWorkBeginYear() << "年" <<p.second.GetWorkBeginMonth() << "月"<<p.second.GetWorkBeginday()<<"日"<< std::endl;

    }

    return true;
}
