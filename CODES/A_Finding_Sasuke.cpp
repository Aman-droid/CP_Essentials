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
ll lcm(ll a,ll b){return (a*b)/gcd(a,b);}
//--------------------------------------------------------------------------------------------------------//

int main() {
    int T=1;cin>>T;
    while (T--)
    {
        ll n;cin>>n;
        ll a[n];
        ll sum=0;
        for(int i=0;i<n;i++)cin>>a[i];
        for(int i=0;i<n;i=i+2){
            ll x=-a[i+1];
            ll y=a[i];
            cout<<x<<" "<<y<<" ";
        }
        cout<<endl;
    }
}

