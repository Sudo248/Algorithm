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

Node* buildTree(){
    int n;
    cin >> n;
    int r, data;
    char branch;
    Node *root = NULL, *currentNode, *newNode;
    map<int, Node*> check;
    for(int i=0;i<n;i++){
        cin >> r >> data >> branch;
        if(check.find(r) == check.end()){
            currentNode = new Node(r);
            check[r] = currentNode;
            if(root == NULL) root = currentNode;
        }
        else currentNode = check[r];
        newNode = new Node(data);
        if(branch == 'L') currentNode ->left = newNode;
        else currentNode -> right = newNode;
        check[data] = newNode;

    }
    return root;
}

void reveseLevelOrder(Node *root){
    if(root == NULL) return;

    queue<Node*>q;
    stack<int>st;
    q.push(root);
    Node* node;
    while(q.size()){
        node = q.front(); q.pop();
        st.push(node ->data);
        if(node ->right != NULL) q.push(node->right);
        if(node ->left != NULL) q.push(node -> left);
        
    }
    while(st.size()){
        cout << st.top() << ' ';
        st.pop();
    }
    cout << endl;
}

void solve(){

    reveseLevelOrder(buildTree());
    
}


int main(){
    faster
    int t;
    cin >> t;
    while(t--) solve();

    return 0;

}