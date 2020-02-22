#ifndef __STARVE_SINGLE_H__
#define __STARVE_SINGLE_H__
#include <iostream>
#include <string>
using namespace std;
//饿汉式单利模式
//进程启动就创建单利资源
//缺点，空间换取时间，进程启动后就一直常驻内存，不管是否使用
//优点线程安全
//不推荐使用这种方式
class StarveSingle {
public:
	StarveSingle(const StarveSingle & t) = delete;
	
	StarveSingle & operator = ( StarveSingle & st) = delete;
	static StarveSingle*  GetInstance() {
		return &m_instance;
	}
private:
	StarveSingle(){}
	~StarveSingle(){}
	static StarveSingle m_instance;
};

#endif // __STARVE_SINGLE_H__