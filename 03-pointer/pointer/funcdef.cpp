// 03-pointer.cpp : �������̨Ӧ�ó������ڵ㡣
//

// 6�� 1�� 0�� 5�� 2�� 9
// 0�� 1�� 6�� 5��2��9
// 0�� 1�� 2�� 5��6��9

#include "funcdef.h"

static void  printarray(int * parray, int nsize) {
	for (int i = 0; i < nsize ; i++) {
		cout << parray[i]<< " ";
	}
	cout << endl;
}
//ѡ������
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

//6 ��1�� 0�� 5�� 2�� 9
//1 ,  0,    5,   2,    6,   9
//0,   1,    2,   5,    6,   9
//ð������
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

//��������
//9, 5, 2, 7, 1, 6, 11
//�ȴ��������ҵ���һ����9С��Ԫ��6��Ȼ��6��9����λ��
//6, 5, 2, 7, 1, 9, 11
//Ȼ��������ң���Ԫ��5��ʼ���ұ�9���Ԫ�أ�Ȼ�󽻻�λ�ã�Ŀǰû���ֱ�9��ġ�
//����9����߶��Ǳ�9С��Ԫ�أ�9���ұ߶��Ǳ�9���Ԫ�ء�
//Ȼ���Դ����ƣ��ֱ�������취��9�������ߵ�Ԫ�طֱ����򼴿ɡ�
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