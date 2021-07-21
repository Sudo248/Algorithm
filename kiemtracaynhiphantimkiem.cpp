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
vector<int>a,b,c;
bool res;

Node* insertNode(Node* root, int data){
    if(root == NULL) return new Node(data);
    if(data == root -> data) return root;
    if(data < root -> data) root -> left = insertNode(root -> left, data);
    else root -> right = insertNode(root->right, data);
    return root;
}

Node* buildTree(){
    int n;
    cin >> n;
    a.assign(n,0);
    b.assign(n,0);
    Node *root = NULL;
    for(int i = 0;i<n;i++){
        cin >> a[i];
        b[i] = a[i];
    }
    sort(a.begin(), a.end());
    root = insertNode(root, a[0]);
    for(int i =1;i<n;i++) insertNode(root, a[i]);
    return root;
}

void preOrder(Node *root){
    if(root == NULL) return;
    c.push_back(root -> data);
    preOrder(root -> left);
    preOrder(root -> right);
}
void check(){
    for(int i = 0; i < a.size(); i++){
        if(c[i] != b[i]){
            cout << "0\n";
            return;
        }
    }
    cout << "1\n";
}

void solve(){

    c.clear();
    preOrder(buildTree());
    check();
    // for(int &i:b) cout << i << ' ';
    // cout << endl;

    

}

int main(){

    faster
    int t;
    cin >> t;
    while(t--) solve();

    return 0;
}