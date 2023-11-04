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

    node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

node* buildTree()
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

pair<int,bool> heightBalanced(node* root){
    pair<int,bool> p, left, right;

    if(!root){
        p.first = 0;
        p.second = true;
        return p;
    }

    left = heightBalanced(root->left);
    right = heightBalanced(root->right);
    int height = 1 + max(left.first,right.first);

    if(abs(left.first-right.first) <= 1 and left.second && right.second){
        return make_pair(height,true);
    }

    return make_pair(height,false);

}


int main(){
    fast_io;

    node *root = buildTree();

    bool value = heightBalanced(root).second;

    if(value){
        cout << "Tree is Balanced";
    }
    else{
        cout << "Tree is not Balanced";
    }



    return 0;
}