#include "XFtpUSER.h"
#include <iostream>
using namespace std;
//解析协议
void XFtpUSER::Parse(std::string type, std::string msg)
{
	cout << "XFtpUSER::Parse " << type << " " << msg << endl;
	ResCMD("230 login successful.\r\n");
}