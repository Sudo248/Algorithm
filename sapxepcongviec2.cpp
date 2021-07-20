#include<bits/stdc++.h>
#define faster ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
using namespace std;
typedef long long ll;

struct data{
    int JobId, Deadline, Profit;
};

bool cmp(data a, data b){
    return a.Profit > b.Profit;
}


void solve(){

    int n;
    cin >> n;
    vector<data>a(n);

    for(int i=0;i<n;i++){
        cin >> a[i].JobId >> a[i]. Deadline >> a[i].Profit;
    }
    sort(a.begin(), a.end(), cmp);
    int res = 0, count = 0;

    int done[1001] = {0};

    for(int i=0;i<n;i++){
        while(done[a[i].Deadline] && a[i].Deadline > 0) a[i].Deadline--;
        if(!done[a[i].Deadline] && a[i].Deadline > 0){
            done[a[i].Deadline] = 1;
            res+= a[i].Profit;
            count++;
        }
    }

    cout << count << ' ' << res << endl;

}


int main(){
    faster;
    int t;
    cin >> t;
    while(t--) solve();

    return 0;

}