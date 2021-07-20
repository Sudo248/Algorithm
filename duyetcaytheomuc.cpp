#include<bits/stdc++.h>
#define faster ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
using namespace std;
typedef long long ll;
int n;
int to_int(string s){
    int res = 0;
    for(char &c:s) res = res*10+(c-'0');
    return res;
}

struct Node{
    int data;
    Node* left;
    Node* right;
    
};

Node* newNode(int data){
    Node* tmp = new Node;
    tmp -> data = data;
    tmp -> left = NULL;
    tmp -> right = NULL;
    return tmp;
}

Node* BuildTree(){
    Node* root = NULL;
    map<int,Node*> hasNode;
    for(int i=0;i<n;i++){
        int ro, value;
        char branch;
        cin >> ro >> value >> branch;
        if(hasNode.find(ro) == hasNode.end()){
            Node* tmp = newNode(ro);
            hasNode[ro] = tmp;
            if(root == NULL) root = tmp;
        }
        Node* currentNode = hasNode[ro];
        Node* tmp = newNode(value);
        if(branch == 'L') currentNode->left = tmp;
        else currentNode->right = tmp;
        hasNode[value] = tmp; 
    }
    
    return root;
}

void levelOder(Node* root){
    if (root == NULL) 
		return;       
    queue<Node*> q;       
    q.push(root);  
    while (q.empty() == false) {        
        Node *node = q.front(); 
        cout << node->data << " "; 
        q.pop();          
        if (node->left != NULL) 
            q.push(node->left);          
        if (node->right != NULL) 
            q.push(node->right); 
    }
}

void solve(){  
    
    cin >> n;
    Node* root = BuildTree();
    levelOder(root);
    cout << endl;

}


int main(){
    faster
    int t;
    cin >> t;
    while(t--) solve();

    return 0;

}