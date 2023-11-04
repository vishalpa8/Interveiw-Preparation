#include<bits/stdc++.h>
using namespace std;

//Input : 1 2 4 -1 -1 5 7 -1 -1 -1 3 -1 6 -1 -1

class node
{

public:
	int data;
	node *left;
	node *right;

	node(int data){
		this->data = data;
		this->left = NULL;
		this->right = NULL;
	}
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
//variable type then class name.

int main(){


	return 0;
}
