#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
#define val(a) a.begin(),a.end()
#define sze(a) a.size()
#define fast_io ios_base::sync_with_stdio(0); cin.tie(0)

class Node{
public:
    int data;
    Node *left;
    Node *right;

    Node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};

Node *buildTree()
{
    int d;
    cin >> d;

    if (d == -1)
    {
        return NULL;
    }

    Node *n = new Node(d);
    n->left = buildTree();
    n->right = buildTree();

    return n;
}

//Naive Approach
int height(Node* root){
    if(!root) return 0;

    int left = height(root->left);
    int right = height(root->right);

    return 1 + max(left,right);
}

int diameterOfTree(Node* root){
    if(!root) return 0;

    // 1 + in d1 is for Nodes, if you want only edges just remove +1 from d1 and it'll work fine.
    int d1 = 1 + height(root->left) + height(root->right);
    int d2 = diameterOfTree(root->left);
    int d3 = diameterOfTree(root->right);

    return max({d1,d2,d3});
}


//Optimal Approach
int res = 0;
int heightToDiamter(Node *root){
    if (!root)
    {
        return 0;
    }
    // int d1 = 1 + heightToDiamter(root->left) + heightToDiamter(root->right);
    int d2 = heightToDiamter(root->left);
    int d3 = heightToDiamter(root->right);
    res = max(res, d2 + d3 + 1);

    return 1 + max(d2, d3);
}

int diameter(Node *root){
    heightToDiamter(root);
    return res;
}

// More Optimized Code;
// this code is will give us a edges.
pair<int,int> diameterOfTre(Node* root){
    pair<int,int> val;
    if(!root) {
        val.first = val.second = 0;
        return val; 
    }
    pair<int,int> left = diameterOfTre(root->left);
    pair<int, int> right = diameterOfTre(root->right);

    val.second = 1 + max(left.second,right.second);

    int d1 = left.second + right.second;
    int d2 = left.first;
    int d3 = right.first;

    val.first = max({d1,d2,d3});

    return val;
}

int main(){
    fast_io;
    Node* root = buildTree();
    cout << diameter(root) << "\n";
    cout << diameterOfTree(root) << "\n";
    cout << diameterOfTre(root).first; // for Node just +1 in stdout and it'll work fine.

    return 0;
}