#include "heapsort.h"
HeapSort::HeapSort(const vector<int> & vectmp) {
	m_vectree = vectmp;
}

HeapSort::HeapSort(int * n_array, int nsize) {
	m_vectree.clear();
	for (int i = 0; i < nsize; i++) {
		m_vectree.push_back(n_array[i]);
	}
}

HeapSort::HeapSort() {

}

HeapSort::~HeapSort() {

}

//������nroot����Ϊ��������Ϊ�����
void HeapSort::adjust_down(int nroot, int nlen) {
	int nleft = 2 * nroot+1;
	int nright = nleft + 1;
	int nmax = nleft;
	for (;;) {
		//�ýڵ���Ҷ�ӽڵ�
		if (nleft > nlen - 1) {
			return;
		}

		//ע���ʱ��֤nrootΪ���ڵ�������������Զ��Ǵ����
		//�Ƚ���������ѡ������
		//�ýڵ�û���ҽڵ�
		if (nright <= nlen - 1 && m_vectree[nright] > m_vectree[nleft]) {
			nmax = nright;
		}
		//���ڵ�������������󣬲���Ҫ�ƶ�
		if (m_vectree[nroot] > m_vectree[nmax]) {
			return;
		}
		//���ڵ�û���������������Ľڵ���򽻻�
		swap(nroot, nmax);
		//�������������������
		nroot = nmax;
		nleft = 2 * nroot + 1;
		nright = nleft + 1;
		nmax = nleft;
	}	
}

void HeapSort::swap(int index1, int index2) {
	if (index1 > m_vectree.size() - 1 || index2 > m_vectree.size() - 1) {
		return;
	}
	int temp = m_vectree[index1];
	m_vectree[index1] = m_vectree[index2];
	m_vectree[index2] = temp;
}

//���������Ϊ�����
void HeapSort::adjust_heap() {
	if (m_vectree.size() == 0) {
		return;
	}
	//�ȴ����һ���������ڵ��������֤������Ϊ�����
	//���һ�������������Ȼ��������������һ��������
	//һ�е�����������ɣ�����������һ���������������ϡ�
	int nlastroot = m_vectree.size()/2 - 1;
	for (; nlastroot >= 0; nlastroot--) {
		adjust_down(nlastroot, m_vectree.size());
	}
}

//��ӡ����
void HeapSort::print_data() {
	for (auto iter = m_vectree.begin(); iter != m_vectree.end(); iter++) {
		cout << *iter << " ";
	}
	cout << endl;
}

//���ڴ���ѣ�������Ѹ�Ԫ�غ����һ��Ҷ��Ԫ�ؽ������������һ��Ԫ��Ϊ����
//Ȼ���ȥ���һ���ڵ㣬ʣ��n-1�ڵ�������ɴ���ѡ�
//������ɵ����о��Ǵ�С��������ġ�
void HeapSort::heap_sort() {
	for (int i = m_vectree.size() - 1; i > 0; i--) {
		swap(0, i);
		//ʣ��i������Ϊ�����
		adjust_down(0, i);
	}
}
//���߿��Կ��ǵ����µ�Ԫ�ز���ʱ����ô���ɴ����
//��ʵ���ǽ��µ�Ԫ�طŵ�vectorĩβ��Ȼ�������ϵ��ڣ�ֱ�����ϴ����Ϊֹ
//��������ʵ��
/*
void HeapSort::adjust_up(int nleaf, int nlen) {
}
*/