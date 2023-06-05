#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    int n,q;
    cin>>n>>q;
    string s;
    cin>>s;
    set<int> st;
    for(int i=1;i<=n;i++){
        if(i%2 == 0 && s[i-1] == '('){
            st.insert(i);
        }
        if(i%2 == 1 && s[i-1] == ')'){
            st.insert(i);
        }
    }
    while(q--){
        int ind;
        cin>>ind;
        if(n%2 == 1){
            cout<<"NO"<<endl;
            continue;
        }
        // if(ind%2 == 0 && s[ind-1] == '('){
        //     st.erase(ind);
        // }else if(ind%2 == 0 && s[ind-1] == ')'){
        //     st.insert(ind);
        // }else if(ind%2 == 1 && s[ind-1] == ')'){
        //     st.erase(ind);
        // }else{
        //     st.insert(ind);
        // }
        if(st.count(ind)) st.erase(ind);
        else st.insert(ind);

        if(st.size() && (*st.begin()%2 == 1 || *st.rbegin()%2 == 0)){
            cout<<"NO"<<endl;
        }else{
            cout<<"YES"<<endl;
        }
        
    }
    return 0;
}