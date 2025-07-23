
#include <iostream>
#include "DictionaryList.h"

using namespace std;

int main() {
	int f = 23;
	int g = 32;
	DictionaryList<int> a;
	a.print();
	a.push_back(3);
	a.push_back(2);
	a.push_back(1);
	a.push_back(4);
	a.push_back(0);
	a.push_back(6);
	a.push_back(3);
	a.push_back(2);
	a.push_back(1);
	a.push_back(4);
	a.push_back(0);
	a.push_back(6);
	a.push_back(123);
	a.push_back(124);
	a.push_back(754);
	a.push_back(2);
	a.push_back(f);
	a.push_back(g);
	a.print();
	a.pop_back();
	a.pop_back();
	a.pop_back();
	a.pop_front();
	a.pop_front();
	a.pop_front();
	a.pop_front();
	a.print();
	DictionaryList<int> b, c;
	b.pop_back();
	b.push_back(8);
	b.pop_back();
	a.delete_special_node(4);
	a.print();
	a.delete_special_node(4);
	a.print();
	a.delete_special_node(4);
	a.print();
	DictionaryList<int> d(c);
	DictionaryList<int> list(a);
	list.print();
	DictionaryList<int> list2(move(list));
	cout << "-----------------------" << endl;
	list2.clear();
	list.print();
	list2.print();
	b = move(a);
	b.print();
}
