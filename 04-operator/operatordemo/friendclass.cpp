#include "friendclass.h"
void FriendClass::DealPrivateClass(const PrivateClass & pc) {
	cout << "PrivateClass base is " << pc.m_nbase << endl;
	cout << "PrivateClass strname is " << pc.m_strName << endl;
}