#include "XFtpPORT.h"
#include <vector>
#include <iostream>
using namespace std;
//解析协议
void XFtpPORT::Parse(std::string type, std::string msg)
{
	//PORT 127,0,0,1,70,96\r\n
	//PORT n1,n1,n3,n4,n5,n6\r\n
	//prot = n5*256 + n6;
	
	// 只获取ip和端口，不连接
	//去除ip
	string tmp = "";
	vector<string> vals;
	for(int i = 5; i < msg.size(); i++)
	{
		if(msg[i] == ',' || msg[i] == '\r')
		{
			vals.push_back(tmp);
			tmp = "";
			continue;
		}
		tmp += msg[i];
	}
	if(vals.size() != 6)
	{
		//PROT格式有误
		ResCMD("501 Syntax error in parameters or arguments.");
		return;
	}
	ip = vals[0] + "." + vals[1] + "." + vals[2] + "." + vals[3];
	//prot = n5*256 + n6;
	port = atoi(vals[4].c_str()) * 256 + atoi(vals[5].c_str());
	cout << "Port ip is " << ip << endl;
	cout << "Port port is " << port << endl;
	ResCMD("200 PORT command successful.\r\n");
};


