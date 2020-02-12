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

//调整以nroot索引为根的子树为大根堆
void HeapSort::adjust_down(int nroot, int nlen) {
	int nleft = 2 * nroot+1;
	int nright = nleft + 1;
	int nmax = nleft;
	for (;;) {
		//该节点是叶子节点
		if (nleft > nlen - 1) {
			return;
		}

		//注意此时保证nroot为根节点的左右子树各自都是大根堆
		//比较左右子树选出最大的
		//该节点没有右节点
		if (nright <= nlen - 1 && m_vectree[nright] > m_vectree[nleft]) {
			nmax = nright;
		}
		//根节点比左右子树都大，不需要移动
		if (m_vectree[nroot] > m_vectree[nmax]) {
			return;
		}
		//根节点没有左右子树中最大的节点大，则交换
		swap(nroot, nmax);
		//继续调整交换后的子树
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

//将数组调整为大根堆
void HeapSort::adjust_heap() {
	if (m_vectree.size() == 0) {
		return;
	}
	//先从最后一个子树根节点调整，保证该子树为大根堆
	//最后一个子树调整完后，然后从右向左调整下一个子树。
	//一行的子树调整完成，继续调整上一个子树，从下向上。
	int nlastroot = m_vectree.size()/2 - 1;
	for (; nlastroot >= 0; nlastroot--) {
		adjust_down(nlastroot, m_vectree.size());
	}
}

//打印数据
void HeapSort::print_data() {
	for (auto iter = m_vectree.begin(); iter != m_vectree.end(); iter++) {
		cout << *iter << " ";
	}
	cout << endl;
}

//基于大根堆，将大根堆根元素和最后一个叶子元素交换，这样最后一个元素为最大的
//然后除去最后一个节点，剩余n-1节点继续生成大根堆。
//最后生成的序列就是从小到大排序的。
void HeapSort::heap_sort() {
	for (int i = m_vectree.size() - 1; i > 0; i--) {
		swap(0, i);
		//剩余i个调整为大根堆
		adjust_down(0, i);
	}
}
//读者可以考虑当有新的元素插入时，怎么生成大根堆
//其实就是将新的元素放到vector末尾，然后将其向上调节，直到符合大根堆为止
//读者自行实现
/*
void HeapSort::adjust_up(int nleaf, int nlen) {
}
*/