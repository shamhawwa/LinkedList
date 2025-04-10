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

	int length() {
		int count = 0;
		Node* tmp = head;
		while (tmp != nullptr) {
			count++;
			tmp = tmp->next;
		}
		cout << "The length=" << count << endl;
		return count;
	}
	
	bool contains(int value) {
		if (search(value) != nullptr) {
			cout << "The value (" << value << ") was found! " << endl;
			return true;
		}
		else {
			cout << "The value (" << value << ") was not found! " << endl;
			return false;
		}
	}

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

	void removeHead() {
		if (isEmpty()) {
			cout << "The list is empty! " << endl;
			return;
		}
		Node* tmp = head->next;
		cout << "The first node (" << head->data << ") was removed successfully! " << endl;
		delete(head);
		head = tmp;
	}

	void removeTail() {
		if (isEmpty()) {
			cout << "The list is empty! " << endl;
		}
		else if (head->next==nullptr) {
			removeHead();
		}
		else {
			Node* tmp = head;
			while (tmp->next->next != nullptr) {
				tmp = tmp->next;
			}
			cout << "The last node (" << tmp->next->data << ") was removed successfully! " << endl;
			delete(tmp->next);
			tmp->next = nullptr;
		}
	}

	void removeElement(int value) {
		if (isEmpty()) {
			cout << "The list is empty! " << endl;
		}
		else if (head->data == value) {
			removeHead();
		}
		else {
			Node* tmp = head;
			while (tmp->next != nullptr && tmp->next->data != value) {
				tmp = tmp->next;
			}
			if(tmp->next==nullptr) {
				cout << "The value (" << value << ") was not found! " << endl;
			}
			else {
				Node* deleteNode = tmp->next;
				tmp->next = deleteNode->next;
				cout << "The node with the value (" << value << ") was removed successfully! " << endl;
				delete(deleteNode);
			}
		}
	}

	void removeAfterNode(int target) {
		if (isEmpty()) {
			cout << "The list is empty! " << endl;
		}
		else {
			Node* searchNode = search(target);
			if (searchNode == nullptr) {
				cout << "There's no node with the value: " << target << "! " << endl;
			}
			else if (searchNode->next == nullptr) {
				cout << "There's no node after (" << target << ")! " << endl;
			}
			else {
				Node* deleteNode = searchNode->next;
				searchNode->next = deleteNode->next;
				cout << "The node with the value (" << deleteNode->data << ") after (" << target << ") was removed successfully! " << endl;
				delete(deleteNode);
			}
		}
	}

	void printSLL() {
		if (isEmpty()) {
			cout << "The list is empty! " << endl;
			return;
		}
		Node* tmp = head;
		while (tmp != nullptr) {
			cout << tmp->data;
			if (tmp->next != nullptr) {
				cout << " -> ";
			}
			tmp = tmp->next;
		}
		cout << endl;
	}
};