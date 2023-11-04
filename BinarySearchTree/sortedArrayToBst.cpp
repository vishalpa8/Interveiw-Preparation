#include<iostream>
#include<vector>
using namespace std;
typedef unsigned long long ll;
#define val(a) a.begin(),a.end()
#define sze(a) a.size()
#define fast_io ios_base::sync_with_stdio(0); cin.tie(0)

class Node{
    public:
        int data;
        Node* left;
        Node* right;
        
        Node(int value){
            this->data = value;
            left = right = NULL;
        }
};

Node* arrayToBst(vector<int> arr,int start, int end){
    if(start > end) return NULL;

    int mid = (start + end)/2;
    Node* root = new Node(arr[mid]);

    root->left = arrayToBst(arr,start,mid-1);
    root->right = arrayToBst(arr,mid+1,end);

    return root;

}

void printInorder(Node* root){
    if(!root){
        return;
    }

    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}

int main(){
    fast_io;
    vector<int> v{1,2,5,6,9,11,10,29};

    Node* root = arrayToBst(v,0,v.size()-1);
    printInorder(root);


    return 0;
}