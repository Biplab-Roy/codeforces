#include<bits/stdc++.h>
using namespace std;

int solve(){
    int n, window_len = INT_MAX;
    bool global_ans = false;
    string s;
    char ch = 65;
    cin>>n>>s;
    unordered_set<char> chars(s.begin(), s.end());
    for(char c : chars){
        int l = 0, r = n - 1;
        int removal = 0;
        int is_ans = true;
        while(l < r){
            if(s[l] == s[r]){
                l++; r--;
            }
            else{
                if(l < r && s[l] == c) l++;
                else if(l < r && s[r] == c) r--;
                else {
                    is_ans = false;
                    break;
                }
                removal++;
            }
        }
        if(is_ans){
            window_len = min(window_len, removal);
        }
        global_ans |= is_ans;
    }
    if(global_ans) return window_len;
    else return -1;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        cout<<solve()<<endl;
    }
}