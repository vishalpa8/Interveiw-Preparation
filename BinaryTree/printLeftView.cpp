#include<iostream>
#include<vector>
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


//Recursive approach
void printLeftView(node* root, int d, vector<int> &v){
    if(root == NULL){
        return;
    }
    if(d == v.size()){
        v.push_back(root->data);
    }
    printLeftView(root->left,d+1,v);
    printLeftView(root->right,d+1,v);
}

//Iterative approach
vector<int> leftView(node *root){
    vector<int> ans;

    if(root==NULL)  return ans;
     
    queue<node*> q;
    q.push(root);
    
    while(q.size()){
       int a  = q.size();
       for(int i=0;i<a;i++){
           node* curr = q.front();
           q.pop();
           if(i==0)  ans.push_back(curr->data);
           if(curr->left) q.push(curr->left);
           if(curr->right) q.push(curr->right);
           
       }
   }

   return ans;
}


int main(){
    fast_io;
    node* root = buildTree();
    vector<int> ans;
    printLeftView(root,0,ans);

    for(auto a : ans){
        cout << a << " ";
    }
    ans.clear();
    cout << "\n";

    ans = leftView(root);
    for(auto a : ans){
        cout << a << " ";
    }

    return 0;
}