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

void levelOrderPrint(node *root)
{
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

void levelOrderPr(node *root)
{
    queue<node *> q;
    q.push(root);
    cout << root->data << "\n";

    while (!q.empty())
    {
        int size = q.size();

        for (int i = 0; i < size; i++)
        {
            node *temp = q.front();
            q.pop();
            if (temp->left != NULL)
            {
                cout << temp->left->data << " ";
                q.push(temp->left);
            }
            if (temp->right != NULL)
            {
                cout << temp->right->data << " ";
                q.push(temp->right);
            }
        }
        cout << "\n";
    }
}

int main()
{
    fast_io;

    node *root = buildTree();
    levelOrderPrint(root);

    return 0;
}