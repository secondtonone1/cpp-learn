// 03-pointer.cpp : 定义控制台应用程序的入口点。
//

// 6， 1， 0， 5， 2， 9
// 0， 1， 6， 5，2，9
// 0， 1， 2， 5，6，9

#include "funcdef.h"

static void  printarray(int * parray, int nsize) {
	for (int i = 0; i < nsize - 1; i++) {
		cout << parray[i]<< " ";
	}
	cout << endl;
}
void selectsort(int * parray, int nsize) {
	for (int i = 0; i < nsize - 1; i++) {
		int mindex = i;
		for (int j = i+1; j < nsize - 1; j++) {
			if (parray[j] > parray[mindex]) {
				continue;
			}
			mindex = j;
		}
		int temp = parray[mindex];
		parray[mindex] = parray[i];
		parray[i] = temp;
		printarray(parray, nsize);
	}
}
