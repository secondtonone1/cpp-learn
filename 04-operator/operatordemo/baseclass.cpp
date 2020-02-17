#include "baseclass.h"
//static 变量放在cpp中初始化
int BaseClass::m_snum = 230;

void BaseClass::PrintClassData() {
	cout << "Hello , this is BaseClass" << endl;
}


void BaseClass::Overloadf() {
	cout << "Hello, this is BaseClass Overload" << endl;
}

void BaseClass::BaseExec() {
	PrintClassData();
	Overloadf();
}

void BaseClass::NetWork() {
	cout << "This is BaseClass NetWork()" << endl;
}
void BaseClass::GreetClient(std::string str) {
	cout << "This is BaseClass GreetClient(str)" << endl;
}

void BaseClass::BaseC11() {
	cout << "This is BaseClass final BaseC11" << endl;
}

void BaseClass::OverrideC11() {
	cout << "This is BaseClass override" << endl;
}

void DeriveClass::PrintClassData() {
	cout << "Hello, this is DeriveClass " << endl;
}

void DeriveClass::Overloadf() {
	cout << "Hello, this is DeriveClass Overload" << endl;
}

void DeriveClass::NetWork(int m) {
	cout << "This is DeriveClass NetWork(int m)" << endl;
 }
void DeriveClass::GreetClient(int id) {
	cout << "This is DeriveClass GreetClient(int)" << endl;
}

void DeriveClass::CallBaseGreetClient(string  str) {
	BaseClass::GreetClient(str);
}

void DeriveClass::OverrideC11() {
	cout << "This is DeriveClass override" << endl;
}

