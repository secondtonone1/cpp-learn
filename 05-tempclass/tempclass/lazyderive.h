#ifndef __LAZY_DERIVE_H__
#define __LAZY_DERIVE_H__
#include <iostream>
#include <string>
#include<memory>
#include <mutex>
#include "templazy.h"
using namespace std;
//����ģʽ
//����getinstance�Żᴴ����������
//ȱ�� ���߳�����²���ȫ
class LazyDerive: public TempLazy<LazyDerive>{
public:
	friend class TempLazy<LazyDerive>;
	LazyDerive(const LazyDerive & ld) = delete;
	LazyDerive& operator = (const LazyDerive & ld) = delete;
	~LazyDerive() {}
private:
	LazyDerive() = default;
};


#endif //__LAZY_DERIVE_H__
