#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
#define val(a) a.begin(), a.end()
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

void levelOrderPrint(node *root){
    queue<node *> qu;
    qu.push(root);
    qu.push(NULL);

    while (!qu.empty())
    {
        node *temp = qu.front();
        if (temp == NULL)
        {
            cout << "\n";
            qu.pop();

            if (!qu.empty())
            {
                qu.push(NULL);
            }
        }
        else
        {
            qu.pop();
            cout << temp->data << " ";
            if (temp->left)
            {
                qu.push(temp->left);
            }
            if (temp->right)
            {
                qu.push(temp->right);
            }
        }
    }

    return;
}


node* levelOrderBuild(){
    int d;
    cin >> d;

    node *root = new node(d);

    queue<node *> qu;
    qu.push(root);

    while (!qu.empty())
    {
        node *temp = qu.front();
        qu.pop();
        int c1, c2;
        cin >> c1 >> c2;

        if (c1 != -1)
        {
            temp->left = new node(c1);
            qu.push(temp->left);
        }
        if (c2 != -1)
        {
            temp->right = new node(c2);
            qu.push(temp->right);
        }
    }

    return root;
}

int main()
{
    fast_io;

    node *root = levelOrderBuild();
    levelOrderPrint(root);

    return 0;
}