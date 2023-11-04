#include<iostream>
#include<queue>
using namespace std;
typedef unsigned long long ll;
#define val(a) a.begin(),a.end()
#define sze(a) a.size()
#define fast_io ios_base::sync_with_stdio(0); cin.tie(0)

// Here we don't have to choose either their children and their parent to find the max;

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
class Pair{
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

Pair maxSum(node* root){
    Pair p;
    if(root == NULL){
        p.inc = p.exc = 0;
        return p;
    }
    Pair left = maxSum(root->left);
    Pair right = maxSum(root->right);

    p.inc = root->data + left.exc + right.exc;
    p.exc = max(left.inc,left.exc) + max(right.exc,right.inc); 

    return p;
}

int main(){
    fast_io;

    node* root = buildTree();
    Pair p = maxSum(root);

    cout << max(p.inc,p.exc);


    return 0;
}