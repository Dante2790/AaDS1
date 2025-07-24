#include "DictionaryList.h"

using namespace std;

void test_dictionary_functional();
void test_list_functional();
void choose_test(int&& number);

int main() {
	choose_test(1);
}

void test_dictionary_functional() {
	cout << "------------------------------------------------------------------------------" << endl;

	cout << "test #1" << endl << endl;

	DictionaryList<int> dict1;
	int temp1 = 10;
	int temp2 = 4;
	dict1.print();
	dict1.insertItem(4);
	dict1.insertItem(4);
	dict1.insertItem(6);
	dict1.insertItem(5);
	dict1.insertItem(temp1);
	dict1.insertItem(temp2);
	dict1.print();
	dict1.searchItem(6);
	dict1.searchItem(7);
	dict1.deleteItem(6);
	dict1.deleteItem(8);
	dict1.print();
	dict1.clear();
	dict1.print();

	cout << endl << endl << "test #2" << endl << endl;

	DictionaryList<string> dict2;
	string temp3 = "hat";
	string temp4 = "apple";
	dict2.print();
	dict2.insertItem("apple");
	dict2.insertItem("apple");
	dict2.insertItem("cow");
	dict2.insertItem("butter");
	dict2.insertItem(temp3);
	dict2.insertItem(temp4);
	dict2.print();
	dict2.searchItem("cow");
	dict2.searchItem("gun");
	dict2.deleteItem("cow");
	dict2.deleteItem("time");
	dict2.print();
	dict2.clear();
	dict2.print();

	cout << endl << endl << "test #3" << endl << endl;

	DictionaryList<int> dict8, dict9;
	dict8.push_back(0);
	dict8.push_back(1);
	dict8.push_back(2);
	dict8.push_back(3);
	dict8.push_back(4);
	dict8.push_back(5);
	dict8.push_back(6);
	dict8.push_back(7);
	dict8.push_back(8);
	dict8.push_back(9);
	dict8.push_back(10);
	dict8.print();

	dict9.push_back(1);
	dict9.push_back(7);
	dict9.push_back(11);
	dict9.print();

	dict8.deleteItems(dict9);
	dict8.print();
	dict9.print();

	cout << endl << endl;
	cout << "------------------------------------------------------------------------------" << endl;
}

void test_list_functional() {
	cout << "------------------------------------------------------------------------------" << endl;

	cout << "test #1" << endl << endl;

	DictionaryList<int> dict3, dict4;
	int temp5 = 6;
	dict3.print();
	dict3.push_back(5);
	dict3.push_back(temp5);
	dict3.push_back(5);
	dict3.push_back(temp5);
	dict3.push_back(32);
	dict3.push_back(31);
	dict3.push_back(-234);
	dict3.push_back(56);
	dict3.print();

	DictionaryList<int> dict5(dict3);
	DictionaryList<int> dict6(dict4);
	dict5.print();
	dict6.print();
	DictionaryList<int> dict7(move(dict5));
	dict7.print();
	dict5.print();
	dict5 = dict7;
	dict5.print();
	dict6.print();
	dict7.print();
	dict6 = move(dict7);
	dict5.print();
	dict6.print();
	dict7.print();
	dict6.pop_back();
	dict6.print();
	dict6.pop_front();
	dict6.print();
	dict6.delete_special_node(3);
	dict6.print();
	dict6.clear();
	dict6.print();
	dict6.clear();

	cout << endl << endl;
	cout << "------------------------------------------------------------------------------" << endl;
}

void choose_test(int&& number) {
	switch (number) {
	case 1: test_dictionary_functional(); break;
	case 2: test_list_functional(); break;
	}
}