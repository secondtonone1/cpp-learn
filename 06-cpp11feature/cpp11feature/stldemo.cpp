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
	//初始化array，每个元素为0
	std::array<double, 10> darray{};
	//使用fill，将array所有元素填充为同一个3.14
	darray.fill(3.1415926);
	//使用迭代器遍历
	for (std::array<double,10>::iterator  it = darray.begin(); it != darray.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}

//vector 支持push_back, pop_back操作, 同时可以通过front,back访问头尾
//支持下表访问
void use_vector() {
	//vector初始化，大小为5，每个元素为0
	vector<int>  nvec(5);
	//vecotr初始化，大小为6， 每个元素为1
	vector<int> nvec1(6, 1);
	//初始化vector，只有一个元素20
	vector<int> nvec2{ 20 };
	//修改capacity
	nvec2.reserve(10);
	std::vector<string>  countries = { "China","Russian","Japan","Korean","India" };
	//两种方式copy vector, 通过迭代器
	std::vector<string> ct_copy = { countries.begin(), countries.end() };
	std::vector<string> ct_copy2 = { std::begin(ct_copy), std::end(ct_copy) };
	//C11 方式遍历
	for (auto element : ct_copy) {
		cout << element << " ";
	}
	cout << endl;

	//移动数据
	ct_copy2 = { std::make_move_iterator(std::begin(ct_copy)), std::make_move_iterator(std::end(ct_copy)) };
	for (vector<string>::iterator it = ct_copy.begin(); it != ct_copy.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;

	for (auto element : ct_copy2) {
		cout << element << " ";
	}
	cout << endl;
	//扩充大小
	ct_copy2.resize(20);
	//vector 可以随意访问指定位置元素
	cout << ct_copy2[1] << endl;

	//获取头部元素和尾部元素
	cout << ct_copy2.front() << " " << ct_copy2.back() << endl;
	//将vector转化为数组
	auto parray = ct_copy2.data();
	for (int i = 0; i < ct_copy2.size(); i++) {
		cout << *(parray + i) << " ";
	}
	cout << endl;
	//从输入流中copy数据给ct_copy2，放在末尾依此插入,  ctrl  z结束
	//std::copy(std::istream_iterator<string>(std::cin), std::istream_iterator<string>(), std::back_inserter(ct_copy2));
	//通过指向常量迭代器遍历
	for (std::vector<string>::const_iterator it = ct_copy2.cbegin(); it != ct_copy2.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;

	auto h1 = new Hero(1024);
	auto h2 = new Hero(2048);
	auto h3 = new Hero(22);
	//插入vector
	std::vector<Hero *> hvec;
	hvec.push_back(h1);
	hvec.push_back(h2);
	hvec.push_back(h3);
	std::sort(hvec.begin(), hvec.end());
	//copy到ostream流里，其实就是输出
	copy(hvec.begin(), hvec.end(), ostream_iterator<Hero*>(cout, ""));
	//emplace, 效率比push_back好，参数是构造函数的参数
	std::vector<Hero> hvec2;
	hvec2.emplace_back(100);
	hvec2.emplace_back(89);
	hvec2.emplace_back(1024);
	copy(hvec2.begin(), hvec2.end(), ostream_iterator<Hero>(cout, ""));
	//emplace 在指定位置插入,返回插入后元素的迭代器，先返回迭代器然后++
	auto iterv = hvec2.emplace(++std::begin(hvec2), 25);
	hvec2.emplace(++iterv, 77);
	copy(hvec2.begin(), hvec2.end(), ostream_iterator<Hero>(cout, ""));
	//insert 插入指定元素
	hvec.insert(hvec.begin(), new Hero(109));
	//insert 可以插入一个序列
	//hvec.insert(hvec.end(), hvec3.begin(), hvec3.end());
	//查找
   auto findit  = std::find(hvec.begin(), hvec.end(), h2);
   if (findit != hvec.end()) {
	   cout << "find data" << endl;
   }else {
	   cout << "not found " << endl;
   }

   //删除最后一个元素
   auto heroback =  hvec.back();
	//vector移除最后一个元素
    hvec.pop_back();
	//因为是指针，所以要回收空间
	delete heroback;

	//缓存迭代器指向的变量
	auto iterase = hvec.begin() + 1;
	heroback = *iterase;
	//erase返回删除元素的下一个元素的迭代器
	iterase = hvec.erase(iterase);
	//回收指针空间
	delete heroback;
	//erase 回收一段区间， 但是要提前回收空间
	//hvec.erase(hvec.begin(), hvec.end());
	for (auto element : hvec) {
		delete element;
	}
	hvec.clear();
}

//deque支持push_back, pop_back, push_front, pop_front等操作
//支持insert 在指定位置插入
//也支持front, back访问头尾
//支持下标访问
void use_deque() {
	std::deque<string>  books = { "flown","zero","play" };
	std::deque<string> books_copy =  { std::begin(books), std::end(books) };
	std::sort(books.begin(), books.end());
	for (auto element : books_copy) {
		cout << element << " ";
	}
	cout << endl;
	//双端队列支持下标访问
	cout << books[1] << endl;
	//at访问
	cout << books[2] << endl;
	//访问头部
	cout << books.front() << endl;
	//访问尾部
	cout << books.back() << endl;
	//插入尾部元素
	books_copy.push_back("good idea");
	//插入头部元素
	books_copy.push_front("first step");
	//插入emplace_front, 参数为构造函数参数
	books_copy.emplace_front(5, 'A');
	//插入emplace_back
	books_copy.emplace_back(6, 'S');
	//利用迭代器在指定位置插入
	books_copy.insert(books_copy.begin(), "insert");
	//删除头部
	books_copy.pop_front();
	//删除尾部
	books_copy.pop_back();
	//可以直接替换
	books_copy[0] = "Hello world";
	for (auto book : books_copy) {
		cout << book << " " << endl;
	}
	cout << endl;
	//assign替换整个books_copy
	books_copy.assign(books.begin(), books.end());
	for (auto book : books_copy) {
		cout << book << " " << endl;
	}
	//替换指定的位置
	books_copy.assign(1, "cpp");
	cout << endl;
	for (auto book : books_copy) {
		cout << book << " " << endl;
	}
	cout << endl;

}

//list 不支持下标访问
//list 支持pop_front, push_front, pop_back, push_back
//list 支持front和back访问头尾
//支持insert，在指定位置插入
void use_list() {
	std::list<string> books = { "starve", "nobody", "diet", "noisy" };
	cout << books.front() << endl;
	cout << books.back() << endl;
	//插入头部
	books.emplace_front(5, 'A');
	books.push_front("firststep");
	//插入尾部
	books.emplace_back("lastday");
	books.push_back("brother");
	for (auto book : books) {
		cout << book << " ";
	}
	cout << endl;
	//先查找
	std::list<string>::iterator  findit = std::find(books.begin(), books.end(), "diet");
	//找到了就插入
	if (findit != books.end()) {
		books.insert(findit, "goodevning");
	}
	for (auto book : books) {
		cout << book << " ";
	}
	cout << endl;
	//移除指定名字的元素
	books.remove("firststep");
	//当然也可以先查找，再删除
	findit = std::find(books.begin(), books.end(), "brother");
	if (findit != books.end()) {
		books.erase(findit);
	}

	//去除重复的元素
	books.unique();
	//std::sort 不支持list操作，因为std::sort要求连续空间，但是list提供了sort操作
	books.sort(std::greater<std::string>());
}

void use_map() {
	std::map<string, int> students;
	//插入数据
	auto insertres = students.insert(make_pair("Zack", 20));
	//插入成功，则返回pair，pair第二个数据为bool表示成功还是失败，第一个数据是插入的元素的迭代器,通过迭代器我们取出pair中的string和int
	cout << insertres.first->first<< " " << insertres.first->second <<" " << insertres.second << endl;
	students.insert(make_pair("Bob", 21));
	//插入相同KEY数据会失败
	insertres = students.insert(make_pair("Bob", 22));
	cout << insertres.first->first << " " << insertres.first->second << " " << insertres.second << endl;
	//map 也支持emplace，传入构造函数的参数即可
	insertres = students.emplace("Alice", 22);
	cout << insertres.first->first << " " << insertres.first->second << " " << insertres.second << endl;
	//查找
	auto iterfind = students.find("Bob");
	if (iterfind != students.end()) {
		cout << "find bob" << " " << iterfind->first <<" " <<  iterfind->second << endl;
	}
	//[]访问不安全，当key存在时返回对应的元素，当key不存在时自动创建新的元素
	students["Bob"] = 1024;
	students["Daniel"] = 22;
	for (auto element : students) {
		cout << element.first << " " << element.second;
		cout << endl;
	}
	auto itererase = students.erase("WangWc");
	//没有key，删除返回0
	cout << itererase << endl;
	itererase = students.erase("Alice");
	//删除的key存在，则返回1
	cout << itererase << endl;
	//erase还有一个重载版本，参数为迭代器
	auto eraseiter = students.erase(students.begin());
	if (eraseiter == students.end()) {
		//删除的时最后一个元素
		cout << "remove the last element" << endl;
	}else {
		//否则返回删除的元素的下一个迭代器
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
	//删除和map操作一样，可以通过迭代器删除
	find_res = students.find("Zack");
	if (find_res != students.end()) {
		students.erase(find_res);
	}
	//可以通过key删除，返回1表示删除成功，返回0表示key不在map中
	auto n = students.erase("ZackFair");
}