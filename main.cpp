#include <iostream>
using namespace std;


class Node {
public:
    int value;
    Node* next;
};


//function to print the list out
void print_list(Node* head) {
    while(head != NULL) {
        cout<<head->value<<endl;
        head = head->next;
    }
}

//function to insert node at beginning
void InsertAttheFront(Node**head, int newValue) {
    //1, Prepare a newNode
    Node* newNode = new Node();
    //we set the value of hte new node to the value we passed into the function
    newNode->value = newValue;
    //2. We put it in the fron of current head
    newNode->next = *head;
    //3. Move head of hte list to point to the new Node
    *head = newNode;
}

//function to inset at the end
void InsertAttheEnd(Node**head, int newValue) {
    //1. Prepare a newNode
    Node* newNode = new Node();
    newNode->value = newValue;
    newNode->next = NULL;
    //2. check the linked list if its empty, new node will be head if its empty
    if(*head == NULL) {
        *head = newNode;
        return;
    }
    //3. Find the last node
    Node* last = *head;
    while(last->next != NULL) {
        last = last->next;
    }
    //4. Inset the new node at the end
    last->next = newNode;
}

//insert a node after a node
void InsertAfter(Node* prevnode, int newValue) {
  //1. check if the previous node is null
    if(prevnode == NULL) {
        cout<<"node cannot be NULL"<<endl;
        return;
    }
    //2. Prepare a newNode
    Node* newNode = new Node();
    newNode->value = newValue;
    //3. Insert the newnode after the previous
    newNode->next = prevnode->next;
    prevnode->next = newNode;
}

//deleing a node in a linked list
void DeleteNode(Node** head, int targetValue) {
    // Check if the list is empty
    if (*head == NULL) {
        cout << "List is empty, cannot delete." << endl;
        return;
    }

    // If the head node contains the target value
    if ((*head)->value == targetValue) {
        Node* temp = *head;
        *head = (*head)->next;
        delete temp;
        return;
    }

    Node* prev = *head;
    Node* current = (*head)->next;

    // Traverse the list to find the node with the target value
    while (current != NULL) {
        if (current->value == targetValue) {
            prev->next = current->next;
            delete current;
            return;
        }
        prev = current;
        current = current->next;
    }

    cout << "Node with value " << targetValue << " not found in the list." << endl;
}

//function to print the list in reverse order
void reverse(Node* head) {
    //the base case
    if(head == NULL) {
        return;
    }

    //print the list after head node
    reverse(head->next);
    //after everything else is printed, print head
    cout<<head->value<<" ";
}

int main()
{

    //we create the nodes for the linked list
    Node* head = new Node();
    Node* second = new Node();
    Node* third = new Node();
    Node* fourth = new Node();

    //we give the nodes a value and link them to the other node
    head->value = 1;
    head->next = second;
    second->value = 2;
    second->next = third;
    third->value = 3;
    third->next = fourth;
    fourth->value = 4;
    fourth->next = NULL;
    
    //calling function to insert node at front
    InsertAttheFront(&head, 0);
    InsertAfter(fourth, -4);
    InsertAttheEnd(&head, 5);
    DeleteNode(&head,2);


    //calling the function to print the list
    //0->1->2->4->-4->-5
    print_list(head);
    reverse(head);
    return 0;
}
