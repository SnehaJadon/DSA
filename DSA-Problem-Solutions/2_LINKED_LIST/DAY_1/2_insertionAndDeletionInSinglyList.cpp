#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(int val){
        data=val;
        next=NULL;
    }
};
int count(Node *head);
void insertionAtBeginning(Node*& head, int data){
    Node* node=new Node(data);
    node->next=head;
    head=node;
    return;
}
void insertionAtEnd(Node*& head, int data){
    if(head == NULL){
        insertionAtBeginning(head, data);
        return;
    }
    Node* temp =  head;
    while(temp->next != NULL){
        temp=temp->next;
    }
    Node* node=new Node(data);
    temp->next=node;
    return;
}
void insertionAtAnyPosition(Node*& head, int data, int position){
    if(position > ((count(head))+1)){
    cout << "Invalid Insertion "<< endl;
        return;
    }
    if(position == 1){
        insertionAtBeginning(head,data);
        return;
    }
    int length = count(head);
    if(position == length+1){
        insertionAtEnd(head,data);
    }
    Node* temp=head;
    for(int i=1;i<position-1;i++){
        temp=temp->next;
    }
    Node* node=new Node(data);
    node->next=temp->next;
    temp->next=node;
    return;
}
void deleteAtHead(Node *&head){
    Node *todelete=head;
    head=head->next;
    delete todelete;
}
void deleteAtEnd(Node *&head){
    Node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    Node *todelete=temp;
    delete todelete;
}
void deletion(Node *&head, int data){
    if(head==NULL){
        return;
    }
    if(head->next==NULL){
        deleteAtHead(head);
        return;
    }
    Node *temp=head;
    while(temp->next->data != data){
        temp=temp->next;
    }
    Node *todelete = temp->next;
    temp->next=temp->next->next;
    delete todelete;
}
void traversal(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }cout<<"null";
}
void reversePrint(Node *temp){
    if(temp == NULL) return;
    reversePrint(temp->next);
    cout<<temp->data<<"->";
}
int count(Node* head){
    Node* temp=head;
    int cnt=0;
    while(temp != NULL){
        cnt++;
        temp=temp->next;
    }
    return cnt;
}
bool search(Node *head, int key){
    Node *temp=head;
    while(temp != NULL){
        if(temp->data == key){
            return true;
        }
        temp=temp->next;
    }
    return false;
}

int main(){

    Node *head=NULL;
    insertionAtBeginning(head, 10);
    insertionAtEnd(head, 20);
    insertionAtEnd(head, 30);
    insertionAtEnd(head, 40);
    insertionAtAnyPosition(head, 25, 3);
    deletion(head,25);
    // deleteAtHead(head);
    // deleteAtEnd(head);
    traversal(head);
    // reversePrint(head);

    cout<<"\n"<<count(head)<<endl;
    cout<<search(head,25)<<endl;
    cout<<search(head,30)<<endl;



    return 0;
}