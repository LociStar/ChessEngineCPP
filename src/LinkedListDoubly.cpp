#include <iostream>
#include <string>
#include <sstream>
#include "types.h"

using namespace std;

/* List Node: */

template <class T>
class MyNode {
	private:
		T data;
	public:
		MyNode* next;
		MyNode* previous;
		MyNode(T data);
		T getData();
        Color getColor();
		string toString();
		~MyNode();
};

template <class T>
MyNode<T>::MyNode(T data) {
	this->data = data;
}

template <class T>
T MyNode<T>::getData() {
	return this->data;
}

template <class Move>
Color MyNode<Move>::getColor() {
    return this->c;
}

template <class T>
string MyNode<T>::toString() {
	stringstream s;
	s << this->getData();
	return s.str();
}

template <class T>
MyNode<T>::~MyNode() { }

/* Linked List: */
 
template <class T>
class MyList {
	private:
		T* head;
		T* tail;
		int list_size;
	public:
		MyList();
		T* getHead();
		T* getTail();
		int size(bool update=false);
		void addNodeAsTail(T* new_node);
		void addNodeAsHead(T* new_node);
		void push(T* new_node);
		T* pop();
		T* peek();
		void enqueue(T* new_node);
		T* dequeue();
		T* get(int index);
		void printList();
		void printListBackwards();
		~MyList();
};

template <class T>
MyList<T>::MyList() {
	this->head = NULL;
	this->tail = NULL;
	this->list_size = -1;
}

template <class T>
T* MyList<T>::getHead() {
	return this->head;
}

template <class T>
T* MyList<T>::getTail() {
	return this->tail;
}

template <class T>
int MyList<T>::size(bool update) {
	if (!update) {
		return this->list_size;
	}
	int size = 0;
	T* temp = this->head;
	while (temp) {
		size++;
		temp = temp->next;
	}
	this->list_size = size;
	return this->list_size;
}

template <class T>
void MyList<T>::addNodeAsTail(T* new_node) {
	new_node->next = NULL;
	new_node->previous = NULL;
	
	if (this->head == NULL) {
		this->head = new_node;
		this->tail = this->head;
		this->list_size = this->list_size + 1;
	} else {
		this->tail->next = new_node;
		new_node->previous = this->tail;
		this->tail = new_node;
		this->list_size = this->list_size + 1;
	}
}

template <class T>
void MyList<T>::addNodeAsHead(T* new_node) {
	new_node->next = NULL;
	new_node->previous = NULL;
	
	if (this->head == NULL) {
		this->head = new_node;
		this->tail = this->head;
		this->list_size = this->list_size + 1;
	} else {
		this->head->previous = new_node;
		new_node->next = this->head;
		this->head = new_node;
		this->list_size = this->list_size + 1;
	}
}

template <class T>
void MyList<T>::push(T* new_node) {
	this->addNodeAsHead(new_node);
}

template <class T>
T* MyList<T>::pop() {
	T* temp = this->head;
	this->head = this->head->next;
	this->head->previous = NULL;
	this->list_size = this->list_size - 1;
	return temp;
}

template <class T>
T* MyList<T>::peek() {
	return this->head;
}

template <class T>
void MyList<T>::enqueue(T* new_node) {
	this->addNodeAsTail(new_node);
}

template <class T>
T* MyList<T>::dequeue() {
	return this->pop();
}

template <class T>
T* MyList<T>::get(int index) {
	if (index == 0) {
		return this->head;
	} else if (index == this->list_size - 1) {
		return this->tail;
	} else if (index < 0 || index >= this->list_size) {
		return NULL;
	}
	if (index < this->list_size / 2) {
		T* temp = this->head;
		int i = 0;
		while (temp) {
			if (i == index) { return temp; }
			i++;
			temp = temp->next;
		}
	} else {
		T* temp = this->tail;
		int i = this->list_size - 1;
		while (temp) {
			if (i == index) { return temp; }
			i--;
			temp = temp->previous;
		}
	}
	return NULL;
}

template <class T>
void MyList<T>::printList() {
	cout << "HEAD: ";
	T* temp = this->head;
	while(temp) {
		cout << temp->toString() << " -> ";
		temp = temp->next;
	}
	cout << "\b\b\b\b :TAIL" << endl;
}

template <class T>
void MyList<T>::printListBackwards() {
	cout << "TAIL: ";
	T* temp = this->tail;
	while(temp) {
		cout << temp->toString() << " -> ";
		temp = temp->previous;
	}
	cout << "\b\b\b\b :HEAD" << endl;
}

template <class T>
MyList<T>::~MyList() {
	while (this->head) {
		T* next = this->head->next;
		delete this->head;
		this->list_size = this->list_size - 1;
		this->head = next;
	}
}
/*
void stackAsString() {
	MyList<MyNode<string> > stack;
	int i = 0;
	cout << "String Stack:" << endl;
	
	stack.push(new MyNode<string>("Alpha"));
	stack.push(new MyNode<string>("Bravo"));
	stack.push(new MyNode<string>("Charlie"));
	stack.push(new MyNode<string>("Delta"));
	stack.push(new MyNode<string>("Echo"));
	stack.push(new MyNode<string>("Foxtrot"));
	stack.push(new MyNode<string>("Golf"));
	stack.push(new MyNode<string>("Hotel"));
	stack.push(new MyNode<string>("India"));
	stack.push(new MyNode<string>("Juliet"));
	stack.push(new MyNode<string>("Kilo"));
	stack.push(new MyNode<string>("Lima"));
	stack.push(new MyNode<string>("Mike"));
	stack.push(new MyNode<string>("November"));
	stack.push(new MyNode<string>("Oscar"));
	stack.push(new MyNode<string>("Papa"));
	stack.push(new MyNode<string>("Quebec"));
	stack.push(new MyNode<string>("Romeo"));
	stack.push(new MyNode<string>("Sierra"));
	stack.push(new MyNode<string>("Tango"));
	stack.push(new MyNode<string>("Uniform"));
	stack.push(new MyNode<string>("Victor"));
	stack.push(new MyNode<string>("Whiskey"));
	stack.push(new MyNode<string>("X-ray"));
	stack.push(new MyNode<string>("Yankee"));
	stack.push(new MyNode<string>("Zulu"));
	
	cout << "List Size: " << stack.size() << endl;
	
	stack.printList();

	cout << stack.pop()->toString() << endl;
	cout << "List Size: " << stack.size() << endl;
	
	stack.printList();
}

void stackAsInt() {
	MyList<MyNode<int> > stack;
	int i = 0;
	cout << "Integer Stack:" << endl;
	
	for (i = 1; i < 27; i++) {
		stack.push(new MyNode<int>(i));
	}
	
	cout << "List Size: " << stack.size() << endl;
	
	stack.printList();

	cout << stack.pop()->toString() << endl;
	cout << "List Size: " << stack.size() << endl;
	
	stack.printList();
}

void stackAsChar() {
	MyList<MyNode<char> > stack;
	char c = 0;
	cout << "Character Stack:" << endl;
	
	for (c = 'A'; c < 'Z'+1; c++) {
		stack.push(new MyNode<char>(c));
	}
	
	cout << "List Size: " << stack.size() << endl;
	
	stack.printList();

	cout << stack.pop()->toString() << endl;
	cout << "List Size: " << stack.size() << endl;
	
	stack.printList();	
}


int main()
{
	stackAsString();
	cout << endl << endl;
	stackAsInt();
	cout << endl << endl;
	stackAsChar();
	cout << endl << endl;
	return 0;
}*/
