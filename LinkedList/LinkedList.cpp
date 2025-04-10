#include <iostream>
#include "SinglyLinkedList.cpp"
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
    cout << "-----------------------------------------------\n";

    return 0;
}
