#pragma once
#ifndef DATA_JSON_H_
#define DATA_JSON_H_
#include <iostream>
#include"Data.h"
#include"json/json.h"
#include"DataMg.h"


class DATAJSON
{
public:
	DATAJSON();
	~DATAJSON();
	void readJson(DATA& data, std::string &pathname,DataMg& Mg, std::map<std::string, DATA> &map1);
	void writeJson(DATA& data,std::string &pathname, std::map<std::string, DATA>& map1);
	
private:
	Json::Value root;
	Json::Reader reader;
	Json::StyledWriter swriter;
	struct {
		std::string name = "name";
		std::string id = "id";
		std::string property = "property";
		std::string sex = "sex";
		std::string department = "department";
		std::string rank = "rank";
		std::string age = "age";
		std::string wage = "wage";
		std::string workbegintime = "workbegintime";
		std::string workBeginyear = "workBeginyear";
		std::string workBeginmonth = "workBeginmonth";
		std::string workBeginday = "workBeginday";

	} dataS;

};





#endif