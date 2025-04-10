#include <iostream>
using namespace std;

class SinglyLinkedList {

	struct Node {
		int data;
		Node* next;
	public:
		Node(): data(0), next(nullptr){}
		Node(int value, Node* ptr=nullptr):data(value),next(ptr){}
	};

	Node* head;
	bool isEmpty() {
		return head == nullptr;
	}
	Node* search(int target) {
		Node* tmp = head;
		while (tmp != nullptr && tmp->data!=target) {
			tmp = tmp->next;
		}
		return tmp;
	}
public:
	SinglyLinkedList(): head(nullptr){}

	void addToHead(int value) {
		head = new Node(value,head);
		cout << "The value (" << value << ") was added! " << endl;
	}

	void addToTail(int value) {
		if (isEmpty()) {
			head = new Node(value);
		}
		else {
			Node* tmp = head;
			while (tmp->next != nullptr) {
				tmp = tmp->next;
			}
			tmp->next = new Node(value);
		}
		cout << "The value (" << value << ") was added! " << endl;
	}

	void addAfterNode(int target, int newValue) {
		if (isEmpty()) {
			cout << "The list is empty, adding (" << newValue << ") as a first node! " << endl;
			addToHead(newValue);
		}
		else {
			Node* targetNode = search(target);
			if (targetNode == nullptr) {
				cout << "There's no node with the value: " << target << "!" << endl;
			}
			else {
				Node* newNode = new Node(newValue, targetNode->next);
				targetNode->next = newNode;
				cout << "The value (" << newValue << ") was added after (" <<target<<")! " << endl;
			}
		}
	}


};