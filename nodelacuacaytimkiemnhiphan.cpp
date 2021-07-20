#include<bits/stdc++.h>
#define faster ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
using namespace std;
typedef long long ll;

struct Node{
    int data;
    Node *left, *right;

    Node(int data){
        this -> data = data;
        this -> left = NULL;
        this -> right = NULL;
    }
};

Node* insertNode(int data, Node* root){
    if(root == NULL){
        return new Node(data); 
    }
    if(data < root ->data) root -> left = insertNode(data, root ->left);
    else root ->right = insertNode(data, root ->right);

    return root;
}

bool isLeaf(Node *node){
    return (node != NULL && node ->left ==  NULL && node ->right == NULL);
}

void showLeafNode(Node *root){
    if(root == NULL) return;
    if(isLeaf(root)) cout << root ->data << ' ';
    else{
        showLeafNode(root ->left);
        showLeafNode(root ->right);
    }
}

void solve(){

    int n;
    cin >> n;
    Node *root = NULL;
    for(int i=0;i<n;i++){
        int data;
        cin >> data;
        root = insertNode(data, root);
    }
    showLeafNode(root);
    cout << endl;

}


int main(){
    faster
    int t;
    cin >> t;
    while(t--) solve();

    return 0;

}