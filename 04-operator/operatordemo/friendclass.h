#ifndef __FRIEND_CLASS_H__
#define __FRIEND_CLASS_H__
#include <iostream>
#include <string>
using namespace std;
//实现基类
class PrivateClass {
public:
	PrivateClass() { m_nbase = 12; m_strName = "PrivateClass"; }
private:
	friend class FriendClass;
	int m_nbase;
	string m_strName;
	
};

class FriendClass {
public:
	FriendClass() { }
	void DealPrivateClass(const PrivateClass & pc);
private:
	
};
#endif   // __FRIEND_CLASS_H__

