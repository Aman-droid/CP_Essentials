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
int solve(string &s,int x,int y){
    int res=0;
    for(auto c:s){
        if(c-'0'==x){
            res++;
            swap(x,y);
        }
    }
    if(x!=y && res%2!=0){
        res--;
    }
    return res;
}

int main() {
    FIO;
    int T=1;cin>>T;
    while (T--){
        string s;cin>>s;
        int ans=-1;
        int n=s.length();
        rep(i,0,9){
            rep(j,0,9){
                ans=max(ans,solve(s,i,j));
            }
        }
        cout<<n-ans<<endl;
    }
    return 0;   
}