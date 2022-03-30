#include"Data.h"
#include<iostream>
DATA::DATA()
{
	id = -1;
}
DATA::~DATA()
{

}

std::string DATA::GetID() const
{
	return id;
}
std::string DATA::GetName() const
{
	return name;
}
int DATA::GetAge() const
{
	return age;
}

std::string  DATA::GetSex() const
{
	return sex;
}
std::string  DATA::GetDepartment()const
{
	return department;
}
std::string  DATA::GetRank()const
{
	return rank;
}
double  DATA::GetWage()const
{
	return wage;
}
int  DATA::GetWorkBeginYear()const
{
	return workBeginTime.workBeginyear;
}
int  DATA::GetWorkBeginMonth()const
{
	return workBeginTime.workBeginMonth;
}
int  DATA::GetWorkBeginday()const
{
	return workBeginTime.workBeginDay;
}





void DATA::SetID(std::string ID)
{
	id = ID;
}
void DATA::SetName(std::string NAME )
{
	name = NAME;
}
void DATA::SetAge(int AGE)
{
	age = AGE;
}
void DATA::SetSex(std::string SEX)
{
	sex = SEX;
}
void DATA::SetDepartment(std::string DEPARTMENT)
{
	department = DEPARTMENT;
}
void DATA::SetRank(std::string RANK)
{
	rank = RANK;
}
//void DATA::SetWage(double WAGE)
//{
//	wage = WAGE;
//}
void DATA::SetWorkBeginYear(int YEAR)
{
	workBeginTime.workBeginyear = YEAR;
}
void DATA::SetWorkBeginMonth(int MONTH)
{
	workBeginTime.workBeginMonth = MONTH;
}
void DATA::SetWorkBeginday(int DAY)
{
	workBeginTime.workBeginDay = DAY;
}

void DATA::showDataAll()
{
	std::cout << "姓名" << "   " << "年龄" << "   " << "性别" << "   " << "工号" << "   " << "部门" << "   " << "职级" << "   " << "薪资" << "   " << "入职时间" << std::endl;
	std::cout << name << "   " << age << "   " << sex << "   " << id << "   " << department << "   " << rank << "   " << wage << "   " << workBeginTime.workBeginyear<<"年" 
		<<workBeginTime.workBeginMonth<<"月"<<workBeginTime.workBeginDay<<"日" << std::endl;
}

void DATA::RankToWage()
{
	if (rank == "common") { wage = 1000; }
	else if (rank == "manager"){wage = 2000;}
	else 
	{
		std::cout << "rank error ！ you must input common or manager" << std::endl;
	}

}