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

Node* Kreverse(Node* head, int k){
    Node* temp = head, *prev = NULL, *curr = NULL;
    int cnt = 1;

    if(head == NULL){
        return NULL;
    }

    while(temp != NULL && cnt <= k){
        curr = temp->next;
        temp->next = prev;
        prev = temp;
        temp = curr;
        cnt++;
    }

    if(curr != NULL){
        head->next = Kreverse(curr,k);
    }

    return prev;
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
    head = Kreverse(head,3);
    printLL(head);


    return 0;
}