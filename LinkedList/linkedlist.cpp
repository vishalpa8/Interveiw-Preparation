#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
#define val(a) a.begin(),a.end()
#define sze(a) a.size()
#define fast_io ios_base::sync_with_stdio(0); cin.tie(0)

class Node
{
public:
    int data;
    Node *next;

    Node(int data){
        this->data = data;
        next = NULL;
    }
};

void insertAtHead(Node* &head, int data){
    if(head == NULL){
        head = new Node(data);
        return;
    }
    Node* n = new Node(data);
    n->next = head;
    head = n;

    return;
}

void printLL(Node* head){
    while(head != NULL){
        cout << head->data << "-->";
        head = head->next;
    }
    cout << "\n";
}

void insertAtMiddle(Node* &head, int val, int pos){
    if(pos == 0){
        insertAtHead(head,val);
        return ;
    }
    Node* temp = head;
    while(--pos > 0){
        temp = temp->next;
    }
    Node* n = new Node(val);

    n->next = temp->next;
    temp->next = n;
}

int main(){
    fast_io;
    Node* head = NULL;

    insertAtHead(head,10);
    insertAtHead(head,20);
    insertAtHead(head,30);
    insertAtHead(head,40);
    insertAtHead(head,50);
    insertAtMiddle(head,60,3);


    printLL(head);




    return 0;
}