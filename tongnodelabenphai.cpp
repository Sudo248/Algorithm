#include<bits/stdc++.h>
#define faster ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
using namespace std;
typedef long long ll;

struct Node{
    int data;
    Node *left, *right;
};

Node* newNode(int data){
    Node *tmp = new Node;
    tmp -> data = data;
    tmp -> left = NULL;
    tmp -> right = NULL;
    return tmp;
}

Node* buildTree(int n){
    map<int, Node*>hasNode;
    Node *root = NULL;
    int newRoot, data;
    char branch;
    for(int i=0;i<n;i++){
        cin >> newRoot >> data >> branch;
        if(hasNode.find(newRoot) == hasNode.end()){
            Node *tmp = newNode(newRoot);
            hasNode[newRoot] = tmp;
            if(root == NULL) root = tmp;
        }

        Node *currentNode = hasNode[newRoot];
        Node *tmp = newNode(data);
        if(branch == 'L') currentNode -> left = tmp;
        else currentNode -> right = tmp;
        hasNode[data] = tmp;
    }
    return root;
}

bool isLeaf(Node *node){
    return (node != NULL && node -> left ==  NULL && node -> right == NULL);
}

int sumRightLeaf(Node *root){
    if(root == NULL) return 0;
    int res = 0;
    if(isLeaf(root -> right)) res += root ->right -> data;
    res += sumRightLeaf(root -> left) + sumRightLeaf(root -> right);
    return res;
}

void solve(){

    int n;
    cin >> n;
    cout << sumRightLeaf(buildTree(n)) << endl;
    

}


int main(){
    faster
    int t;
    cin >> t;
    while(t--) solve();

    return 0;

}