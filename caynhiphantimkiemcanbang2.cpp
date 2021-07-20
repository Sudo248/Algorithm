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
vector<int>input;

Node* buildTree(int l, int r){

    if(l > r) return NULL;

    int mid = (l+r)/2;
    Node *root = new Node(input[mid]);
    root ->left = buildTree(l, mid-1);
    root ->right = buildTree(mid+1, r);
    return root;

}

void preOrder(Node *root){
    if(root == NULL) return;
    cout << root ->data << ' ';
    preOrder(root ->left);
    preOrder(root ->right);
}

void solve(){

    int n;
    cin >> n;
    input.assign(n,0);
    for(int &i:input) cin >> i;
    sort(input.begin(), input.end());

    preOrder(buildTree(0, n-1));
    cout << endl;

    

}


int main(){
    faster
    int t;
    cin >> t;
    while(t--) solve();

    return 0;

}