#ifndef  __STL_DEMO_H__
#define __STL_DEMO_H__
#include <memory>
#include <iostream>
#include <string>
#include <array>
using namespace std;
extern void use_array();
extern void use_vector();
extern void use_deque();
extern void use_list();
extern void use_map();
extern void use_unorderd_map();
class Hero {
public:
	Hero() { m_nAttack = 0; }
	Hero(const Hero & h) { this->m_nAttack = h.m_nAttack; }
	Hero(int nattack) { this->m_nAttack = nattack; }
	~Hero() = default;
	
	//����==�����������std::find�������Բ��ҵ�
	bool  operator == (Hero * h) {
		if (this->m_nAttack == h->m_nAttack) {
			return true;
		}
		return false;
	}

	//ʵ��һ���º�����std::sort������ÿ��Ԫ��ΪHero����
	bool operator ()(const Hero & h) {
		if (this->m_nAttack > h.m_nAttack){
			return true;
		}
	}
	
	//ʵ��һ���º�����std::sort������ÿ��Ԫ��ΪHero *����
	bool operator()(Hero * h) {
		if (this->m_nAttack > h->m_nAttack) {
			return true;
		}
	}

	friend ostream & operator <<(ostream & os, Hero * h) {
		os << "Hero attack is " << h->m_nAttack << endl;
		return os;
	}

	friend ostream & operator << (ostream & os, Hero h) {
		os << "Hero attack is " << h.m_nAttack << endl;
		return os;
	}
private:
	int m_nAttack;
};
#endif   //__STL_DEMO_H__

