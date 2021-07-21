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
        left = NULL;
        right = NULL;
    }
};

int res;

Node* insertNode(Node *root, int data){
    if(root == NULL) return new Node(data);
    if(data < root -> data) root -> left = insertNode(root -> left, data);
    else root -> right = insertNode(root -> right, data); 
    return root;
}

Node* buildTree(){
    int n, data;
    cin >> n >> data;
    Node *root = insertNode(NULL, data);
    for(int i = 0;i < n-1; i++){
        cin >> data;
        insertNode(root, data);
    }
    return root;
}

bool isMid(Node *root){
    return root -> left != NULL | root -> right != NULL;
}

void duyet(Node* root){
    if(root == NULL) return;
    if(isMid(root)) res++;
    if(root -> left != NULL) duyet(root -> left);
    if(root -> right != NULL) duyet(root -> right);
}

void solve(){

    res = 0;
    duyet(buildTree());
    cout << res << endl;

}

int main(){

    faster
    int t;
    cin >> t;
    while(t--) solve();

    return 0;
}