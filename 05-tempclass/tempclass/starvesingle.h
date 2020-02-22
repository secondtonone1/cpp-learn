#ifndef __STARVE_SINGLE_H__
#define __STARVE_SINGLE_H__
#include <iostream>
#include <string>
using namespace std;
//����ʽ����ģʽ
//���������ʹ���������Դ
//ȱ�㣬�ռ任ȡʱ�䣬�����������һֱ��פ�ڴ棬�����Ƿ�ʹ��
//�ŵ��̰߳�ȫ
//���Ƽ�ʹ�����ַ�ʽ
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