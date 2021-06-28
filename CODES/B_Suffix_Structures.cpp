#include<bits/stdc++.h>
#define ll long long 
#define endl '\n'
#define rep(i,a,b)  for(int i=a;i<=b;i++)
#define pll pair<ll,ll>
#define pii pair<int,int>
#define vpll vector<pll>
#define SZ(x) ((int)x.size())
#define FIO  ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define watch(x)cout<<(#x)<<" is "<<(x)<<"\n"
#define watch2(x,y)cout<<(#x)<<" is "<<(x)<<" and "<<(#y)<<" is "<<(y)<<"\n"
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
int lcs(string s1,string s2,int n,int m){
    int dp[n+1][m+1];
    rep(i,0,n){
        rep(j,0,m){
            if(i==0 || j==0){
                dp[i][j]=0;
            }
            else if(s1[i-1]==s2[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
            }
            else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    return dp[n][m];    
}
void solve(){
    int n,m,x;
    string s,t,A,B;cin>>s>>t;
    A=s;
    B=t;
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    n=SZ(s);
    m=SZ(t);
    int fl=0,fl1=0,fl2=0,fl3=0;
    vector<int>c1(26,0),c2(26,0);
    rep(i,0,n-1){
        c1[s[i]-'a']++;
    }
    rep(i,0,m-1){ 
       c2[t[i]-'a']++;
    }
    rep(i,0,25){    
        if(c2[i]>c1[i]){
            fl=1;
            cout<<"need tree"<<endl;
            return;
        }
    }
    if(m==n){
        cout<<"array"<<endl;
        return;
    }
    else{
        if(lcs(s,t,n,m)==m){
            cout<<"automaton"<<endl;
        }
        else{
            cout<<"both"<<endl;
        }
    }
    return;
}
signed main() {
    FIO;
    int T=1;//cin>>T;
    while (T--){
        solve();
    }
    return 0;   
}