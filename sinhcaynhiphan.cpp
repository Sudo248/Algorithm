#include<bits/stdc++.h>
#define faster ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
using namespace std;
typedef long long ll;

int to_int(string s){
    int res=0;
    for(char &c:s){

        res = res*10+(c-'0');
    }
    return res;
}

struct Node{
    int data;
    int deep;
    Node* left;
    Node* right;
};

Node* newNode(int data, int deep){
    Node* tmp = new Node;
    tmp->data = data;
    tmp->deep = deep;
    tmp->left = NULL;
    tmp->right = NULL;
    return tmp;
}

Node* buildTree(int n, string input){
    vector<string>Input;
    stringstream ss(input);
    while(ss >> input) Input.push_back(input);
    int i=0;
    Node* root = newNode(to_int(Input[0]), 0);
    queue<Node*>q;
    Node* currentNode;
    q.push(root);
    while(q.size() && i < Input.size()){
        currentNode = q.front();q.pop();
        if(currentNode->data == to_int(Input[i])){
            i+=2;
            int val = to_int(Input[i-1]);
            if(Input[i]=="R"){
                currentNode->right=newNode(val, currentNode->deep+1);
                q.push(currentNode->right);
            }
            else if(Input[i] == "L"){
                currentNode->left=newNode(val, currentNode->deep+1);
                q.push(currentNode->left);
            }
            
        }
        i++;
        if(currentNode->data == to_int(Input[i])){
            i+=2;
            int val = to_int(Input[i-1]);
            
            if(Input[i]=="R"){
                currentNode->right=newNode(val, currentNode->deep+1);
                q.push(currentNode->right);
            }
            else if(Input[i] == "L"){
                currentNode->left=newNode(val, currentNode->deep+1);
                q.push(currentNode->left);
            }
            i++;
        }
    }
    return root;
}

void levelOder(Node* root){
    if (root == NULL) 
		return;       
    queue<Node *> q;       
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

    int n;
    string input;
    cin >> n;
    cin.ignore();
    getline(cin,input);
    Node* root = buildTree(n,input);
    levelOder(root);

}


int main(){
    faster
    int t;
    cin >> t;
    while(t--) solve();

    return 0;

}