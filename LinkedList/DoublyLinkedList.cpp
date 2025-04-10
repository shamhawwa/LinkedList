#include <iostream>
using namespace std;

class DoublyLinkedList {

	struct Node {
		int data;
		Node* next;
		Node* previous;
	public:
		Node() : data(0), next(nullptr), previous(nullptr) {}
		Node(int value, Node* nxt = nullptr,Node* pre=nullptr ) :data(value), next(nxt), previous(pre){}
	};

	Node* head;
	bool isEmpty() {
		return head == nullptr;
	}
	Node* search(int target) {
		Node* tmp = head;
		while (tmp != nullptr && tmp->data != target) {
			tmp = tmp->next;
		}
		return tmp;
	}
public:
	DoublyLinkedList(): head(nullptr){};

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
		head = new Node(value, head, nullptr);
		if (head->next != nullptr) {
			head->next->previous = head;
		}
		cout << "The value (" << value << ") was added! " << endl;
	}

	void addToTail(int value) {
		if (isEmpty()) {
			addToHead(value);
			return;
		}
		Node* tmp = head;
		while (tmp->next != nullptr) {
			tmp = tmp->next;
		}
		tmp->next = new Node(value,nullptr,tmp);
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
				Node* newNode = new Node(newValue, targetNode->next,targetNode);
				if (targetNode->next != nullptr) {
					targetNode->next->previous = newNode;
				}
				targetNode->next = newNode;
				cout << "The value (" << newValue << ") was added after (" << target << ")! " << endl;
			}
		}
	}

	void addBeforeNode(int target, int newValue) {
		if (isEmpty()) {
			cout << "The list is empty, adding (" << newValue << ") as a first node! " << endl;
			addToHead(newValue);
		}
		else {
			Node* targetNode = search(target);
			if (targetNode == nullptr) {
				cout << "There's no node with the value: " << target << "!" << endl;
			}
			else if (targetNode->previous == nullptr) {
				addToHead(newValue);
			}
			else {
				Node* newNode = new Node(newValue, targetNode, targetNode->previous);
				targetNode->previous->next = newNode;
				targetNode->previous = newNode;
				cout << "The value (" << newValue << ") was added before (" << target << ")! " << endl;
			}
		}
	}

	void removeHead() {
		if (isEmpty()) {
			cout << "The list is empty! " << endl;
			return;
		}
		Node* tmp = head;
		cout << "The first node (" << head->data << ") was removed successfully! " << endl;
		head = head->next;
		if (head != nullptr) {
			head->previous = nullptr;
		}
		delete(tmp);
	}

	void removeTail() {
		if (isEmpty()) {
			cout << "The list is empty! " << endl;
		}
		else if (head->next == nullptr) {
			removeHead();
		}
		else {
			Node* tmp = head;
			while (tmp->next != nullptr) {
				tmp = tmp->next;
			}
			cout << "The last node (" << tmp->data << ") was removed successfully! " << endl;
			tmp->previous->next = nullptr;
			delete(tmp);
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
			if (tmp->next == nullptr) {
				cout << "The value (" << value << ") was not found! " << endl;
			}
			else {
				Node* deleteNode = tmp->next;
				tmp->next = deleteNode->next;
				if (deleteNode->next != nullptr) {
					deleteNode->next->previous = tmp;
				}
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
				if (deleteNode->next != nullptr) {
					deleteNode->next->previous = searchNode;
				}
				cout << "The node with the value (" << deleteNode->data << ") after (" << target << ") was removed successfully! " << endl;
				delete(deleteNode);
			}
		}
	}

	void removeBeforeNode(int target) {
		if (isEmpty()) {
			cout << "The list is empty! " << endl;
		}
		else {
			Node* searchNode = search(target);
			if (searchNode == nullptr) {
				cout << "There's no node with the value: " << target << "! " << endl;
			}
			else if (searchNode->previous == nullptr) {
				cout << "The node with the value (" << target << ") is the first node in the list! " << endl;
			}
			else {
				Node* deleteNode = searchNode->previous;
				if (deleteNode == head) {
					head = searchNode;
				}
				searchNode->previous = deleteNode->previous;
				if (deleteNode->previous != nullptr) {
					deleteNode->previous->next = searchNode;
				}
				cout << "The node with the value (" << deleteNode->data << ") before (" << target << ") was removed successfully! " << endl;
				delete(deleteNode);
			}
		}
	}

	void printDLLForward() {
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

	void printDLLBackward() {
		if (isEmpty()) {
			cout << "The list is empty! " << endl;
			return;
		}
		Node* tmp = head;
		while (tmp->next != nullptr) {
			tmp = tmp->next;
		}
		while (tmp != nullptr) {
			cout << tmp->data;
			if (tmp->previous != nullptr) {
				cout << " -> ";
			}
			tmp = tmp->previous;
		}
		cout << endl;
	}
};