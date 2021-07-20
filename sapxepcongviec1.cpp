
#include<bits/stdc++.h>
#define faster ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
using namespace std;
typedef long long ll;

struct CV{
    int start,finish;
};

bool cmp(CV a, CV b){
    if(a.finish == b.finish) return a.start < b.start;
    return a.finish < b.finish;
}

void solve(){
    int n;
    cin >> n;
    CV a[1005];

    for(int i = 0; i < n; i++) cin >> a[i].start;
    
    for(int i = 0; i < n; i++) cin >> a[i].finish;

    sort(a,a + n,cmp);

    int res = 1, x = 0;

    for(int i = 1; i < n; i++){ 
        if(a[x].finish <= a[i].start){
            res++;
            x = i;
        }
        // cout << a[i].start << ' ';
    }
    // cout <<endl;
    // for(int i = 0; i < n; i++){ 
    //     cout << a[i].finish << ' ';
    // }

    cout << res <<endl;
    
}

int main(){
    // faster

    int t;
    cin>>t;
    while(t--) solve();

    return 0;
}