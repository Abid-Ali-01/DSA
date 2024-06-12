#include <iostream>
using namespace std;

class Node{
public:
int data; 
Node* next;


};

void printList(Node* head) {
    if (head == NULL) return; //Check ensures that the function does not attempt to print an empty list

    Node* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head); /*The loop continues until temp points back to the head node,
                            indicating that we have completed one full traversal of the circular 
                            linked list.*/
    cout << endl;
}

int main (){

Node* head = NULL;
Node* second = NULL;
Node* third = NULL;



head = new Node();
second = new Node();
third = new Node();

head->data = 2;
head->next = second;

second->data = 4;
second->next = third;

third->data = 6;
third->next = head;

printList(head);

}