#ifndef __LAZY_DERIVE_H__
#define __LAZY_DERIVE_H__
#include <iostream>
#include <string>
#include<memory>
#include <mutex>
#include "templazy.h"
using namespace std;
//懒汉模式
//调用getinstance才会创建单利对象
//缺点 多线程情况下不安全
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
