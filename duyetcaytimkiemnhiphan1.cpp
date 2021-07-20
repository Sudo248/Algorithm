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
        this -> right = NULL;
    }
};

Node* insertNode(int data, Node *root){
    if(root == NULL) return new Node(data);
    if(data < root->data) root -> left = insertNode(data, root -> left);
    else root ->right = insertNode(data, root ->right);
    return root;
}

Node* buildTree(){
    int n, data;
    cin >> n >> data;
    Node *root = new Node(data);
    for(int i=0;i<n-1;i++){
        cin >> data;
        insertNode(data, root);
    }
    return root;

}

void postOrder(Node *root){
    if(root == NULL) return;
    postOrder(root ->left);
    postOrder(root ->right);
    cout << root -> data << ' ';
}



void solve(){

    postOrder(buildTree());
    cout << endl;

}


int main(){
    faster
    int t;
    cin >> t;
    while(t--) solve();

    return 0;

}