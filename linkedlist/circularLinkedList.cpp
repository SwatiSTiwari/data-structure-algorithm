#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    // Constructor
    Node(int d) {
        this->data = d;
        this->next = nullptr;
    }

    ~Node() {
        int val = this->data;
        if (next != nullptr) {
            delete next;
            next = nullptr;
        }
    }
};

// Insertion at the head
void insertAtHead(Node*& head, int d) {
    Node* newNode = new Node(d);
    if (head == nullptr) {
        head = newNode;
        head->next = head;
    } else {
        Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
        head = newNode;
    }
}

// Insertion at the tail
void insertAtTail(Node*& head, int d) {
    Node* newNode = new Node(d);
    if (head == nullptr) {
        head = newNode;
        head->next = head;
    } else {
        Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
    }
}

// Display the circular linked list
void display(Node* head) {
    if (head == nullptr) {
        cout << "List is empty" << endl;
        return;
    }

    Node* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}



//deleting a node


void deleteNode(Node*&head,int val){
    //for empty
    if(head==NULL){
        cout<<"list is empty"<<endl;
    }
    
    else{
        Node*prev=head;
        Node*curr=prev->next;
        
        while(curr->data!=val){
            prev=curr;
            curr=curr->next;
        }
        
        prev->next=curr->next;
        if(head==NULL){
            prev=head;
        }
        curr->next=NULL;
        delete curr;
    }
    
    cout<<endl;
}
int main() {
    Node* head = nullptr;

    insertAtHead(head, 10);
    display(head);

    insertAtHead(head, 11);
    display(head);

    insertAtHead(head, 12);
    display(head);

    insertAtTail(head, 9);
    display(head);
    
    deleteNode(head,11);
    display(head);

    return 0;
}
