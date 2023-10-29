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

Node* recReverse(Node* head){
    if(head->next == NULL){
        return head;
    }
    Node* temp = recReverse(head->next);
    head->next->next = head;
    head->next = NULL;

    return temp;
}

Node* iterReverse(Node* head){
    Node* temp = head, *prev = NULL, *curr = NULL;

    while(temp != NULL){
        curr = temp->next;
        temp->next = prev;
        prev = temp;
        temp = curr;
    }

    return prev;
}


int main(){
    fast_io;
    Node* head = NULL;

    int n;
    cin >> n;

    while(n--){
        int data;
        cin >> data;
        createList(head,data);
    }

    printLL(head);
    head = recReverse(head);
    printLL(head);
    head = iterReverse(head);
    printLL(head);




    return 0;
}