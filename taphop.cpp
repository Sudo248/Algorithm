
#include<bits/stdc++.h>
#define faster ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
using namespace std;
typedef long long ll;

int n,k,s,res;
int a[25];

void Try(int i,int sum){
    for(int j = a[i-1]+1; j <= n - k + i; j++){
        a[i] = j;
        sum += j;
        if(i == k) {
            if(sum == s) res++;
        }
        else Try(i+1,sum);

        sum -= j;
    }
}


int main(){
    faster
    while(true){
        cin >> n >> k >> s;
        if(n == 0 && k == 0 && s == 0) return 0;
        res = 0;
        if(n >= k){
            Try(1,0);     
        }

        cout << res << endl;
    }

    return 0;
}