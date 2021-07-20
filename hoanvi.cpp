
#include<bits/stdc++.h>
#define faster ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
using namespace std;
typedef long long ll;
vector<int>a;
vector<bool>check;
vector<vector<int> >res;
int n;

void Try(int i){
    for(int j=1;j<=n;j++){
        if(!check[j]){
            a.push_back(j);
            check[j]=true;
            if(a.size()==n){
                res.push_back(a);
            }
            else{
                Try(i+1);
            }
            a.pop_back();
            check[j]=false;
        }
    }
}

int main(){
    faster
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        a.clear();
        res.clear();
        check.resize(15,false);
        Try(1);
        for(int i = res.size()-1;i>=0;i--){
            for(int j:res[i]){
                cout<<j;
            }
            cout<<' ';
        }
        cout<<endl;
    }


    return 0;
}