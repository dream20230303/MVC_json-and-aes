// PMangerSystem.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

//#define use_CRT_SECURE_NO_WARNINGS
#include <iostream>
#include"Data.h"
#include"DataMg.h"
#include"View.h"
#include<map>
#include "DataJson.h"
#include "AES.h"
#include "Base64.h"

#pragma warning(disable:4996)
using namespace std;
void inidata2(DATA& data);//for find delete
void inidata(DATA& data);


int main()
{
	View view;
	DataMg MG;
	DATA data;
	DATAJSON datajson;
	std::string pathname = "example2.json";
	std::string pathname2 = "example2.json";
	std::map<std::string, DATA> map1;

	while (1)
	{

		int temp = 0;
		view.meun();
		std::cin >> temp;
		if (temp == 1)
		{
			inidata(data);
			view.add(map1, data);


		}
		else if (temp == 2)
		{
			inidata2(data);
			view.del(map1, data);

		}
		else if (temp == 3)
		{
			inidata(data);
			view.update(map1, data);

		}
		else if (temp == 4)
		{
			inidata2(data);
			view.find(map1, data);
	
		}
		else if (temp == 5)
		{

			view.showall(map1, data);

		}
		else if (temp == 6)
		{
			datajson.readJson(data, pathname,MG,map1);
		}
		else if (temp == 7)
		{
			datajson.writeJson(data, pathname2, map1);
		}
		else if (temp == 8)
		{
		
		}
	}
	getchar();
	return 0;

}
void GetHtmlfile(std::map<std::string, DATA> map1)
{
	std::string str1 = "<html>\n";
	std::string str1 = "<body>\n";

}
void inidata(DATA& data)
{
	std::cout << "请输入" << std::endl;
	std::cout << "姓名" << "   " << "年龄" << "   " << "性别" << "   " << "工号" << "   " << "部门" << "   " << "职级" << "   " << "薪资" << "   " << "入职时间" << std::endl;

	std::string id;//工号 6位

	std::string name;//姓名
	int age;//年龄
	std::string sex;//性别

	std::string department;//部门
	std::string rank;//职级
	double wage; //工资
	int workBeginyear;
	int workBeginMonth;
	int workBeginDay;
	std::cin >> name >> age >> sex>>id>>department>>rank>>wage>>workBeginyear>>workBeginMonth>>workBeginDay;
	if (id.length() != 6)
	{
		std::cout << "error!!!,id length must equal 6" << std::endl;
	}
	else
	{
		data.SetID(id);
		data.SetName(name);
		data.SetAge(age);
		data.SetSex(sex);
		data.SetDepartment(department);
		data.SetRank(rank);
		//data.SetWage(wage);
		data.RankToWage();
		data.SetWorkBeginYear(workBeginyear);
		data.SetWorkBeginMonth(workBeginMonth);
		data.SetWorkBeginday(workBeginDay);
		data.showDataAll();
	}
}
void inidata2(DATA& data)
{
	std::cout << "请输入" << std::endl;
	std::cout <<"工号" << std::endl;

	std::string id;//工号 6位


	std::cin >>id;
	if (id.length() != 6)
	{
		std::cout << "error!!!,id length must equal 6" << std::endl;
	}
	else
	{
		data.SetID(id);
		data.showDataAll();
	}
}
// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
