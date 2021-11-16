#include <iostream>
#include <string>

using namespace std;

class Node {
    public:
    int data;
    Node* next;
};

void printl (Node* n){
    while(n != NULL) {
        cout<<n->data<<endl;
        n = n->next;
    }
}

void InsertFront(Node** head, int value){
    //Prepare New Node 
    Node* newNode = new Node;
    newNode->data = value;
    //Insert It In Front Of Current Head
    newNode->next = *head; // Pointer to Pointer 
    //Move Head Of The List To Point to newnode
    *head = newNode;
}

void InsertLast (Node** head, int value){
    // Prepare Node 
    Node* lastNode = new Node;
    lastNode->data = value;
    lastNode->next = NULL;
    // Check If Linked List Is Empty, If So Last Node wil Be the only node in it 
    if (*head == NULL){
        *head = lastNode;
        return;
    }
    // Find the last Node 
    Node* last = *head;
    while (last->next != NULL){
        last = last->next;
    }
    // Insert New Node at the end 
    last->next = lastNode;
}

void InsertAfter (Node* Previous, int value){
    //Check if the previous Node is NULL
    if (Previous == NULL){
        return;
    }
    // Prepare a New Node 
    Node* newNode = new Node;
    newNode->data = value;
    // Insert new node after previous node 
    newNode->next = Previous->next;
    Previous->next = newNode;

}

int main()
{
    Node* head = new Node;
    Node* second = new Node;
    Node* third = new Node;

    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = NULL;

    
   printl(head);

   return 0;
}