#include<bits/stdc++.h>
using namespace std;
int a[17][17],n,Min=INT_MAX,s=0,dem=1;
bool ok[17]={false};
 
void Try(int i){
    dem++;
    for(int j=1;j<=n;j++){
        if(!ok[j]){
            ok[j]=true;
            s=s+a[i][j];
            if(s>=Min) {
                ok[j]=false;
                s=s-a[i][j];
                dem--;
                return;
            }
            if(dem==n){
                if(Min>s+a[1][j]) Min=s+a[1][j];
            }
            else Try(j);
 
            ok[j]=false;
            s=s-a[i][j];
        }
    }
    dem--;
}
 
 
 
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) cin>>a[i][j];
    ok[1]=true;
    Try(1);
    cout<<Min;
   
 
    return 0;
} 