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

Node* buildTree(){
    int n;
    cin >> n;
    Node *root = NULL, *currentNode, *currentRoot;
    int r, data;
    char c;
    map<int, Node*>hasNode;

    for(int i = 0;i < n; i++){
        cin >> r >> data >> c;
        if(hasNode.find(r) == hasNode.end()){
            currentRoot = new Node(r);
            hasNode[r] = currentRoot;
            if(root == NULL) root = currentRoot;
        }else currentRoot = hasNode[r];
        currentNode = new Node(data);
        if(c == 'L') currentRoot -> left = currentNode;
        else currentRoot -> right = currentNode;
        hasNode[data] = currentNode;
    }

    return root;
}

void spiralOrder(Node *root){
    stack<Node*>leftToRight, rightToLeft;
    Node* tmp;
    rightToLeft.push(root);
    while(rightToLeft.size() | leftToRight.size()){
        if(leftToRight.empty()){
            while(rightToLeft.size()){
                tmp = rightToLeft.top(); rightToLeft.pop();
                cout << tmp->data << ' ';
                if(tmp->right != NULL) leftToRight.push(tmp->right);
                if(tmp->left != NULL) leftToRight.push(tmp->left);
            }
        }else{
            while(leftToRight.size()){
                tmp = leftToRight.top(); leftToRight.pop();
                cout << tmp->data << ' ';
                if(tmp->left != NULL) rightToLeft.push(tmp->left);
                if(tmp->right != NULL) rightToLeft.push(tmp->right);
            }
        }
    }
    cout << endl;
}

void solve(){

    spiralOrder(buildTree());
    
}

int main(){

    faster
    int t;
    cin >> t;
    while(t--) solve();

    return 0;
}