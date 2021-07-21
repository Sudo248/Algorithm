#include<bits/stdc++.h>
#define faster ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
using namespace std;
typedef long long ll;

struct Node{
    int data, level;
    Node *left, *right;
    Node(int d){
        data = d;
        level = 0;
        left = NULL;
        right = NULL;
    }
};

Node* insertNode(Node* root, int data){
    if(root == NULL) return new Node(data);
    if(data < root -> data) root -> left = insertNode(root->left, data);
    else root -> right = insertNode(root->right, data);
    return root;
}

Node* buildTree(){
    int n, data;
    cin >> n >> data;
    Node* root = insertNode(NULL, data);
    for(int i = 0;i <n-1;i++){
        cin >> data;
        insertNode(root, data);
    }

    return root;
}

int res;

void level(Node* root, int le){
    if(root == NULL) return;
    root -> level = le+1;
    res = max(res,le);
    if(root->left != NULL) level(root ->left, le+1);
    if(root -> right != NULL) level(root->right, le+1);
}


void solve(){

    res = 0;
    level(buildTree(),0);
    cout << res << endl;

}

int main(){

    faster
    int t;
    cin >> t;
    while(t--) solve();

    return 0;
}