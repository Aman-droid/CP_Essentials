#include<bits/stdc++.h>
#define ll long long 
#define endl '\n'
#define rep(i,a,b)  for(int i=a;i<=b;i++)
#define pll pair<ll,ll>
#define pii pair<int,int>
#define vpll vector<pll>
#define SZ(x) ((int)x.size())
#define FIO  ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define watch(x) cout << (#x) << " is " << (x) << "\n"
#define pb push_back
#define pf push_front
#define ff first
#define ss second
#define mod 1000000007
using namespace std;
ll power(ll a, ll b){//a^b
ll res=1;
a=a%mod;
while(b>0){
    if(b&1){res=(res*a)%mod;b--;}
    a=(a*a)%mod;
    b>>=1;
}
    return res;
}
ll gcd(ll a, ll b){return (b==0)?a:gcd(b,a%b);}
//--------------------------------------------------------------------------------------------------------//

ll a1[26],dp[26][26];
int main()
{
    string s;cin>>s;
    for (int i=0;i<s.length();i++){
        int c=s[i]-'a';
        for (int j=0;j<26;j++){
            dp[j][c]+=a1[j];  // updating count of subsequences t[0]='a'+j && t[1] = 'c'
        }
        a1[c]++;
    }
    /*rep(i,0,25){
      rep(j,0,25)
        cout<<arr2[i][j]<<" ";
      cout<<endl;
    }*/
    ll ans=0;
    rep(i,0,25)
        ans=max(ans,a1[i]);
    rep(i,0,25){
        rep(j,0,25)
            ans=max(ans,dp[i][j]);
    }
    cout<<ans<<endl;
}