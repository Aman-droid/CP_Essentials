#include<bits/stdc++.h>
#define ll long long int
#define endl '\n'
#define vll vector< ll >
#define rep(i,a,b)  for(int i=a;i<=b;i++)
#define pii pair<int,int>
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

int main() {
    FIO;
    int T=1;cin>>T;
    while (T--){
        int fl=0;
        ll n,m;cin>>n>>m;
        ll t[n],l[n],h[n];
        rep(i,0,n-1){
            cin>>t[i]>>l[i]>>h[i];
        }
        ll mx,mn;
        mx=m;
        mn=m;
        ll cur=0;
        rep(i,0,n-1){
            //watch(mx);
            //watch(mn);
            mx+=t[i]-cur;
            mn-=t[i]-cur;
            cur=t[i];
            if(mx<l[i] || mn>h[i]){
                fl=1;
                break;
            }
            mx=min(mx,h[i]);
            mn=max(mn,l[i]);

        }
        if(fl==0)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
        

    }
}

