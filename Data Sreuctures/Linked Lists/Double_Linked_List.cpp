#include <iostream>
using namespace std;

class Node{
public:
int data; 
Node* next;
Node* prev;

};

void printList( Node* n){

//Iterate till n = NULL
while (n != NULL)
{
    //print data
    cout<< n->data<<endl;
    n = n->next;
}
}

int main (){

Node* head = NULL;
Node* second = NULL;
Node* third = NULL;



head = new Node();
second = new Node();
third = new Node();

head->data = 2;
head->prev = NULL;
head->next = second;

second->data = 4;
second->prev = head;
second->next = third;

third->data = 6;
third->prev = second;
third->next = NULL;

printList(head);

}