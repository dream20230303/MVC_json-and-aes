#include"DataJson.h"
#include"Data.h"
#include"DataMg.h"
#include<iostream>
#include<fstream>
#pragma warning(disable:4996)
#include"AES.h"
#include"Base64.h"
#include<sstream>
std::string EncryptionAES(const std::string& strSrc);
std::string DecryptionAES(const std::string& strSrc);
DATAJSON::DATAJSON()
{
    Json::Value root;
    Json::Reader reader;
    Json::FastWriter fwriter;
    Json::StyledWriter swriter;
}

DATAJSON::~DATAJSON()
{
}

void DATAJSON::readJson(DATA& data,std::string& pathname,DataMg &MG, std::map<std::string, DATA> &map1)
{
    std::ifstream fls(pathname);
    ostringstream os;
    os << fls.rdbuf();
   // string str1 = os.str();//查看使用
    std::string str2 = os.str();
    string str1 = DecryptionAES(str2);
    if (!reader.parse(str1, root)) {
        //parse fail
        std::cout << reader.getFormattedErrorMessages() << std::endl;

    }
    else
    {
        //readjson(root);
        //std::cout << dataIn<< std::endl;
        std::cout << "readJson" << std::endl;
        int size = root["member"].size();
        for (int i = 0; i < size; i++)
        {
            std::string name = root["member"][i][dataS.name].asString();
            std::string id = root["member"][i][dataS.id].asString();
            
            std::string sex =root["member"][i][dataS.sex].asString();
            std::string department = root["member"][i][dataS.department].asString();
            std::string rank = root["member"][i][dataS.rank].asString();
            int age = root["member"][i][dataS.age].asInt();
            double wage = root["member"][i][dataS.wage].asDouble();
            int workBeginyear = root["member"][i][dataS.workBeginyear].asInt();
            int  workBeginmonth = root["member"][i][dataS.workBeginmonth].asInt();
            int  workBeginday = root["member"][i][dataS.workBeginday].asInt();
            data.SetName(name);
            data.SetID(id);
            data.SetAge(age);
            data.SetSex(sex);
            data.SetDepartment(department);
            data.SetRank(rank);
            data.SetWorkBeginday(workBeginday);
            data.SetWorkBeginMonth(workBeginmonth);
            data.SetWorkBeginYear(workBeginyear);
            //data.SetWage(wage);
            data.RankToWage();
            data.showDataAll();
            MG.add(map1, data);
        }
        fls.close();
    }

	
}

void DATAJSON::writeJson(DATA& data,std::string& pathname2,std::map<std::string, DATA>& map1)
{
    for (auto p : map1)
    {
       static int i = 0;
       
        root["member"][i][dataS.id] = p.first;
        root["member"][i][dataS.age]=p.second.GetAge();
        root["member"][i][dataS.sex] = p.second.GetSex();
        root["member"][i][dataS.name] = p.second.GetName();
        root["member"][i][dataS.rank] = p.second.GetRank();
        root["member"][i][dataS.wage] = p.second.GetWage();
        root["member"][i][dataS.workBeginday] = p.second.GetWorkBeginday();
        root["member"][i][dataS.workBeginmonth] = p.second.GetWorkBeginMonth();
        root["member"][i][dataS.workBeginyear] = p.second.GetWorkBeginYear();
        root["member"][i][dataS.department] = p.second.GetDepartment();
        i++;
    }
    std::string str = swriter.write(root);
    std::cout << str << std::endl;
    std::string str3 = EncryptionAES(str);
    std::cout << str3 << std::endl;
    std::ofstream ofs(pathname2);
    ofs << str3;
    ofs.close();
}


/*json 文件格式
"member" :
[
  {
     "name" = "name",
     "id" = "id",
     "property" = "property",
     "sex" = "sex",
     "department" = "department",
     "rank" = "rank",
     "age" = "age",
     "wage" = "wage",
     "workbegintime" = "workbegintime",
     "workBeginyear" = "workBeginyear",
     "workBeginmonth" = "workBeginmonth",
     "workBeginday" = "workBeginday"
  },
  {
     "name" = "name",
     "id" = "id",
     "property" = "property",
     "sex" = "sex",
     "department" = "department",
     "rank" = "rank",
     "age" = "age",
     "wage" = "wage",
     "workbegintime" = "workbegintime",
     "workBeginyear" = "workBeginyear",
     "workBeginmonth" = "workBeginmonth",
     "workBeginday" = "workBeginday"





  }
]



*/

const char g_key[17] = "asdfwetyhjuytrfd";
const char g_iv[17] = "gfdertfghjkuyrtg";//ECB MODE不需要关心chain，可以填空
string EncryptionAES(const string& strSrc) //AES加密
{
    size_t length = strSrc.length();
    size_t block_num = length / BLOCK_SIZE + 1;
    //明文
    char* szDataIn = new char[block_num * BLOCK_SIZE + 1];
    memset(szDataIn, 0x00, block_num * BLOCK_SIZE + 1);
    strcpy(szDataIn, strSrc.c_str());

    //进行PKCS7Padding填充。
    int k = length % BLOCK_SIZE;
    int j = length / BLOCK_SIZE;
    int padding = BLOCK_SIZE - k;
    for (int i = 0; i < padding; i++)
    {
        szDataIn[j * BLOCK_SIZE + k + i] = padding;
    }
    szDataIn[block_num * BLOCK_SIZE] = '\0';

    //加密后的密文
    char* szDataOut = new char[block_num * BLOCK_SIZE + 1];
    memset(szDataOut, 0, block_num * BLOCK_SIZE + 1);

    //进行进行AES的CBC模式加密
    AES aes;
    aes.MakeKey(g_key, g_iv, 16, 16);
    aes.Encrypt(szDataIn, szDataOut, block_num * BLOCK_SIZE, AES::CBC);
    string str = base64_encode((unsigned char*)szDataOut,
        block_num * BLOCK_SIZE);
    delete[] szDataIn;
    delete[] szDataOut;
    return str;
}
string DecryptionAES(const string& strSrc) //AES解密
{
    string strData = base64_decode(strSrc);
    size_t length = strData.length();
    //密文
    char* szDataIn = new char[length + 1];
    memcpy(szDataIn, strData.c_str(), length + 1);
    //明文
    char* szDataOut = new char[length + 1];
    memcpy(szDataOut, strData.c_str(), length + 1);

    //进行AES的CBC模式解密
    AES aes;
    aes.MakeKey(g_key, g_iv, 16, 16);
    aes.Decrypt(szDataIn, szDataOut, length, AES::CBC);

    //去PKCS7Padding填充
    if (0x00 < szDataOut[length - 1] <= 0x16)
    {
        int tmp = szDataOut[length - 1];
        for (int i = length - 1; i >= length - tmp; i--)
        {
            if (szDataOut[i] != tmp)
            {
                memset(szDataOut, 0, length);
                cout << "去填充失败！解密出错！！" << endl;
                break;
            }
            else
                szDataOut[i] = 0;
        }
    }
    string strDest(szDataOut);
    delete[] szDataIn;
    delete[] szDataOut;
    return strDest;
}