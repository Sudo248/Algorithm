#include<bits/stdc++.h>
#define faster ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
using namespace std;
typedef long long ll;

struct Node{
    int data;
    Node *left, *right;
    Node(int data){
        this ->data = data;
        this ->left = NULL;
        this ->right = NULL;
    }
};

Node* insertNode(int data, Node* root){
    if(root == NULL) return new Node(data);
    if(data < root ->data) root ->left = insertNode(data, root->left);
    else root ->right = insertNode(data, root->right);
    return root;
}

Node* buildTree(){
    int n;
    cin >> n;
    Node* root = NULL;
    int ro, data;
    char branch;
    for(int i=0;i<n;i++){
        cin >> ro >> data >> branch;
        if(root == NULL) root = insertNode(ro, root);
        insertNode(data, root);
    }
    return root;
}


void inOrder(Node *root){
    if(root == NULL) return;
    inOrder(root -> left);
    cout << root ->data << ' ';
    inOrder(root ->right);
}

void solve(){

    inOrder(buildTree());
    cout << endl;

}


int main(){
    faster
    int t;
    cin >> t;
    while(t--) solve();

    return 0;

}