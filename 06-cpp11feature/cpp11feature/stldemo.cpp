#include "stldemo.h"
#include <memory>
#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <list>
#include <functional>
#include <map>
#include <unordered_map>
using namespace std;
void use_array() {
	//��ʼ��array��ÿ��Ԫ��Ϊ0
	std::array<double, 10> darray{};
	//ʹ��fill����array����Ԫ�����Ϊͬһ��3.14
	darray.fill(3.1415926);
	//ʹ�õ���������
	for (std::array<double,10>::iterator  it = darray.begin(); it != darray.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}

//vector ֧��push_back, pop_back����, ͬʱ����ͨ��front,back����ͷβ
//֧���±����
void use_vector() {
	//vector��ʼ������СΪ5��ÿ��Ԫ��Ϊ0
	vector<int>  nvec(5);
	//vecotr��ʼ������СΪ6�� ÿ��Ԫ��Ϊ1
	vector<int> nvec1(6, 1);
	//��ʼ��vector��ֻ��һ��Ԫ��20
	vector<int> nvec2{ 20 };
	//�޸�capacity
	nvec2.reserve(10);
	std::vector<string>  countries = { "China","Russian","Japan","Korean","India" };
	//���ַ�ʽcopy vector, ͨ��������
	std::vector<string> ct_copy = { countries.begin(), countries.end() };
	std::vector<string> ct_copy2 = { std::begin(ct_copy), std::end(ct_copy) };
	//C11 ��ʽ����
	for (auto element : ct_copy) {
		cout << element << " ";
	}
	cout << endl;

	//�ƶ�����
	ct_copy2 = { std::make_move_iterator(std::begin(ct_copy)), std::make_move_iterator(std::end(ct_copy)) };
	for (vector<string>::iterator it = ct_copy.begin(); it != ct_copy.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;

	for (auto element : ct_copy2) {
		cout << element << " ";
	}
	cout << endl;
	//�����С
	ct_copy2.resize(20);
	//vector �����������ָ��λ��Ԫ��
	cout << ct_copy2[1] << endl;

	//��ȡͷ��Ԫ�غ�β��Ԫ��
	cout << ct_copy2.front() << " " << ct_copy2.back() << endl;
	//��vectorת��Ϊ����
	auto parray = ct_copy2.data();
	for (int i = 0; i < ct_copy2.size(); i++) {
		cout << *(parray + i) << " ";
	}
	cout << endl;
	//����������copy���ݸ�ct_copy2������ĩβ���˲���,  ctrl  z����
	//std::copy(std::istream_iterator<string>(std::cin), std::istream_iterator<string>(), std::back_inserter(ct_copy2));
	//ͨ��ָ��������������
	for (std::vector<string>::const_iterator it = ct_copy2.cbegin(); it != ct_copy2.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;

	auto h1 = new Hero(1024);
	auto h2 = new Hero(2048);
	auto h3 = new Hero(22);
	//����vector
	std::vector<Hero *> hvec;
	hvec.push_back(h1);
	hvec.push_back(h2);
	hvec.push_back(h3);
	std::sort(hvec.begin(), hvec.end());
	//copy��ostream�����ʵ�������
	copy(hvec.begin(), hvec.end(), ostream_iterator<Hero*>(cout, ""));
	//emplace, Ч�ʱ�push_back�ã������ǹ��캯���Ĳ���
	std::vector<Hero> hvec2;
	hvec2.emplace_back(100);
	hvec2.emplace_back(89);
	hvec2.emplace_back(1024);
	copy(hvec2.begin(), hvec2.end(), ostream_iterator<Hero>(cout, ""));
	//emplace ��ָ��λ�ò���,���ز����Ԫ�صĵ��������ȷ��ص�����Ȼ��++
	auto iterv = hvec2.emplace(++std::begin(hvec2), 25);
	hvec2.emplace(++iterv, 77);
	copy(hvec2.begin(), hvec2.end(), ostream_iterator<Hero>(cout, ""));
	//insert ����ָ��Ԫ��
	hvec.insert(hvec.begin(), new Hero(109));
	//insert ���Բ���һ������
	//hvec.insert(hvec.end(), hvec3.begin(), hvec3.end());
	//����
   auto findit  = std::find(hvec.begin(), hvec.end(), h2);
   if (findit != hvec.end()) {
	   cout << "find data" << endl;
   }else {
	   cout << "not found " << endl;
   }

   //ɾ�����һ��Ԫ��
   auto heroback =  hvec.back();
	//vector�Ƴ����һ��Ԫ��
    hvec.pop_back();
	//��Ϊ��ָ�룬����Ҫ���տռ�
	delete heroback;

	//���������ָ��ı���
	auto iterase = hvec.begin() + 1;
	heroback = *iterase;
	//erase����ɾ��Ԫ�ص���һ��Ԫ�صĵ�����
	iterase = hvec.erase(iterase);
	//����ָ��ռ�
	delete heroback;
	//erase ����һ�����䣬 ����Ҫ��ǰ���տռ�
	//hvec.erase(hvec.begin(), hvec.end());
	for (auto element : hvec) {
		delete element;
	}
	hvec.clear();
}

//deque֧��push_back, pop_back, push_front, pop_front�Ȳ���
//֧��insert ��ָ��λ�ò���
//Ҳ֧��front, back����ͷβ
//֧���±����
void use_deque() {
	std::deque<string>  books = { "flown","zero","play" };
	std::deque<string> books_copy =  { std::begin(books), std::end(books) };
	std::sort(books.begin(), books.end());
	for (auto element : books_copy) {
		cout << element << " ";
	}
	cout << endl;
	//˫�˶���֧���±����
	cout << books[1] << endl;
	//at����
	cout << books[2] << endl;
	//����ͷ��
	cout << books.front() << endl;
	//����β��
	cout << books.back() << endl;
	//����β��Ԫ��
	books_copy.push_back("good idea");
	//����ͷ��Ԫ��
	books_copy.push_front("first step");
	//����emplace_front, ����Ϊ���캯������
	books_copy.emplace_front(5, 'A');
	//����emplace_back
	books_copy.emplace_back(6, 'S');
	//���õ�������ָ��λ�ò���
	books_copy.insert(books_copy.begin(), "insert");
	//ɾ��ͷ��
	books_copy.pop_front();
	//ɾ��β��
	books_copy.pop_back();
	//����ֱ���滻
	books_copy[0] = "Hello world";
	for (auto book : books_copy) {
		cout << book << " " << endl;
	}
	cout << endl;
	//assign�滻����books_copy
	books_copy.assign(books.begin(), books.end());
	for (auto book : books_copy) {
		cout << book << " " << endl;
	}
	//�滻ָ����λ��
	books_copy.assign(1, "cpp");
	cout << endl;
	for (auto book : books_copy) {
		cout << book << " " << endl;
	}
	cout << endl;

}

//list ��֧���±����
//list ֧��pop_front, push_front, pop_back, push_back
//list ֧��front��back����ͷβ
//֧��insert����ָ��λ�ò���
void use_list() {
	std::list<string> books = { "starve", "nobody", "diet", "noisy" };
	cout << books.front() << endl;
	cout << books.back() << endl;
	//����ͷ��
	books.emplace_front(5, 'A');
	books.push_front("firststep");
	//����β��
	books.emplace_back("lastday");
	books.push_back("brother");
	for (auto book : books) {
		cout << book << " ";
	}
	cout << endl;
	//�Ȳ���
	std::list<string>::iterator  findit = std::find(books.begin(), books.end(), "diet");
	//�ҵ��˾Ͳ���
	if (findit != books.end()) {
		books.insert(findit, "goodevning");
	}
	for (auto book : books) {
		cout << book << " ";
	}
	cout << endl;
	//�Ƴ�ָ�����ֵ�Ԫ��
	books.remove("firststep");
	//��ȻҲ�����Ȳ��ң���ɾ��
	findit = std::find(books.begin(), books.end(), "brother");
	if (findit != books.end()) {
		books.erase(findit);
	}

	//ȥ���ظ���Ԫ��
	books.unique();
	//std::sort ��֧��list��������Ϊstd::sortҪ�������ռ䣬����list�ṩ��sort����
	books.sort(std::greater<std::string>());
}

void use_map() {
	std::map<string, int> students;
	//��������
	auto insertres = students.insert(make_pair("Zack", 20));
	//����ɹ����򷵻�pair��pair�ڶ�������Ϊbool��ʾ�ɹ�����ʧ�ܣ���һ�������ǲ����Ԫ�صĵ�����,ͨ������������ȡ��pair�е�string��int
	cout << insertres.first->first<< " " << insertres.first->second <<" " << insertres.second << endl;
	students.insert(make_pair("Bob", 21));
	//������ͬKEY���ݻ�ʧ��
	insertres = students.insert(make_pair("Bob", 22));
	cout << insertres.first->first << " " << insertres.first->second << " " << insertres.second << endl;
	//map Ҳ֧��emplace�����빹�캯���Ĳ�������
	insertres = students.emplace("Alice", 22);
	cout << insertres.first->first << " " << insertres.first->second << " " << insertres.second << endl;
	//����
	auto iterfind = students.find("Bob");
	if (iterfind != students.end()) {
		cout << "find bob" << " " << iterfind->first <<" " <<  iterfind->second << endl;
	}
	//[]���ʲ���ȫ����key����ʱ���ض�Ӧ��Ԫ�أ���key������ʱ�Զ������µ�Ԫ��
	students["Bob"] = 1024;
	students["Daniel"] = 22;
	for (auto element : students) {
		cout << element.first << " " << element.second;
		cout << endl;
	}
	auto itererase = students.erase("WangWc");
	//û��key��ɾ������0
	cout << itererase << endl;
	itererase = students.erase("Alice");
	//ɾ����key���ڣ��򷵻�1
	cout << itererase << endl;
	//erase����һ�����ذ汾������Ϊ������
	auto eraseiter = students.erase(students.begin());
	if (eraseiter == students.end()) {
		//ɾ����ʱ���һ��Ԫ��
		cout << "remove the last element" << endl;
	}else {
		//���򷵻�ɾ����Ԫ�ص���һ��������
		cout << eraseiter->first << " " << eraseiter->second << endl;
	}
}

void use_unorderd_map() {
	std::unordered_map<string, int > students;
	auto insertres = students.insert(std::make_pair("Zack", 1024));
	cout << insertres.first->first << " " << insertres.first->second << " " << insertres.second << endl;
	auto find_res = students.find("Rolin");
	if (find_res == students.end()) {
		cout << "not found Rolin" << endl;
	}
	else {
		cout << find_res->first << " " << find_res->second << endl;
	}
	students.insert(std::make_pair("Zack Fair", 1024));
	//ɾ����map����һ��������ͨ��������ɾ��
	find_res = students.find("Zack");
	if (find_res != students.end()) {
		students.erase(find_res);
	}
	//����ͨ��keyɾ��������1��ʾɾ���ɹ�������0��ʾkey����map��
	auto n = students.erase("ZackFair");
}