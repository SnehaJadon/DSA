#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(int val){
        data = val;
        next = NULL;
    }
};
int length(Node* head){
    Node* temp = head;
    int count = 0;
    while(temp){
        count++;
        temp = temp->next;
    }
    return count;
}

void print(Node *head){
    Node* temp = head;
    while(temp){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<"null"<<"\n";
}

void insertionAtBeginning(Node *&head, int val){
    Node *node = new Node(val);
    node->next = head;
    head = node;
}

void insertionAtEnd(Node*& head, int val){
    //edge case if list is empty then it will be the first node
    if(head == nullptr){
        insertionAtBeginning(head, val);
        return;
    }
    Node* node = new Node(val);
    Node* temp = head;
    while(temp->next){
        temp = temp->next;
    }
    temp->next = node;
}

void insertionAtAnyPosition(Node*& head, int position, int val){
    //edge case
    int len = length(head);
    if(position > len){
        cout<<"Invalid insertion"<<endl;
        return;
    }
    if(position == len){
        insertionAtEnd(head, val);
        return;
    }
    if(position == 1){
        insertionAtBeginning(head, val);
        return;
    }
    Node* node = new Node(val);
    Node* temp = head;

    for(int i=1; i<position-1; i++){
        temp = temp->next;
    }
    node->next = temp->next;
    temp->next = node;

}

void deleteAtHead(Node*& head){
    Node* todelete = head;
    head = head->next;
    delete todelete;
}

void deleteAtEnd(Node*& head){
    if(head == nullptr) return ;
    Node* temp = head;
    while(temp->next->next){
        temp = temp -> next;
    }
    temp->next = nullptr;
}

int main(){

    Node* head = NULL;
    insertionAtBeginning(head, 40);
    insertionAtBeginning(head, 30);
    insertionAtBeginning(head, 20);
    insertionAtBeginning(head, 10);
    print(head);

    insertionAtEnd(head,50);
    insertionAtEnd(head,60);
    print(head);

    insertionAtAnyPosition(head, 4, 35);
    print(head);

    cout<<length(head)<<endl;

    insertionAtAnyPosition(head, 7, 35);
    print(head);
    insertionAtAnyPosition(head, 9, 35);
    print(head);

    deleteAtHead(head);
    print(head);

    deleteAtEnd(head);
    deleteAtEnd(head);
    print(head);

    return 0;
}