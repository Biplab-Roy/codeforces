#include<bits/stdc++.h>
using namespace std;
 

void solve(){
    int n,k;
    cin>>n>>k;
    vector<int> x(k),c(k);
    for(int i=0;i<k;i++){
        cin>>x[i];
    }
    for(int i=0;i<k;i++){
        cin>>c[i];
    }
    //////////////////////////////////                  
    string res;
    if (c[0] < 3 || c[0] > x[0]) {
        cout <<"NO"<<endl;
        return;
    }
    char chr = 'a';
    for (int i = 0; i < c[0] - 3; i++)
        res.push_back('a');

    for (int i = c[0] - 3; i < x[0]; i++) {
        res.push_back(chr);
        chr++;
        if (chr == 'd') chr = 'a';
    }
    int prevLen = x[0],prevPal = c[0];
    for(int i=1;i<k;i++){
        int newChar = x[i] - prevLen;
        int needPal = c[i] - prevPal;
        if(newChar < needPal){
            cout<<"NO"<<endl;
            return;
        }
        prevLen = x[i];
        prevPal = c[i];
        for(int j=0;j<needPal;j++){
            res.push_back('c'+i);
        }
        for(int j=needPal;j<newChar;j++){
            res.push_back(chr);
            chr++;   
            if (chr == 'd') chr = 'a';
        }
    }
    cout<<"YES"<<endl;
    cout<<res<<endl;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}