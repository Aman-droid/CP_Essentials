#include<bits/stdc++.h>
#define ll long long int
#define endl '\n'
#define vll vector< ll >
#define rep(i,a,b)  for(int i=a;i<=b;i++)
#define pii pair<int,int>
#define SZ(x) ((int)x.size())
#define FIO  ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define watch(x) cout << (#x) << " is " << (x) << "\n"
#define mp make_pair
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
    int T=1;//cin>>T;
    while (T--)
    {
        ll n,x,y;cin>>n;
        ll sum=0;
        ll a[n];
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            sum+=a[i];
        }
        sort(a,a+n,greater<ll>());
        ll sum2=sum-a[0];
        if(sum%2==1  || sum2 < a[0])
            cout<<"NO\n";
        else
        {
            cout<<"YES\n";
        }
        
        
    }
}

