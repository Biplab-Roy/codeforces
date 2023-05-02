#include<bits/stdc++.h>

using namespace std;

void solve(){
    int n, k;
    cin>>n>>k;
    int a = 2, b = -2*n, c = n*n - n - 2*k; 
    int d = b*b - 4*a*c; 
    if(d>=0 && ceil(sqrt(d))==floor(sqrt(d)) && (-b + (int)sqrt(d))%4 == 0){
        cout<<"YES"<<endl;
        int solution = (-b + sqrt(d))/4;
        for(int i=0; i<solution; i++) cout<<"1 ";
        for(int i=solution; i<n; i++) cout<<"-1 ";
        cout<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}