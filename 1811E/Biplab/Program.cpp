#include<bits/stdc++.h>
using namespace std;

void solve(){
    long long int l;
    cin >> l;
    string s;
    while(l){
        int mod = l%9;
        s.push_back(mod>=4?'0'+mod+1:'0'+mod);
        l = l / 9;
    }
    reverse(s.begin(), s.end());
    cout << s << endl;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}