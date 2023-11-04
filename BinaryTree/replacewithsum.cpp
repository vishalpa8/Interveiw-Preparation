#include<bits/stdc++.h>
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

    node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};

// Input : 1 2 4 -1 -1 5 7 -1 -1 -1 3 -1 6 -1 -1
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

int replaceWithSum(node* root){
    if(root == NULL){
        return 0;
    }
    if(root->left == NULL and root->right == NULL){
        return root->data;
    }
    int left = replaceWithSum(root->left);
    int right = replaceWithSum(root->right);

    int temp = root->data;
    root->data = left + right;

    return root->data + temp;

}

int main(){
    fast_io;
    node* root = buildTree();
    // 4,1,6,0,2,5,7,null,null,null,3,null,null,null,8
    

    return 0;
}