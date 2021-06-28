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
#include<bits/stdc++.h>
 
#define ll long long int
#define ld long double
#define pb push_back
#define fi first
#define se second
#define all(x) x.begin(),x.end()
#define mem(x,y) memset(x,y,sizeof(x))
#define pii pair<int,int>
#define pll pair<ll,ll>
#define INF 1e9+10
#define INFL 1e18
#define mod 1000000007
//#define mod 998244353
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
 
 
 
 
ll power(ll x,ll n){ll res =1;while(n>0){if(n%2==1){res=res*x;}x=x*x;n=n/2;}return res;}
ll powm(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
 
//cout<< fixed << setprecision(10)
//__builtin_popcountll();
//|_2.4_|=2  



int main(){
    FIO;
    int T;cin>>T;
    while(T--)
    {
        int n;cin>>n;
        int a[n+1];
        set<int>s;
        for(int i=0;i<=n+5;i++)
            s.insert(i);
        for(int i=1;i<=n;i++){
            cin>>a[i];
            if(s.find(a[i])!=s.end()){
                s.erase(a[i]);
            }
        }
        int x=*s.lower_bound(-1);
        if(x==0){
            cout<<powm(2,n-1)<<"\n";
            continue;
        }
        ll dp[n+1]={0};
        map<int,int>mp;
        dp[0]=1;
        ll l=1;
        for(int i=1;i<=n;i++){
            if(a[i]<x)
                mp[a[i]]++;
            if(mp.size()==x){
                dp[i]=1;
                mp.clear();
                break;
            }
        }
        i++;
        l=i;
        int f=0;
        for(;i<=n;i++)
        {
            if(a[i]<x)
            mp[a[i]]++;
            dp[i]=dp[i-1];
            if(mp.size()==x)
            {
                while(1)
                {
                    if(a[l]>x){
                        dp[i]+=dp[l];
                        dp[i]%=mod;
                        l++;
                        continue;
                    }
                    if(mp[a[l]]==1){
                        if(f==0)
                        {
                            f=1;
                            dp[i]+=dp[l-1];
                            dp[i]%=mod;
                        }
                        break;
                    }
                    else{
                        dp[i]+=dp[l];
                        dp[i]%=mod;
                        mp[a[l]]--;
                        l++;
                    }
                }
            }
        }
        cout<<dp[n]<<"\n";
    }
}