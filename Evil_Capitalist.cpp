/*
 * @Author: BlaCat
 */
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a.begin(),a.end());
    int sum=0;
    int maxn=0;
    int x=0;
    int cnt=0;
    a.push_back(2e9);
    for(int i=0;i<n;i++){
        if(a[i]==a[i+1]){
            cnt++;
        }
        else{
            if(cnt%2==0){
                x=abs(a[i+1]-a[i]);
            }
            else{
                x=0;
            }
            sum+=x;
            maxn=max(maxn,x);
            cnt=0;
        }
    }
    int ans1=sum-maxn;
    cout<<ans1<<endl;
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    while(t--){
        solve();
    }
    return 0;
}
