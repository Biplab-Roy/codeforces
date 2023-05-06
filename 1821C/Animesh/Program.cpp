#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int n = s.length();
    int res = 1e9;
    for(int i=97;i<=122;i++){
        char ch = char(i);
        int cnt = 0,mx = 0;
        for(int j=0;j<n;j++){
            if(s[j] != ch){
                cnt++;
            }else{
                mx = max(mx,cnt);
                cnt = 0;
            }
        }
        mx = max(mx,cnt);
        
        cnt = 0;
        while(mx){
            mx = mx/2;
            cnt++;
        }
        res = min(res,cnt);
    }
    cout<<res<<endl;
  }
  return 0;
}