#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int f[105][105][105];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);cout.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int a,b,c;
        cin >> a >> b >> c;
        string s1, s2,s3;
        cin>>s1>>s2>>s3;
        int res=0;
        memset(f,0,sizeof(f));
        for(int i=1;i<=s1.size();i++){
            for(int j=1;j<=s2.size();j++){
                for(int k=1;k<=s3.size();k++){
                    if(s1[i-1]==s2[j-1]&&s2[j-1]==s3[k-1]) f[i][j][k]=f[i-1][j-1][k-1]+1;
                    else f[i][j][k]= max(f[i-1][j][k], max(f[i][j-1][k],f[i][j][k-1]));
                    res=max(res, f[i][j][k]);
                }  
            }
        }
        cout << res << endl;
    }  
    return 0;
}