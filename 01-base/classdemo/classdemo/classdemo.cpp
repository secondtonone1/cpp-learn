#include "stdafx.h"
#include "classdemo.h"
using namespace std;
ClassDemo::ClassDemo(std::string name, int age){
	std::cout << "call param construct ClassDemo " <<std::endl;
	m_name = name;
	m_nage = age;
}

ClassDemo::ClassDemo(){
	std::cout << "call no param construct ClassDemo " <<std::endl;
	m_nage = 0;
	m_name = "";
}

ClassDemo::~ClassDemo(){
	std::cout <<"call destruct ClassDemo"<<std::endl;
}

void ClassDemo::PrintInfo(){
	std::cout << "name is " << m_name <<endl;
	std::cout << "age is " << m_nage <<endl;
}


