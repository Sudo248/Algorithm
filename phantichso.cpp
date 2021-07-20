
// #include<bits/stdc++.h>
// #define faster ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
// #define endl '\n'
// using namespace std;
// typedef long long ll;

// vector<int>a;
// bool stop;
// int k;

// void print(){
//     cout << '(';
//     for(int i=1;i<k;i++) cout << a[i] << ' ';
//     cout << a[k] << ") ";
// }

// void sinh(){
//     int i = k;
//     while(i > 0 && a[i] == 1) i--;
//     if(i <= 0) stop = true;
//     else{
//         a[i]--;
//         int D = k - i + 1;
//         int R = D / a[i];
//         int S = D % a[i];
//         k = i;
//         if(R > 0){
//             for(int j = i+1; j <= i+R; j++){
//                 a[j] = a[i]; 
//             }
//             k = k + R;
//         }
//         if(S > 0){
//             k++;
//             a[k] = S;
//         }

//     }
// }

// void solve(){
//     int n;
//     cin >> n;
//     a.resize(n+1);
//     stop = false;
//     k=1;
//     a[1] = n;
//     while(!stop){
//         print();
//         sinh();
//     }
    
//     cout<<endl;

// }

// int main(){
//     faster

//     int t;
//     cin>>t;
//     while(t--) solve();

//     return 0;
// }

#include<bits/stdc++.h>
#define faster ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
using namespace std;
typedef long long ll;

int n,a[101],s[101],m;
void in(int i){
    cout<<"(";
    for(int j=1;j<i;j++) 
    {
        cout<<a[j]<<' ';
    }
    cout<<a[i]<<")"<<' ';
}

void Try(int i){
    for(int j=a[i-1];j>=1;j--)
    {
        a[i]=j;
        s[i]=s[i-1]+j;
        if(s[i]==n) in(i);
        else if(s[i]>n) continue;
        else Try(i+1);
    }
}

void solve(){
    cin>>n;
    s[0]=0;
    for(int i=n;i>=1;i--){
        a[1]=i;
        s[1]=s[0]+i;
        if(s[1]==n) in(1);
        else Try(2);
    }
    cout<<endl;
}


int main(){
    faster
    int t;
    cin >> t;
    while(t--) solve();

    return 0;

}