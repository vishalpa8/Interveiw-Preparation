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

void createList(Node* &head,int val){
    if(head == NULL){
        head = new Node(val);
        return;
    }
    
    Node* temp = head;

    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = new Node(val);
}

void printLL(Node* head){
    while(head != NULL){
        string val = "-->";
        if(head->next == NULL){
            val.clear();
            val.push_back(' ');
        }
        cout << head->data << val;
        head = head->next;
    }
    cout << "\n";
}

Node* merge(Node* a, Node* b){
    if(a == NULL){
        return b;
    }
    if(b == NULL){
        return a;
    }
    Node* c;
    if(a->data < b->data){
        c = a;
        c->next = merge(a->next,b);
    }
    else{
        c = b;
        c->next = merge(a,b->next);
    }

    return c;
}

Node* midPoint(Node* head){
    Node* slow = head;
    Node* fast = head->next;

    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

Node* mergeSort(Node* head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    Node* mid = midPoint(head);
    
    Node* start = head;
    Node* end = mid->next;
    mid->next = NULL;

    start = mergeSort(start);
    end = mergeSort(end);

    return merge(start,end);
}

int main(){
    fast_io;

    int n;
    cin >> n;
    Node* head = NULL;

    for(int i=0; i<n; i++){
        int data;
        cin >> data;
        createList(head,data);
    }
    printLL(head);
    head = mergeSort(head);
    printLL(head);



    return 0;
}