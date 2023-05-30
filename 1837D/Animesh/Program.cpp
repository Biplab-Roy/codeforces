#include<bits/stdc++.h>
using namespace std;
 

void solve(){
    int n;
    cin>>n;
    string str;
    cin>>str;
    ////////////////////////    
    if(n%2){
        cout<<-1<<endl;
        return;
    }
    vector<int> res(n);
    stack<char> st1,st2;
    for(int i=0;i<n;i++){
        if(str[i] == '('){
            if((st1.empty() && st2.empty()) || (!st1.empty() && st1.top() == '(')){
                // cout<<"st1 push"<<endl;
                st1.push('(');
                res[i] = 1;
            }else{
                // cout<<"st2 pop"<<endl;
                st2.pop();
                res[i] = 2;
            }
        }else{
            if((st1.empty() && st2.empty()) || (!st2.empty() && st2.top() == ')')){
                // cout<<"st2 push"<<endl;
                st2.push(')');
                res[i] = 2;
            }else if(!st1.empty() && st1.top() == '('){
                // cout<<"st1 pop"<<endl;
                st1.pop();
                res[i] = 1;
            }
        }
    }
    if(!st1.empty() || !st2.empty()){
        cout<<-1<<endl;
        return;
    }
    bool isOne = false,isTwo = false;
    for(int i=0;i<n;i++){
        if(res[i] == 1){
            isOne = true;
        }
    }
    if(isOne == false){
        res.assign(n,1);
    }
    for(int i=0;i<n;i++){
        if(res[i] == 2){
            isTwo = true;
        }
    }
    if(isTwo == true){
        cout<<2<<endl;
    }else{
        cout<<1<<endl;
    }
    for(int i=0;i<n;i++){
        cout<<res[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}