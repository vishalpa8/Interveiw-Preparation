#include<iostream>
using namespace std;
typedef unsigned long long ll;
#define val(a) a.begin(),a.end()
#define sze(a) a.size()
#define fast_io ios_base::sync_with_stdio(0); cin.tie(0)

class node
{

public:
    int data;
    node *left;
    node *right;

    node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};
class Pair
{
public:
    int exc;
    int inc;
};

node *buildTree()
{
    int d;
    cin >> d;

    if (d == -1)
    {
        return NULL;
    }

    node *n = new node(d);
    n->left = buildTree();
    n->right = buildTree();

    return n;
}
/*
    1
    2 3 
    4 5 6 
*/

// 1 2 3 4 5 -1 6 -1 -1 7 8 -1 -1 -1 -1 9 10 -1 -1 -1 -1

void printKNodeLevel(node* root, int k){
    if(!root){
        return;
    }
    if(k == 0){
        cout << root->data << " ";
        return;
    }

    printKNodeLevel(root->left,k-1);
    printKNodeLevel(root->right,k-1);

}

int printNodeAtDistanceK(node* root, node* target,int k){
    if(!root){
        return -1;
    }

    if(root == target){
        printKNodeLevel(target,k);
        return 0;
    }
    int dl = printNodeAtDistanceK(root->left,target,k);
    if(dl != -1){
        if(dl + 1 == k){
            cout << root->data << " ";
        }
        else{
            printKNodeLevel(root->right,k-2-dl);
        }

        return 1 + dl;
    }

    int dr = printNodeAtDistanceK(root->right, target, k);
    if (dr != -1){
        if (dr + 1 == k){
            cout << root->data << " ";
        }
        else{
            printKNodeLevel(root->left, k - 2 - dr);
        }

        return 1 + dr;
    }

    return -1;
}

int main(){
    fast_io;
    node* root = buildTree();
    printNodeAtDistanceK(root,root->left->right,2);



    return 0;
}