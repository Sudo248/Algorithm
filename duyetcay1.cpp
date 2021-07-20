#include<bits/stdc++.h>
#define faster ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
using namespace std;
typedef long long ll;
int preIndex;

void postOrder(vector<int> In, vector<int> Pre, int start, int end){
    if(start > end) return;
    int index = 1;
    int value = Pre[preIndex++];
    for(index = start;index<end;index++){
        if(In[index] == value) break;
    }
    postOrder(In, Pre, start,index-1);
    postOrder(In, Pre, index+1,end);
    cout << In[index] << ' ';
}

void solve(){
    int n;
    cin >> n;
    vector<int>Inorder(n+1), PreOrder(n+1);    
    for(int i=1;i<=n;i++) {
        cin >> Inorder[i];
    }
    for(int i=1;i<=n;i++) {
        cin >> PreOrder[i];
    }
    preIndex = 1;
    postOrder(Inorder, PreOrder,1,n);
    cout << endl;

}


int main(){
    faster
    int t;
    cin >> t;
    while(t--) solve();

    return 0;

}