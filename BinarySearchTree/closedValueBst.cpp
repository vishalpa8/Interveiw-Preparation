#include<iostream>
#include<vector>
using namespace std;
typedef unsigned long long ll;
#define val(a) a.begin(),a.end()
#define sze(a) a.size()
#define fast_io ios_base::sync_with_stdio(0); cin.tie(0)

class Node{
    public:
        int data;
        Node* left;
        Node* right;
        
        Node(int value){
            this->data = value;
            left = right = NULL;
        }
};

Node* insert(Node* root, int value){
    if(root == NULL){
        return new Node(value);
    }

    if(value < root->data){
        root->left = insert(root->left,value);
    }
    else
        root->right = insert(root->right,value);

    return root;
}

int closestValue(Node* root, int key){
    int closest;
    int diff = INT8_MAX;

    Node* temp = root;

    while(temp != NULL){
        int current = abs(temp->data - key);
        if(current == 0){
            return temp->data;
        }
        
        if(current < diff){
            diff = current;
            closest = temp->data;
        }

        if(temp->data < key){
            temp = temp->right;
        }

        else{
            temp = temp->left;
        }

    }

    return closest;
}

int main(){
    fast_io;

    Node* root = NULL;
    int arr[] = {15,4,17,1,7,12};

    for(int x : arr){
        root = insert(root,x);
    }

    cout << closestValue(root,2);


    return 0;
}