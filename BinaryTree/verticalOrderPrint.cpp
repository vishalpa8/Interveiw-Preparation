#include<iostream>
#include<vector>
#include<map>
#include<queue>
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

// Recursive approach which is good but not best for large input's
void traverseTree(node* root, int d, map<int,vector<int>> &mp){
    if(!root){
        return;
    }
    mp[d].push_back(root->data);
    traverseTree(root->left,d-1,mp);
    traverseTree(root->right,d+1,mp);
    
}

void verticalOrderPrint(node* root){
    map<int,vector<int>> mp;
    int d = 0;

    traverseTree(root,d,mp);
    for(auto a : mp){
        for(int v : a.second){
            cout << v << " ";
        }
        cout << endl;
    }
}

//Iterative approach which is better
void verticalOrder(node *root){
        map<int,vector<int>> mp;
        queue<pair<node*,int>> q;
        q.push({root,0});
      
        // traverse(root,d,mp);
        
        while(!q.empty()){
            auto a = q.front();
            q.pop();
            node* curr = a.first;
            int val = a.second;
            
            mp[val].push_back(curr->data);
            
            if(curr->left){
                q.push({curr->left,val-1});
            }
            if(curr->right){
                q.push({curr->right,val+1});
            }
        }
        
        for(auto a : mp){
            for(auto v : a.second){
                cout << v << " ";
            }
            cout << "\n";
        }
        
}

int main(){
    fast_io;
    node* root = buildTree();

    verticalOrder(root);        //Iterative Approach
    cout << "\n";
    verticalOrderPrint(root);   // Recursive Approach



    return 0;
}