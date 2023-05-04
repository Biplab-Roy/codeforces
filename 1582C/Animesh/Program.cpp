#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    string s;
    cin>>n;
    cin>>s;
    int res = 1e9;
    for(int i=97;i<=122;i++){
        int l = 0,r = n-1;
        int cnt = 0;
        char ch = char(i);
        while(l<=r){
            if(s[l] != s[r]){
                if(s[l] == ch){
                    cnt++;
                    l++;
                }else if(s[r] == ch){
                    cnt++;
                    r--;
                }else{
                    cnt = 1e9;
                    break;
                }
            }else{
                l++;r--;
            }
        }
        res = min(res, cnt);
    }
    if(res == 1e9){
        cout<<-1<<endl;
    }else{
        cout<<res<<endl;
    }
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}