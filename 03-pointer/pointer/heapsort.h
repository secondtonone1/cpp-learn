// 03-pointer.cpp : 定义控制台应用程序的入口点。
//
#ifndef __HEAPSORT_H__
#define __HEAPSORT_H__
#include<iostream>
#include <vector>
using namespace std;
class HeapSort {
public:
	HeapSort(const vector <int> & vectmp);
	HeapSort(int * n_array, int nsize);
	HeapSort();
	~HeapSort();
	void adjust_down(int nroot, int nlen);
	void adjust_heap();
	void print_data();
	void heap_sort();
private:
	void swap(int index1, int index2);
	vector<int> m_vectree;
};
#endif //__HEAPSORT_H__
