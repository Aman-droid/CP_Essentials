#include<bits/stdc++.h>
#define ll long long
#define int long long 
#define endl '\n'
#define rep(i,a,b)  for(int i=a;i<=b;i++)
#define SZ(x) ((int)x.size())
#define FIO  ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define mod 1000000007
#define INF (ll)(1e18)
#define all(c) (c).begin(),(c).end()
using namespace std;

const int mxn=2e5;
stack<int>st;
void solve(){
    string s;cin>>s;
    int n=s.size();
    int dp[n+1]={0};
    
    int mx=0;
    map<int,int >mp;
    mp[0]=1;

    rep(i,0,n-1){
        if(s[i]==')'){
            if(st.empty()){
                continue;
            }
            else{
                int cur=st.top();
                st.pop();
                dp[i+1]=dp[cur]+i-cur+1;
                mx = max(mx,dp[i+1]);
                mp[dp[i+1]]++;
            }
            
        }
        else{
            st.push(i);
        }
    }
    cout<<mx<<" "<<mp[mx]<<endl;
    
}

signed main() {
    FIO;
    int T=1;//cin>>T;
    while (T--){
       solve();
    }
    return 0;   
}