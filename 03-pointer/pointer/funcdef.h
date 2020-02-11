// 03-pointer.cpp : 定义控制台应用程序的入口点。
//
#ifndef __FUNCDEF_H__
#define __FUNCDEF_H__
#include<iostream>
#include <vector>
using namespace std;
//实现一个函数 ， 实现选择排序
//函数的第一个参数是指针，这样保证参数可以传入，也可以传出。
//第二个参数为数组的长度, 实现从小到大排序
extern void selectsort(int * parray, int nsize);
//冒泡排序
extern void popsort(int * parray, int nsize);
//快速排序
extern void quicksort(int * parray, int nsize);
#endif //__FUNCDEF_H__
