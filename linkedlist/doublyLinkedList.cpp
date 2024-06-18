
#include <iostream>
using namespace std;

//creating a structure
class Node{
    public:
    int data;
    Node*next;
    Node*prev;
    
    
    //constructor
    
    Node(int d){
        this->data=d;
        this->next=NULL;
        this->prev=NULL;
    }
    ~Node(){
        int val=this->data;
        if(next!=NULL){
            delete next;
            next=NULL;
        }
        cout << "Deleted node with data: " << val << endl;
    }
};

//travesing a linked list



void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}


//insertion at head

void insertAtHead(Node*&head,Node*&tail,int d){
    
    if(head==NULL){
        Node*temp=new Node(d);
        head=temp;
        tail=temp;
    }
    
    else{
        Node*temp=new Node(d);
        temp->next=head;
        head->prev=temp;
        head=temp;
    }
    
}

//TAIL
void insertAtTail(Node*&head,Node*&tail,int d){
    if(tail==NULL){
    Node*temp=new Node(d);
    tail=temp;
    head=temp;
    }
    else{
    Node*temp=new Node(d);
    tail->next=temp;
    temp->prev=temp;
    tail=temp;
    }
    cout<<endl;
}

//inserting at perticular position

void insertAtpostion(Node* &head,Node* &tail,int position,int  d){
    //insert at sraart
    if(position==1){
        insertAtHead(head,tail,d);
        return;
    }
    //traversing a node
    Node*temp=new Node(d);
    int cnt=1;
     while (cnt < position - 1 && temp != NULL) {
        temp = temp->next;
        cnt++;
    }
    
    //inserting at last
     if(temp -> next == NULL) {
        insertAtTail(tail,head,d);
        return ;
    }
     //creating a node for d
    Node* nodeToInsert = new Node(d);

    nodeToInsert ->next = temp -> next;
    temp -> next -> prev = nodeToInsert;
    temp -> next = nodeToInsert;
    nodeToInsert -> prev = temp;
}
//deleting a head

void deleteAtHead(Node*&head,Node*&tail,int d){
    if(head==NULL){
        return;
    }
    //travesing a list
    Node*temp=head;
    head->next=head;
    
    if(head!=NULL){
        head->prev=NULL;
    }
    else{
        tail=NULL;
    }
    temp->next=NULL;
    delete temp;
}


void deleteAtTail(Node*&head,Node*&tail,int d){
    if(tail==NULL){
        return;
    }
    //travesing a list
    Node*temp=head;
    tail->prev=tail;
    
    if(tail!=NULL){
        tail->next=NULL;
    }
    else{
        head=NULL;
    }
    temp->prev=NULL;
    delete temp;
}


void deletAtMiddle(Node*& head, Node*& tail, int position,int d){
    if(head==NULL){
       deleteAtHead(head, tail,d);
        return;
    }
    Node* temp=head;
    int cnt=1;
    
    
     while (cnt < position && temp != NULL) {
        temp = temp->next;
        cnt++;
    }
    
    if (temp == NULL) {
        cout << "Position out of bounds" << endl;
        return;
    }
    if (temp->next == NULL) {
        deleteAtTail(head, tail,d);
        return;
    }
    
    
temp->prev->next=temp->next;
temp->prev->next=temp->prev;

temp->next=NULL;
temp->prev=NULL;

delete temp;
}






int main() {
    Node*head=NULL;
    Node*tail=NULL;
    printList(head);
    
    insertAtHead(head,tail,11);;
    //printList(head);
    cout<<endl;
    
    insertAtHead(head,tail,12);;
    printList(head);
    cout <<endl;
    
    insertAtTail(head,tail,10);
    printList(head);
    cout<<endl;
    
    insertAtTail(head,tail,9);
    printList(head);
    cout<<endl;
    
    
    //insertAtpostion(head,tail,2,8);
    //printList(head);
    
    
    deleteAtHead(head,tail,12);
    printList(head);
    
    

    return 0;
}