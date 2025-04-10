#include<bits/stdc++.h>
#define endl '\n'
using i64 = long long;
using u64 = unsigned long long;
using d64 = double;
using ld64 = long double;
std::vector<int> kmp(std::string s) {
    int n = s.size();
    std::vector<int> f(n + 1);
    for (int i = 1, j = 0; i < n; i++) {
        while (j && s[i] != s[j]) {
            j = f[j];
        }
        j += (s[i] == s[j]);
        f[i + 1] = j;
    }
    f[0]=-1;
    return f;
}
void solve(){
    std::string c,s,t;
    std::cin>>c>>s>>t;
    c=" "+c;
    auto s1=kmp(s);
    auto t1=kmp(t);
    int n=c.size();
    std::vector dp(n,std::vector(s.size()+10,std::vector<int>(t.size()+10,-(i64)1e9-7)));
    dp[0][0][0]=0;
    int len1=s.size();
    int len2=t.size();
    auto kmps=[&](int j,char x)->int{
        while(1){
            if(j==-1||s[j]==x){
                return j+1;
            }
            else{
                j=s1[j];
            }
        }
    };
    auto kmpt=[&](int j,char x)->int{
        while(1){
            if(j==-1||t[j]==x){
                return j+1;
            }
            else{
                j=t1[j];
            }
        }
    };
    for(int i=1;i<n;i++){
        for(int j=0;j<len1;j++){
            for(int k=0;k<len2;k++){
                if(dp[i-1][j][k]==-(i64)1e9-7){
                    continue;
                }
                int poss=0,cnt=0,post=0;
                if(c[i]!='*'){
                    cnt=0;
                    poss=kmps(j,c[i]);
                    post=kmpt(k,c[i]);
                    if(poss==len1) cnt++,poss=s1[poss];
                    if(post==len2) cnt--,post=t1[post];
                    dp[i][poss][post]= std::max(dp[i][poss][post],dp[i-1][j][k]+cnt);
                }
                else{
                    for(char x='a';x<='z';x++){
                        cnt=0;
                        poss=kmps(j,x);
                        post=kmpt(k,x);
                        if(poss==len1) cnt++,poss=s1[poss];
                        if(post==len2) cnt--,post=t1[post];
                        dp[i][poss][post]= std::max(dp[i][poss][post],dp[i-1][j][k]+cnt);
                    }
                }
            }
        }
    }
    int ans = -1e9-7;
     for(int i=0;i<len1;i++)
        for(int j=0;j<len2;j++)
         ans = std::max(dp[n-1][i][j],ans);
    std::cout<<ans<<endl;
}
signed main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t=1;
    while(t--){
        solve();
    }
    return 0;
}
