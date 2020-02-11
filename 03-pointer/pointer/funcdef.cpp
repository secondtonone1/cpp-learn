// 03-pointer.cpp : 定义控制台应用程序的入口点。
//

// 6， 1， 0， 5， 2， 9
// 0， 1， 6， 5，2，9
// 0， 1， 2， 5，6，9

#include "funcdef.h"

static void  printarray(int * parray, int nsize) {
	for (int i = 0; i < nsize ; i++) {
		cout << parray[i]<< " ";
	}
	cout << endl;
}
//选择排序
void selectsort(int * parray, int nsize) {
	for (int i = 0; i < nsize ; i++) {
		int mindex = i;
		for (int j = i+1; j < nsize ; j++) {
			if (parray[j] > parray[mindex]) {
				continue;
			}
			mindex = j;
		}
		if (i == mindex) {
			continue;
		}
		int temp = parray[mindex];
		parray[mindex] = parray[i];
		parray[i] = temp;
		printarray(parray, nsize);
	}
}

//6 ，1， 0， 5， 2， 9
//1 ,  0,    5,   2,    6,   9
//0,   1,    2,   5,    6,   9
//冒泡排序
void popsort(int *parray, int nsize) {
	for (int i =0; i < nsize; i++)
		for (int j = 0; j < nsize - 1 - i; j++) {
			if (parray[j] <= parray[j + 1]) {
				continue;
			}
			int temp = parray[j];
			parray[j] = parray[j + 1];
			parray[j + 1] = temp;
		}
	printarray(parray, nsize);
}

//快速排序
//9, 5, 2, 7, 1, 6, 11
//先从右向左，找到第一个比9小的元素6，然后6，9交换位置
//6, 5, 2, 7, 1, 9, 11
//然后从左向右，从元素5开始，找比9大的元素，然后交换位置，目前没发现比9大的。
//这样9的左边都是比9小的元素，9的右边都是比9大的元素。
//然后以此类推，分别用这个办法将9左右两边的元素分别排序即可。
extern void subsort(int * parray, int nleft, int nright);
void quicksort(int * parray, int nsize) {
	if (nsize <= 0) {
		return;
	}
	int nleft = 0;
	int nright = nsize - 1;
	subsort(parray, nleft, nright);
	printarray(parray, nsize);
}

static void subsort(int * parray, int nleft, int nright ) {
	int nbegin = nleft;
	int nend = nright;
	for (; nbegin < nend; ) {
		for (; nbegin < nend;) {
			if (parray[nend] > parray[nbegin]) {
				nend--;
				continue;
			}
			int temp = parray[nend];
			parray[nend] = parray[nbegin];
			parray[nbegin] = temp;
		}

		for (; nbegin < nend;) {
			if (parray[nbegin] < parray[nend]) {
				nbegin++;
				continue;
			}
			int temp = parray[nbegin];
			parray[nbegin] = parray[nend];
			parray[nend] = temp;
		}
	}
	
	//cout << parray[nbegin] << endl;
	if (nleft < nend - 1) {
		subsort(parray, nleft, nend - 1);
	}
	
	if (nend + 1 < nright) {
		subsort(parray, nend + 1, nright);
	}
	
}

//9, 5, 7, 12, 4, 2, 8, 11
//8, 5, 7, 12, 4, 2, 9, 11
//8, 5, 7,  9,  4, 2, 12, 11
//8, 5, 7,  2 , 4, 9, 12, 11