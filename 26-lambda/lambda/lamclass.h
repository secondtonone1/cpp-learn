// lambda.cpp : 定义控制台应用程序的入口点。
//
#ifndef _LAMCLASS_H_
#define _LAMCLASS_H_
#include <iostream>
#include <list>
#include <functional>
typedef std::function<void(int, int)> FuncType;
class LamClass {
public:
	void PushFunc(const FuncType &funVar);
	bool PopFunc(FuncType &funVar);
private:
	std::list<FuncType> m_funcList;
};

#endif //~_LAMCLASS_H_



