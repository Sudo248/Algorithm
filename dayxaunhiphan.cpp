#include<bits/stdc++.h>
#define faster() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
using namespace std;
typedef long long ll;
 
vector<ll>fibo(101);
void init(){
	fibo[1]=1;
	fibo[2]=1;
	for(int i=3;i<93;i++){
		fibo[i]=fibo[i-1]+fibo[i-2];
	}
}

char find(ll n,ll k){
	if(n==1) return '0';
	if(n==2) return '1';
	if(k>fibo[n-2]) return find(n-1,k-fibo[n-2]);
	return find(n-2,k);
}
 
int main(){
	faster();
	init();
	ll n,k,t;
	cin>>t;
	while(t--){
		cin>>n>>k;
		cout<<find(n,k)<<endl;
	}
	
	
 
 
	return 0;
}