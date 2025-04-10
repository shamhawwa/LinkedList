#include <iostream>
using namespace std;

class SinglyLinkedList {

	struct Node {
		int data;
		Node* next;
	public:
		Node() {
			data = 0;
			next = nullptr;
		}
		Node(int value, Node* ptr = nullptr) {
			data = value;
		}
	};

	Node* head;
public:
	SinglyLinkedList() {
		head = nullptr;
	}

};