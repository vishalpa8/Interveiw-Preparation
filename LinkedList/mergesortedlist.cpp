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

Node* mergeList(Node* a, Node* b){
    if(a == NULL){
        return b;
    }
    if(b == NULL){
        return a;
    }
    Node* c;
    if(a->data < b->data){
        c = a;
        c->next = mergeList(a->next,b);
    }
    else{
        c = b;
        c->next = mergeList(a,b->next);
    }

    return c;
}

int main(){
    fast_io;
    Node* a = NULL;
    Node* b = NULL;

    int n,m;
    cin >> n >> m;

    for(int i=0; i<n; i++){
        int data;
        cin >> data;
        createList(a,data);
    }

    for(int i=0; i<m; i++){
        int data;
        cin >> data;
        createList(b,data);
    }

    a = mergeList(a,b);
    printLL(a);



    return 0;
}