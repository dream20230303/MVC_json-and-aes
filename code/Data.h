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
	std::string GetSex() const;//�Ա�
	std::string GetDepartment()const;
	std::string GetRank()const;
	double GetWage()const;
	int GetWorkBeginYear()const;
	int GetWorkBeginMonth()const;
	int GetWorkBeginday()const;


	void SetID(std::string ID);
	void SetName(std::string NAME);
	void SetAge(int AGE);
	void SetSex(std::string SEX) ;//�Ա�
	void SetDepartment(std::string DEPARTMENT);
	void SetRank(std::string RANK);
	void SetWage(double WAGE);
	void SetWorkBeginYear(int YEAR);
	void SetWorkBeginMonth(int MONTH);
	void SetWorkBeginday(int DAY);

	void showDataAll();
	void RankToWage();
private:
	std::string id;//���� 6λ

	std::string name;//����
	int age;//����
	std::string sex;//�Ա�

	std::string department;//����
	std::string rank;//ְ��
	double wage; //����

	//��ְʱ��
	struct {
		int workBeginyear;
		int workBeginMonth;
		int workBeginDay;
	} workBeginTime;





};

#endif // !DATA_H_

