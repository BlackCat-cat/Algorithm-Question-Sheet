/*
 * @Author: BlaCat
 */
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
using i64= long long ;
void solve(){
    int n;
    cin>>n;
    i64 c=n;
    i64 res=1;
    while(c){
        i64 m=c%10;
        c/=10;
        res*=(m+2)*(m+1)/2;
    }
    cout<<res<<endl;
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
