// lambda.cpp : �������̨Ӧ�ó������ڵ㡣
//
#include "lamclass.h"

void LamClass::PushFunc(const FuncType &funVar){
	m_funcList.push_back(funVar);
}

 bool LamClass::PopFunc(FuncType& funcVar){
	if(m_funcList.empty()) {
		return false;
	}
	funcVar = m_funcList.front();
	m_funcList.pop_front();
	return true;
}



