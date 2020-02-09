// 03-pointer.cpp : 定义控制台应用程序的入口点。
//
#ifndef __VECTORARRARY_H__
#define __VECTORARRARY_H__
#include<iostream>
#include <vector>
using namespace std;

//vecarrfunc 为普通的全局函数，不可以在头文件中定义
//因为当多个文件包含vectorarray.h文件时会生成多个vecarrfunc的obj链接问题
//所以这里先声明，然后在vectorarray.cpp中定义即可。
extern void vecarrfunc();
//static 全局函数，作用域仅限于当前文件。
static void vecarrfunc2();

//普通的全局变量在头文件中声明，在cpp中定义，否则会出现多个obj链接问题。
//在这里声明下gnum,然后在cpp中定义。
extern int gnum;
//int gum = 3; 普通的全局变量不要定义在头文件中，产生多个obj链接问题。

//static 全局变量也要放在cpp中定义，否则会出现多个全局实例
//虽然static可以放在h文件定义，但是每个包含该头文件的源文件生成的static变量不同。
static int sgnum = 1024;

//为避免多个实例static变量,将static变量定义放在cpp中

#endif //__VECTORARRARY_H__
