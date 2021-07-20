#include<bits/stdc++.h>
#define faster ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
using namespace std;
typedef long long ll;

struct Node{
    char data;
    Node* left;
    Node* right;
};

Node* newNode(char val){
    Node* tmp = new Node;
    tmp->data = val;
    tmp->left = NULL;
    tmp-> right = NULL;
    return tmp;
}

bool isOperater(char c){
    return (c == '+' | c == '-' | c == '*' | c == '/');
}

Node* buildTree(string input){
    stack<Node*>st;
    Node *node1, *node2, *node;

    for(char &c:input){
        if(isOperater(c)){
            node = newNode(c);
            node1 = st.top(); st.pop();
            node2 = st.top(); st.pop();
            node->left = node2;
            node->right = node1;
            st.push(node);
        }
        else{
            node = newNode(c);
            st.push(node);
        }
    }

    return st.top();

}

void Inorder(Node* root){
    if(root == NULL) return;
    Inorder(root->left);
    cout << root -> data ;
    Inorder(root->right);
}

void solve(){

    string input;
    cin >> input;
    Inorder(buildTree(input));
    cout << endl;

}


int main(){
    faster
    int t;
    cin >> t;
    while(t--) solve();

    return 0;

}