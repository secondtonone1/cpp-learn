// 03-pointer.cpp : �������̨Ӧ�ó������ڵ㡣
//
#ifndef __VECTORARRARY_H__
#define __VECTORARRARY_H__
#include<iostream>
#include <vector>
using namespace std;

//vecarrfunc Ϊ��ͨ��ȫ�ֺ�������������ͷ�ļ��ж���
//��Ϊ������ļ�����vectorarray.h�ļ�ʱ�����ɶ��vecarrfunc��obj��������
//����������������Ȼ����vectorarray.cpp�ж��弴�ɡ�
extern void vecarrfunc();
//static ȫ�ֺ���������������ڵ�ǰ�ļ���
static void vecarrfunc2();

//��ͨ��ȫ�ֱ�����ͷ�ļ�����������cpp�ж��壬�������ֶ��obj�������⡣
//������������gnum,Ȼ����cpp�ж��塣
extern int gnum;
//int gum = 3; ��ͨ��ȫ�ֱ�����Ҫ������ͷ�ļ��У��������obj�������⡣

//static ȫ�ֱ���ҲҪ����cpp�ж��壬�������ֶ��ȫ��ʵ��
//��Ȼstatic���Է���h�ļ����壬����ÿ��������ͷ�ļ���Դ�ļ����ɵ�static������ͬ��
static int sgnum = 1024;

//Ϊ������ʵ��static����,��static�����������cpp��

#endif //__VECTORARRARY_H__
