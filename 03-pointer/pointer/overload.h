// 03-pointer.cpp : 定义控制台应用程序的入口点。
//
#ifndef __OVERLOAD_H__
#define __OVERLOAD_H__
#include<iostream>
#include <vector>
using namespace std;
//重载add函数
int  add(int a, int b);
//只有返回值不一样，形参一样，这样不能算作重载，所以编译会出问题
//float add(int c, int d);
//重载函数，要求函数同名，且形参不同，返回值可以相同可以不同。
int add(float a, int c);
#endif //__OVERLOAD_H__
