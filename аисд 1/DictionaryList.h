#ifndef DICTIONARYLIST_H
#define DICTIONARYLIST_H

#include <string>
#include <iostream>
#include <chrono>
#include <thread>
#include <stdexcept>
#include <typeinfo>
using namespace std;
template<typename T1>

class DictionaryList {
private:
    struct Node {
        T1 data;
        Node* next;
        Node(const T1& new_data) : data(new_data), next(nullptr) {}
        Node(T1&& new_data): data(move(new_data)), next(nullptr){}
    };

    Node* first;
    Node* last;

    int size = 0;

public:
    /* DictionaryList();
     DictionaryList(const DictionaryList& other);
     DictionaryList(DictionaryList&& other) {};
     DictionaryList& operator=(DictionaryList&& other) {};

     ~DictionaryList() {};
     void insertItem() {};
     bool searchItem() {};
     void deleteItem() {};

     int getSize() {};
     void is_empty() {};


     void deleteItems() {};
     */
    void print() {
        switch (check_for_content()) {
        case 1:
            break;
        case 0: {
            Node* printing_node = this->first;
            for (int i = 0; i < (this->size); i++) {
                cout << printing_node->data << " -> ";
                printing_node = printing_node->next;
            }
            cout << endl;
            break;
        }
        }
    }


    DictionaryList() : size(0), first(nullptr), last(nullptr) {};


    void delete_data(T1 data) {         //переделать
        check_for_content();
        Node* verifiable_node = this->first;

        for (int i = 0; i < size; i++) {
            if (verifiable_node->data == data) {
                verifiable_node->data = " ";
                size -= 1;
                return;
            }
            else {
                verifiable_node = this->first->next;
            }
        }
    }
    
    void push_back(const T1& new_data) {
  
        Node* new_node = new Node(new_data);  
        switch (is_empty()) {
        case true:
            this->first = new_node;
            this->last = new_node;
            break;
        case false:
            this->last->next = new_node;
            this->last = new_node;
            break;
        }
        this->size += 1;
    }

    void push_back(T1&& new_data) {
 
        Node* new_node = new Node(move(new_data));
        switch (is_empty()) {
        case true:
            this->first = new_node;
            this->last = new_node;
            break;
        case false:
            this->last->next = new_node;
            this->last = new_node;
            break;
        }
        this->size += 1;
    }
    void delete_node() {

    }
    void edit_data(int key) {

    }
    bool is_empty() {
        return first == nullptr;
    }
    void print_error_empty() {
        cout << "sorry, but this list is empty" << endl;
        return;
    }
    void print_loading() {
        cout << "|*";
        this_thread::sleep_for(chrono::seconds(1));
        cout << "*";
        this_thread::sleep_for(chrono::seconds(1));
        cout << "*|" << endl;
        this_thread::sleep_for(chrono::seconds(1));
        return;
    }
    int check_for_content() {
        switch (is_empty()) {
        case true:
            print_error_empty();
            return 1;
        case false:
            return 0;
        }
        return 0;
    }
    T1 get_data(Node& node) {
        return node->data;
    }
    
    void sort_list() {
        Node* node_for_sorting = this->first;
        Node* node_for_sorting2 = nullptr;
        for (int i = 0; i < (this->size); i++) {
            if (node_for_sorting->data < node_for_sorting->next->data) {

            }
        }
    }
    
    
    /*template<typename T1, typename T2>
    DictionaryList<T1, T2>::DictionaryList(const DictionaryList& other) : first(other.first), last(other.last), size(other.size) {}; //переделать//

    template<typename T1, typename T2>
    DictionaryList<T1, T2>::DictionaryList(DictionaryList&& other) : first(other.first), last(other.last), size(other.size) {
        other.first(nullptr), other.last(nullptr), other.size(0)}; //переделать//

    */

};
#endif