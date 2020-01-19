#ifndef CLASS_DEMO_H_
#include <iostream>
#include <string>
class ClassDemo{
public:
	ClassDemo(std::string name, int age);
	ClassDemo();
	~ClassDemo();
	void PrintInfo();
private :
	std::string m_name;
	int m_nage;
};

#define CLASS_DEMO_H_
#endif