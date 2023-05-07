#include<bits/stdc++.h>
using namespace std;

void solve(){
    long long k;
    cin>>k;
    long long num = k;
    // convert the number into base 9 number
    long long base9num = 0;
    long long initialZero = 0;
    bool flag = false;
    while(num){
        int r = num%9;
        if(!flag && r == 0){
            initialZero++;
        }
        if(r != 0){
            flag = true;
        }
        num = num/9;
        base9num = base9num*10+r;
        // cout<<num<<" : "<<r<<" : "<<base9num<<endl;
    }
    string res = to_string(base9num);
    reverse(res.begin(),res.end());
    while(initialZero--){
        res.push_back('0');
    }
    for(auto it:res){
        int val = it-'0';
        if(val >= 4){
            cout<<val+1;
        }else{
            cout<<val;
        }
    }
    cout<<endl;

}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}