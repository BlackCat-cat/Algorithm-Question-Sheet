/*
 * @Author: BlaCat
 */
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
mt19937_64 rnd(time(0));
void solve(){
    int n,q;
    cin>>n>>q;
    vector<int> a(n+1);
    vector<int> pre(n+1,0);
    map<int,int> mp;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(mp[a[i]]==0){
            mp[a[i]]=rnd();
        }
        pre[i]=pre[i-1]^mp[a[i]];
    }
    int l,r;
    for(int i=0;i<q;i++){
        cin>>l>>r;
        if((r-l)%2==0){
            cout<<"NO"<<endl;
            continue;
        }
        if((pre[r]^pre[l-1])==0){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
