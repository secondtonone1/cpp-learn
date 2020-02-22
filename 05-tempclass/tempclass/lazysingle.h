#ifndef __LAZY_SINGLE_H__
#define __LAZY_SINGLE_H__
#include <iostream>
#include <string>
#include<memory>
#include <mutex>
using namespace std;
//����ģʽ
//����getinstance�Żᴴ����������
//ȱ�� ���߳�����²���ȫ
class LazySingle {
public:
	
	LazySingle(const LazySingle & ls) = delete;
	~LazySingle() {
		cout << "LazySingle Destructer" << endl;
		if (m_pLazySingle != nullptr) {
			//ֻ�����ÿգ����ⲿdeleteָ�룬
			//����˴�delete�ͻ�������������ݹ����
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

//����ʽ�ĸĽ���ʹ��ֻ��ָ��
class LazyAuto {
public:

	LazyAuto(const LazySingle & ls) = delete;
	
	LazyAuto & operator = (const LazySingle & ls) = delete;
	static shared_ptr<LazyAuto> GetInstance() {
		cout << "shared_ptr instance" << endl;
		if (m_pLazySingle == nullptr) {
			//����auto_make����ֱ��������Ϊ��ʱ���캯���Ѿ�Ϊ˽�У�
			//shared_ptr�޷�����˽�й��캯��
			//m_pLazySingle = make_shared<LazyAuto>();
			//�����·�ʽ��ʼ�����ȹ����LazyAutoָ��
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

//��������ʽ�����̷߳��ʻ���ְ�ȫ���⣬�������ǲ�ȡ�̼߳���
class LazySafeAuto {
public:
	
	LazySafeAuto(const LazySafeAuto & lz) = delete;
	LazySafeAuto & operator = (const LazySafeAuto & lz) = delete;
	static shared_ptr<LazySafeAuto>  GetInstance() {
		if (m_pLazySingle == nullptr) {
			lock_guard  <mutex> lk(m_mutex);
			//�ٴμ�⣬��ֹ����ǰm_pLazySingle������̳߳�ʼ��
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
