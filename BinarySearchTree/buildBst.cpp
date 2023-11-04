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

void printInorder(Node* root){
    if(!root){
        return;
    }

    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}

bool isPresent(Node *root,int key){
    
    if(!root){
        return false;
    }
    
    if(root->data == key){
        return true;
    }
    else if(root->data > key){
        return isPresent(root->left,key);
    }
    
    else{
        return isPresent(root->right,key);
    }
    
    return true;
}


int main(){
    fast_io;

    Node* root = NULL;
    int arr[] = {3,1,5,9,19,10,11,8,14};

    for(int x : arr){
        root = insert(root,x);
    }

    return 0;
}