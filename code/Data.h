#ifndef DATA_H_
#define DATA_H_
#include<iostream>
class DATA
{


public:
	DATA();
	~DATA();

	std::string GetID() const;
	std::string GetName() const;
	int GetAge() const;
	std::string GetSex() const;//性别
	std::string GetDepartment()const;
	std::string GetRank()const;
	double GetWage()const;
	int GetWorkBeginYear()const;
	int GetWorkBeginMonth()const;
	int GetWorkBeginday()const;


	void SetID(std::string ID);
	void SetName(std::string NAME);
	void SetAge(int AGE);
	void SetSex(std::string SEX) ;//性别
	void SetDepartment(std::string DEPARTMENT);
	void SetRank(std::string RANK);
	void SetWage(double WAGE);
	void SetWorkBeginYear(int YEAR);
	void SetWorkBeginMonth(int MONTH);
	void SetWorkBeginday(int DAY);

	void showDataAll();
	void RankToWage();
private:
	std::string id;//工号 6位

	std::string name;//姓名
	int age;//年龄
	std::string sex;//性别

	std::string department;//部门
	std::string rank;//职级
	double wage; //工资

	//入职时间
	struct {
		int workBeginyear;
		int workBeginMonth;
		int workBeginDay;
	} workBeginTime;





};

#endif // !DATA_H_

