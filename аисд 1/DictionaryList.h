#ifndef DICTIONARYLIST_H
#define DICTIONARYLIST_H

#include <string>
#include <iostream>
#include <chrono>
#include <thread>
#include <stdexcept>

using namespace std;
template<typename T1>

class DictionaryList {
private:
    struct Node {
        T1 data;
        Node* next;
        Node(const T1& new_data) : data(new_data), next(nullptr) {}
        Node(T1&& new_data): data(move(new_data)), next(nullptr) {}
        Node(Node* node) : data(node->data), next(nullptr) { delete node; }
        
    };

    Node* first;
    Node* last;

    int size = 0;

public:

    // Конструкторы, операторы и деструктор
    DictionaryList() : size(0), first(nullptr), last(nullptr) {};
    
    DictionaryList(const DictionaryList& other) : size(0), first(nullptr), last(nullptr) {
        try {
            if (other.first == nullptr) {
           //   cout << "list is empty" << endl;
                throw invalid_argument("list is empty");
            }
            Node* current = other.first;
            Node* new_first_node = new Node(current->data);
            this->first = new_first_node;
            this->last = new_first_node;
            current = current->next;
            this->size++;
            for (int i = 1; i < (other.size); i++) {
                Node* new_node = new Node(current->data);
                this->last->next = new_node;
                this->last = new_node;
                current = current->next;
                this->size++;
            }
        }
        catch (invalid_argument er) {
            cerr << "error: " << er.what() << endl;
        }
        catch (bad_alloc er) {
            cerr << "error: " << er.what() << endl;
        }
    };
    DictionaryList(DictionaryList&& other) : size(0), first(nullptr), last(nullptr) {
        try {
            if (other.first == nullptr) {

                throw invalid_argument("list is empty");
            }
            Node* current = other.first;
            Node* current_next = current->next;
            Node* new_first_node = new Node(current);
            this->first = new_first_node;
            this->last = new_first_node;

            other.size--;
            current = current_next;
            other.first = current;
            current_next = current_next->next;
            this->size++;
            int other_size = other.size;
            for (int i = 0; i < (other_size); i++) {
                Node* new_node = new Node(current);
                this->last->next = new_node;
                this->last = new_node;
                current = current_next;
                this->size++;
                other.size--;
                if (current_next->next) {

                    current_next = current_next->next;

                }


            }
            other.first = nullptr;
            other.last = nullptr;
            other.size = 0;
        }
        catch (invalid_argument er) {
            cerr << "error: " << er.what() << endl;
        }
        catch (bad_alloc er) {
            cerr << "error: " << er.what() << endl;
        }
    };

    DictionaryList& operator=(const DictionaryList& other) {
        try {
            if (other.first == nullptr) {
                cout << "list is empty" << endl;
                throw invalid_argument("list is empty");
            }
            this->clear();
            Node* current = other.first;
            Node* new_first_node = new Node(current->data);
            this->first = new_first_node;
            this->last = new_first_node;
            current = current->next;
            this->size++;
            for (int i = 1; i < (other.size); i++) {
                Node* new_node = new Node(current->data);
                this->last->next = new_node;
                this->last = new_node;
                current = current->next;
                this->size++;
            }
            return *this;
        }
        catch (invalid_argument er) {
            cerr << "error: " << er.what() << endl;
        }
        catch (bad_alloc er) {
            cerr << "error: " << er.what() << endl;
        }
    };
    DictionaryList& operator=(DictionaryList&& other) {
        try {
            if (other.first == nullptr) {
                cout << "list is empty" << endl;
                throw invalid_argument("list is empty");
            }
            this->clear();
            Node* current = other.first;
            Node* current_next = current->next;
            Node* new_first_node = new Node(current);
            this->first = new_first_node;
            this->last = new_first_node;

            other.size--;
            current = current_next;
            other.first = current;
            current_next = current_next->next;
            this->size++;
            int other_size = other.size;
            for (int i = 0; i < (other_size); i++) {
                Node* new_node = new Node(current);
                this->last->next = new_node;
                this->last = new_node;
                current = current_next;
                this->size++;
                other.size--;
                if (current_next->next) {

                    current_next = current_next->next;

                }


            }
            other.first = nullptr;
            other.last = nullptr;
            other.size = 0;
            return *this;
        }
        catch (invalid_argument er) {
            cerr << "error: " << er.what() << endl;
        }
        catch (bad_alloc er) {
            cerr << "error: " << er.what() << endl;
        }
    };

    ~DictionaryList() noexcept {
        clear();
        cout << "list was deleted" << endl;
    };



    // Вставка и удаление
    void push_back(const T1& new_data) {
        try {

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

            merge_sort(&this->first);
            this->last = this->first;
            for (int i = 1; i < (this->size); i++) {
                this->last = this->last->next;
            }
        }
        catch (bad_alloc er) {
            cerr << "error: " << er.what() << endl;
        }
    }
    void push_back(T1&& new_data) {
        try {

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

            merge_sort(&this->first);
            this->last = this->first;
            for (int i = 1; i < (this->size); i++) {
                this->last = this->last->next;
            }
        }
        catch (bad_alloc er) {
            cerr << "error: " << er.what() << endl;
        }
    }

    void pop_back() {
        try {
            if (is_empty()) {
                throw (invalid_argument("this list is empty"));
            }
            if (this->last == this->first) {
                delete first;
                this->last = nullptr;
                this->first = nullptr;
                this->size = 0;
                cout << "this list is empty now" << endl;
                return;
            }


            Node* current = this->first;
            for (int i = 2; i < (this->size); i++) {
                current = current->next;
            }
            delete last;
            current->next = nullptr;
            this->last = current;
            this->size--;
        }
        catch (invalid_argument er) {
            cerr << "error: " << er.what() << endl;
            return;
        }
    }
    void pop_front() {
        try {
            if (is_empty()) {
                throw (invalid_argument("this list is empty"));
            }
            if (this->last == this->first) {
                delete first;
                this->last = nullptr;
                this->first = nullptr;
                cout << "this list is empty now" << endl;
                return;
            }


            Node* current = this->first->next;
            delete first;
            first = current;
            this->size--;
        }
        catch (invalid_argument er) {
            cerr << "error: " << er.what() << endl;
            return;
        }
    }
    void delete_special_node(const T1&& data) {

        try {
            if (is_empty()) {
                throw invalid_argument("list is empty");
            }
            if (data == this->first->data) {
                pop_front();
                cout << "data " << '"' << data << '"' << " was deleted" << endl;
                return;
            }
            if (data == this->last->data) {
                pop_back();
                cout << "data " << '"' << data << '"' << " was deleted" << endl;
                return;
            }
            Node* prev = this->first;
            Node* current = this->first->next;
            for (int i = 1; i < (this->size - 1); i++) {
                if (current->data == data) {
                    prev->next = current->next;
                    delete current;
                    cout << "data " << '"' << data << '"' << " was deleted" << endl;
                    this->size--;
                    return;
                }
                prev = prev->next;
                current = current->next;
            }
            cout << "node with data " << '"' << data << '"' << " doesn't exist" << endl;
            return;
        }
        catch (invalid_argument er) {
            cerr << "error: " << er.what() << endl;
            return;
        }
    }



    // Вывод
    void print() {
        try {
            switch (check_for_content()) {
            case 1:
                throw invalid_argument("list is empty");
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
        catch (invalid_argument er) {
            cerr << "error: " << er.what() << endl;
            return;
        }
        
    }
    void print(const Node* node) {
        cout << node->data << endl;
    }
    


    // Сортировка
    void split(Node* source, Node** left, Node** right) {
        Node* slow = source;
        Node* fast = source->next;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        *left = source;
        *right = slow->next;

        slow->next = nullptr;
    }
    Node* merge(Node* left, Node* right) {
        if (!left) { return right; }
        if (!right) { return left; }
        Node* result;
        if (left->data <= right->data) {
            result = left;
            result->next = merge(left->next, right);

        }
        else {
            result = right;
            result->next = merge(left, right->next);

        }

        return result;
    }
    void merge_sort(Node** source_ref) {
        Node* source = *source_ref;
        if (!source || !source->next) { return; }

        Node* left;
        Node* right;

        split(source, &left, &right);
        merge_sort(&left);
        merge_sort(&right);
        *source_ref = merge(left, right);

    }
    
    
    
    // Необходимая (или нет...) мелочевка 
    void clear() noexcept {
        if (is_empty()) {
            return;
        }
        Node* next = this->first->next;
        for (int i = 0; i < (this->size); i++) {

            try { check_node_for_correctness(this->first); }
            catch (invalid_argument er) {
                cerr << "error:" << er.what() << endl;
                this->first = nullptr;
            }
            delete this->first;
            this->first = next;
            if (first != nullptr) {
                next = this->first->next;
            }
        }
        this->first = nullptr;
        this->last = nullptr;
        this->size = 0;
    }

    bool is_empty() {
        return first == nullptr;
    }
    bool is_even(const int size) {
        return size % 2 == 0;
    }
    bool is_invalid(const Node* node) {
        return node == nullptr;
    }
    bool is_data(const T1& data) {
        Node* current = this->first;
        for (int i = 0; i < (this->size); i++) {
            if (current->data == data) {
                return true;
            }
            else {
                current = current->next;
            }
        }
        return false;
    }

    void print_error_empty() {
        cerr << "sorry, but this list is empty" << endl;
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

    void check_node_for_correctness(const Node* current) {
        if (is_invalid(current)) {
            throw invalid_argument("empty node is detected");

        }
    }
    int check_for_content() {
        switch (is_empty()) {
        case true:
    //      print_error_empty();
            return 1;
        case false:
            return 0;
        }
        return 0;
    }

    T1 get_data(const Node& node) {
        return node->data;
    }
    

    
    // Для словаря
    void insertItem(const T1& data) {
        if (!this->is_data(data)) {
            this->push_back(data);
        }
        else {
            cout << "data " <<'"'<<data<<'"'<< " already exists" << endl;
            return;
        }
    }
    void insertItem(T1&& data) {
        if (!this->is_data(data)) {
            this->push_back(data);
        }
        else {
            cout << "data " << '"' << data << '"' << " already exists" << endl;
            return;
        }
    }
    bool searchItem(const T1&& data) {
        switch (this->is_data(data)) {
        case true:
            cout << "this element exists" << endl;
            return true;
        case false:
            cout << "this element doesn't exist" << endl;
            return false;
        }

    }
    void deleteItem(const T1&& data) {
        this->delete_special_node(move (data)); // move здесь, чтобы сохранить rvalue в виде rvalue
    }
    void deleteItems(const DictionaryList& other) {
        int number_of_repeats = 0;
        Node* this_current = this->first;
        Node* other_current = other.first;
        for (int i = 0; i < (other.size); i++) {
            for (int j =0; j<(this->size); j++) { 
                if (this_current->data == other_current->data) {
                    number_of_repeats++;
                }
                if (this_current->next) {
                    this_current = this_current->next;
                }
            }
            for (int k = 0; k < number_of_repeats; k++) {
                this->delete_special_node(move(other_current->data));
            }
            number_of_repeats = 0;
            this_current = this->first;
            if (other_current->next) {
                other_current = other_current->next;
            }
        }
    }




    // собсна, парочка функций для быстрой сортировки

    /*

    Node* get_pivot() {
        int min_size = 1;
        if (this->size <= min_size) {
            return nullptr;
        }
        int size_for_pivot = this->size;
        Node* pivot = this->first;
        switch (is_even(size_for_pivot)) {
        case true:
            for (int i = 0; i < (this->size / 2); i++) {
                pivot = pivot->next;
            }
        case false:
            size_for_pivot++;
            for (int i = 0; i < (this->size / 2); i++) {
                pivot = pivot->next;
            }
        }
        return pivot;
    }
    Node* get_two_sides() {
        int min_size = 1;
        if (this->size <= min_size) {
            return nullptr;
        }
        Node* node_for_sorting = this->first;
        Node* node_for_sorting2 = new Node(node_for_sorting->data);
        for (int i = 0; i < (this->size - 1); i++) {
            if (node_for_sorting->data < node_for_sorting->next->data) {
                node_for_sorting->data = node_for_sorting->next->data;
                node_for_sorting->next->data = node_for_sorting2->data;
            }
            node_for_sorting = node_for_sorting->next;
            node_for_sorting2->data = node_for_sorting->data;

        }
        delete node_for_sorting2;
        return node_for_sorting;
    }
    */

    //увы, я начал писать быструю сортировку, а она подходит только двунаправленным спискам

    /*
    void sort_list() {
        Node* pivot = (move(get_pivot()));
        Node* left_from_pivot
        int location_of_pivot = 0;
        if (pivot == nullptr) {
            return;
        }
        else {
            switch (is_even(this->size)) {
            case true: location_of_pivot=(this->size)/2
            case false: location_of_pivot = (this->size ++) / 2
            }
            for (int i = 0; i < (location_of_pivot); i++) {

            }
        }

    }
    

*/
    };
#endif;