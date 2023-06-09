#include <bits/stdc++.h>
#define ll long long
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);srand(time(NULL))

void solve(){
    string s1,s2;
    cin >> s1 >> s2;
    int t,q,cnt = 0;
    cin >> t >> q;
    int n = s1.size();
    vector<int> unblock(1e6,0);
    for(int i=0;i<n;i++){
        if(s1[i]!=s2[i]){
            cnt++;
        }
    }
    int q1 = 0,type,pos,pos1,pos2,x,y;
    while(q1<q){
        cin >> type;
        cnt += unblock[q1];
        if(type == 1){ // blocking
            cin>>pos;
            pos--;
            // if the pos elements are different then we need to decrease the cnt value
            if(s1[pos]!=s2[pos]){
                cnt--;
                unblock[q1+t] = 1;
            }
        }else if(type == 2){
            cin >> x >> pos1 >> y >> pos2;
            pos1--;pos2--;
            // before swapping
            if(s1[pos1] == s2[pos1]) cnt++;
            if(s1[pos2] == s2[pos2]) cnt++;
            if(x == 1 && y == 1){
                swap(s1[pos1],s1[pos2]);
            }else if(x==1 && y==2){
                swap(s1[pos1],s2[pos2]);
            }else if(x==2 && y==1){
                swap(s2[pos1],s1[pos2]);
            }else{
                swap(s2[pos1],s2[pos2]);
            }
            if(s1[pos1] == s2[pos1]) cnt--;
            if(s1[pos2] == s2[pos2]) cnt--;
        }else{
            if(cnt == 0){
                cout<<"YES"<<endl;
            }else{
                cout<<"NO"<<endl;
            }
        }
        q1++;
    }
}

int main()
{
    int t;
    cin>>t;
    while(t--) {
        solve();
    }
}