#include<bits/stdc++.h>
#define faster ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
using namespace std;
typedef long long ll;

struct Node{
    string data;
    Node* left;
    Node* right;
};

Node* newNode(string val){
    Node* tmp = new Node;
    tmp-> data = val;
    tmp-> left = NULL;
    tmp -> right = NULL;
    return tmp;
}

bool isOperater(char c){
    return (c == '+' | c == '-' | c == '*' | c == '/');
}

int to_Int(string s){
    int res = 0;
    for(char &c:s){
        res = res*10+(c-'0');
    }
    return res;
}

void solve(){

    int n;
    cin >> n;
    string input;
    vector<string>Input;
    queue<int>numberQ;
    queue<char>operaterQ;
    cin.ignore();
    getline(cin,input);
    stringstream ss(input);
    while(ss >> input) Input.push_back(input);
    for(int i=Input.size()-1;i>=0;i--){
        if(!isOperater(Input[i][0])){
            numberQ.push(to_Int(Input[i]));
        }
        else {
            operaterQ.push(Input[i][0]);
        }
    }

    while(operaterQ.size()){
        char c = operaterQ.front();operaterQ.pop();
        int a = numberQ.front(); numberQ.pop();
        int b = numberQ.front(); numberQ.pop();
        if(c == '+'){
            numberQ.push(b+a);
        }else if(c == '-'){
            numberQ.push(b-a);
        }else if(c == '*'){
            numberQ.push(b*a);
        }
        else{
            numberQ.push(b/a);
        }
    }
    cout << numberQ.front() << endl;



}


int main(){
    faster
    int t;
    cin >> t;
    while(t--) solve();

    return 0;

}