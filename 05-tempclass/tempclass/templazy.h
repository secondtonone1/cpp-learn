#ifndef __TEMP_LAZY_H__
#define __TEMP_LAZY_H__
#include <iostream>
#include <string>
#include<memory>
#include <mutex>
using namespace std;
//懒汉模式
//调用getinstance才会创建单利对象

template<typename T>
class TempLazy {
public:
	virtual ~TempLazy() { cout << "templazy destruct" << endl; }
	TempLazy(const TempLazy & tz) = delete;
	TempLazy & operator = (const TempLazy & tz) = delete;
	static shared_ptr<T> GetInstance() {
		if (m_pTinstance == nullptr) {
			std::lock_guard<std::mutex> lk(m_mutex);
			if (m_pTinstance == nullptr) {
				m_pTinstance = shared_ptr<T>(new T());
			}
		}
		return m_pTinstance;
	}
protected:
	TempLazy(){}
	static shared_ptr<T>  m_pTinstance;
	static mutex m_mutex;
};

//模板类静态变量再h文件中初始化
template<typename T>
shared_ptr<T>  TempLazy<T>::m_pTinstance = nullptr;

template<typename T>
mutex  TempLazy<T>::m_mutex;

#endif //__TEMP_LAZY_H__
