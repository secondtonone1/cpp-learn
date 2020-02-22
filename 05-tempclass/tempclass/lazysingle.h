#ifndef __LAZY_SINGLE_H__
#define __LAZY_SINGLE_H__
#include <iostream>
#include <string>
#include<memory>
#include <mutex>
using namespace std;
//懒汉模式
//调用getinstance才会创建单利对象
//缺点 多线程情况下不安全
class LazySingle {
public:
	
	LazySingle(const LazySingle & ls) = delete;
	~LazySingle() {
		cout << "LazySingle Destructer" << endl;
		if (m_pLazySingle != nullptr) {
			//只能先置空，在外部delete指针，
			//如果此处delete就会造成析构函数递归调用
			m_pLazySingle = nullptr;
		}
	}
	LazySingle & operator = (const LazySingle & ls) = delete;
	static LazySingle* GetInstance() {
		if (m_pLazySingle == nullptr) {
			m_pLazySingle = new LazySingle();
		}
		return m_pLazySingle;
	}
private:
	LazySingle() {
		cout << "LazySingle Private constructer" << endl;
	}
	static LazySingle * m_pLazySingle;
};

//懒汉式的改进，使用只能指针
class LazyAuto {
public:

	LazyAuto(const LazySingle & ls) = delete;
	
	LazyAuto & operator = (const LazySingle & ls) = delete;
	static shared_ptr<LazyAuto> GetInstance() {
		cout << "shared_ptr instance" << endl;
		if (m_pLazySingle == nullptr) {
			//调用auto_make会出现编译错误，因为此时构造函数已经为私有，
			//shared_ptr无法访问私有构造函数
			//m_pLazySingle = make_shared<LazyAuto>();
			//用如下方式初始化，先构造好LazyAuto指针
			m_pLazySingle = shared_ptr<LazyAuto>(new LazyAuto());
		}
		return m_pLazySingle;
	}
	~LazyAuto(){}
private:
	LazyAuto() {
		cout << "LazyAuto Private constructer" << endl;
	}
	static shared_ptr<LazyAuto>  m_pLazySingle;
	
};

//由于懒汉式，多线程访问会出现安全问题，所以我们采取线程枷锁
class LazySafeAuto {
public:
	
	LazySafeAuto(const LazySafeAuto & lz) = delete;
	LazySafeAuto & operator = (const LazySafeAuto & lz) = delete;
	static shared_ptr<LazySafeAuto>  GetInstance() {
		if (m_pLazySingle == nullptr) {
			lock_guard  <mutex> lk(m_mutex);
			//再次检测，防止加锁前m_pLazySingle被别的线程初始化
			if (m_pLazySingle == nullptr) {
				m_pLazySingle = shared_ptr<LazySafeAuto>(new LazySafeAuto());
			}
		}		
		return m_pLazySingle;
	}
	~LazySafeAuto(){}
private:
	LazySafeAuto() {}
	static shared_ptr<LazySafeAuto> m_pLazySingle;
	static mutex m_mutex;
};

#endif //__LAZY_SINGLE_H__
