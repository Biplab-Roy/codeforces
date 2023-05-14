#include<bits/stdc++.h>
using namespace std;

void solve(){
    int x;
    cin>>x;
    // ----------------------------------------------------------------
    int cntZero = 0;
    int original = x;
    // if there is only one 0 then output is -1
    // while(y){
    //     int val = y&1;
    //     if(val==0) cntZero++;
    //     y = y>>1;
    // }
    // if(cntZero==1 || x == 1){
    //     cout<<-1<<endl;
    //     return;
    // }
    // ELSE
    int s = 2*x;
    string a,b;
    while(x || s){
        int curx = x&1;
        int curs = s&1;
        if(curx == 1){ // then curs must be 1
            // cout<<curx<<" "<<curs<<endl;
            a.insert(0,"1");
            b.insert(0,"0");
        }else{ // there is 2 possibilities 00 or 11
            int prevx = x>>1&1;
            int prevs = s>>1&1;
            // cout<<curx<<" "<<curs<<" "<<prevx<<" "<<prevs<<endl;
            if(prevx == 1){
                if(prevs == 1){
                    a.insert(0,"0");
                    b.insert(0,"0");
                }else{
                    a.insert(0,"1");
                    b.insert(0,"1");
                }
            }else{ // prevx == 0
                if(prevs == 1){
                    a.insert(0,"1");
                    b.insert(0,"1");
                }else{
                    a.insert(0,"0");
                    b.insert(0,"0");
                }
            }
        }
        x = x>>1;
        s = s>>1;
    }
    // cout<<a<<" "<<b<<endl;
    int res1 = 0,res2 = 0;
    for(int i=0;i<a.size();i++){
        res1 = 2*res1 + a[i]-'0';
        res2 = 2*res2+b[i]-'0';
    }
    if(res1+res2 != 2*original){
        cout<<-1<<endl;
        return;
    }
    cout<<res1<<" "<<res2<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}