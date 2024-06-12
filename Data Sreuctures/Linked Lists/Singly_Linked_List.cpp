#include <iostream>
using namespace std;

class Node{
public:
int data; 
Node* next;

};

void printList( Node* n){

//Iterate till n = NULL
while (n != NULL)
{
    //print data
    cout<< n->data<<" ";
    n = n->next;

}
cout<<endl;
}

void appendNode(Node** head_ref, int new_data){ /*When you pass a pointer to a function, you can change the 
                                                contents of the memory location that the pointer is pointing
                                                 to. However, if you want to modify the pointer itself (i.e., 
                                                 make it point to a different memory location), you need to pass 
                                                 a pointer to the pointer. This concept is known as "pointer to pointer.*/
   //Alocate memory for new node
   Node* newnode = new Node();
   newnode->data = new_data;
   newnode->next = NULL;

      // If the list is empty, make the new node the head
    if (*head_ref == NULL) {    
        *head_ref = newnode;
        return;
    }

    Node* temp = *head_ref;
    while (temp->next != NULL)
    {
        temp= temp->next;
    }
    temp->next = newnode;
}


void deleteNode( Node** head_ref, int value){
    Node* temp = *head_ref;
    Node* prev = NULL;


if(temp != NULL && temp->data == value){
        *head_ref= temp->next;
        delete temp;
}
while(temp != NULL && temp->data != value){
        prev = temp;
        temp = temp->next;
}
if(temp == NULL){
    return;
}
    prev->next = temp->next;
    delete temp;

}

void searchElement(Node* head_ref, int val) {
    Node* temp = head_ref;

    // Check if the list is empty
    if (temp == NULL) {
        cout << "List is empty" << endl;
        return;
    }

    // Iterate through the list to find the element
    while (temp != NULL && temp->data != val) {
        temp = temp->next;
    }

    // Check if the element was found
    if (temp != NULL && temp->data == val) {
        cout << "Element Found" << endl;
    } else {
        cout << "Element Not Found" << endl;
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
head->next = second;

second->data = 4;
second->next = third;

third->data = 6;
third->next = NULL;

printList(head);
appendNode(&head, 90);
appendNode(&head, 100);
printList(head);
deleteNode(&head, 4);
printList(head);
searchElement(head, 5);

}