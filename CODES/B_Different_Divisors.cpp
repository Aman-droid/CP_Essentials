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
ll MAX=10000001;
ll spf[10000001];
vector<ll>prime;
void sieve()
{
    spf[0] = spf[1] = 1;
    for (int i = 2; i < MAX; i++) {
        if (spf[i] == 0) {
            for (int j = i * 2; j < MAX; j += i) {
                if (spf[j] == 0) {
                    spf[j] = i;
                }
            }
            spf[i] = i;
        }
    }
    //prime.pb(1);
    for(int i=2;i<MAX;i++){
        if(spf[i]==i)
            prime.pb(i);
    }
}

int main() {
    FIO;
    sieve();
    int T=1;cin>>T;
    while (T--){
        ll d;cin>>d;
        ll cur=1;
        int N=SZ(prime);
        vector<ll>ans;
        ans.pb(1);
        int cnt=1;
        for(int i=0;i<N;i++){
            //watch(prime[i]);
            //watch(cur);
            if(prime[i]-cur>=d){
                ans.pb(prime[i]);
                cur=prime[i];
                cnt++;
            }
            if(cnt==3)
                break;
        }
        ll res=ans[0]*ans[1]*ans[2];
        cout<<res<<endl;
    }
    return 0;   
}