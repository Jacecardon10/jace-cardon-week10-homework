#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <string>
using namespace std;

//TODO: Create your Node Struct and Queue class here
struct Node {
	string data;
	Node* next;
};


class Queue {
private:
	Node* front;
	Node* back;
	int count;

public:
	Queue() {
		front = nullptr;
		back = nullptr;
		count = 0;
	}

	~Queue() {
		while (!isEmpty()) {
			dequeue();
		}
	}

	void enqueue(string data) {
		Node* newNode = new Node();
		newNode->data = data;
		newNode->next = nullptr;

		if (isEmpty()) {
			front = newNode;
			back = newNode;
		}
		else {
			back->next = newNode;
			back = newNode;
		}
		count++;
	}

	void dequeue() {
		if (isEmpty()) {
			cout << endl << "Queue is empty. Cannot dequeue." << endl;
			return;
		}
		Node* temp = front;
		front = front->next;
		delete temp;
		count--;
	}

	string peek() {
		if (!isEmpty()) {
			return front->data;
		}
		else {
			return "";
		}
	}

	bool isEmpty() {
		if (front == nullptr){
			return true;
		}
		else {
			return false;
		}
	}

	int size() {
		return count;
	}

	void print() {
		if (isEmpty()) {
			cout << "The queue is empty... nothing to print" << endl;
		}
		else {
			Node* temp = front;
			while (temp != nullptr) {
				cout << "[" << temp->data << "]";
				temp = temp->next;
			}
			cout << endl;
		}
	}
};
#endif