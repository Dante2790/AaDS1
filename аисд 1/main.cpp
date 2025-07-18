
#include <iostream>
#include "DictionaryList.h"

using namespace std;

int main() {
	
	int a = 31;
	string c = "hat";
	
	int* ptr = &a;
	cout << ptr << endl << *ptr << endl;
	DictionaryList<string> b;
	b.print();
	b.push_back("apple");
	b.print();
	b.push_back("bread");
	b.push_back(c);
	b.print();
	
	b.push_back("a");
	b.push_back("b");
	b.push_back("c");
	b.push_back("d");
	b.push_back("A");
	b.push_back("J");
	b.print();
}
