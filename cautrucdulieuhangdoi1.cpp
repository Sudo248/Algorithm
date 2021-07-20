
#include<bits/stdc++.h>
#define faster ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
using namespace std;
typedef long long ll;

void solve(){
    int n,a,x;
    cin>>n;
    queue<int>q;
    while(n--){
        cin>>a;
        switch (a)
        {
            case 1:
                cout<<q.size()<<endl;
                break;
            case 2:
                if(q.size()) cout<<"NO\n";
                else cout<<"YES\n";
                break;
            case 3:
                cin>>x;
                q.push(x);
                break;
            case 4:
                if(q.size()) q.pop();
                break;

            case 5:
                if(q.size()) cout<<q.front()<<endl;
                else cout<<-1<<endl;
                break;
            case 6:
                if(q.size()) cout<<q.back()<<endl;
                else cout<<-1<<endl;
                break;
        }
    }
}

int main(){
    faster

    int t;
    cin>>t;
    while(t--) solve();

    return 0;
}