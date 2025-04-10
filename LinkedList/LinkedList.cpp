#include <iostream>
#include "SinglyLinkedList.cpp"
#include "DoublyLinkedList.cpp"
using namespace std;

int main()
{
    SinglyLinkedList sll;
    cout << "-----------------------------------------------\n"<<"Singly Linked List Example: \n";

    sll.addToHead(1);
    sll.addToTail(2);
    sll.addToTail(4);
    sll.addToTail(5);
    sll.addToTail(6);
    sll.printSLL();

    sll.length();
    sll.contains(3);

    sll.addAfterNode(2, 3);
    sll.printSLL();
    sll.contains(3);

    sll.removeHead();
    sll.printSLL();
    sll.removeTail();
    sll.printSLL();
    sll.removeElement(4);
    sll.printSLL();
    sll.removeAfterNode(4);
    sll.removeAfterNode(3);
    sll.printSLL();
    sll.length();

    cout << "-----------------------------------------------\n"<<"Doubly Linked List Example: \n";
    DoublyLinkedList dll;
    dll.addToHead(1);
    dll.addToTail(2);
    dll.addToTail(3);
    dll.addToTail(4);
    dll.addToTail(5);
    dll.addToTail(6);
    dll.addToTail(7);
    dll.addToTail(8);
    dll.printDLLForward();
    dll.printDLLBackward();

    dll.addAfterNode(8, 10);
    dll.printDLLForward();

    dll.contains(9);
    dll.addBeforeNode(10, 9);
    dll.printDLLForward();

    dll.contains(9);
    dll.length();

    dll.removeHead();
    dll.printDLLForward();
    dll.removeTail();
    dll.printDLLForward();
    dll.removeElement(2);
    dll.printDLLForward();
    dll.removeAfterNode(5);
    dll.printDLLForward();
    dll.removeBeforeNode(8);
    dll.printDLLForward();
    dll.length();
    cout << "-----------------------------------------------\n";
    return 0;
}
