#include<bits/stdc++.h>
using namespace std;
/*
    link-> https://codeforces.com/problemset/problem/1823/A
    APPROACH:
        we have to find the value of n1 and n2 so that
        k = n1C2 + n2C2
        n1-> number of -1
        n2-> number of 1
*/
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        int n1,n2;
        bool isPossible = false;
        if(n == 2 && k == 0){
            cout<<"YES"<<endl;
            cout<<1<<" "<<-1<<endl;
            continue;
        }
        for(int i=2;i<=n;i++){
            n1 = i;
            n2 = n-i;
            if(k == ((n1-1)*n1)/2 + ((n2-1)*n2)/2){
                isPossible = true;
                break;
            }
        }
        if(isPossible){
            cout<<"YES"<<endl;
            for(int i=0;i<n1;i++){
                cout<<-1<<" ";
            }
            for(int i=0;i<n2;i++){
                cout<<1<<" ";
            }
            cout<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }
}