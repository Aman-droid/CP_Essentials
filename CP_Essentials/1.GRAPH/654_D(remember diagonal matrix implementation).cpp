#include<bits/stdc++.h>
#define ll long long int
#define endl '\n'
#define vll vector< ll >
#define rep(a,b)  for(ll i=a;i<=b;i++)
#define vpll vector<pair<ll,ll>>
#define SZ(x) ((int)x.size())
#define FIO  ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define watch(x) cout << (#x) << " is " << (x) << "\n"
#define watch2(x,y) cout <<(#x)<<" is "<<(x)<<" and "<<(#y)<<" is "<<(y)<<"\n"
#define mp make_pair
#define pb push_back
#define pf push_front
#define mod 1000000007
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


using namespace std;

int main()
{
    FIO;
	ll T;cin>>T;
	while(T--)
	{
        ll n,k;cin>>n>>k;
        int flag=0;
        ll a[n][n];
        memset(a,0,sizeof(a));
        if(k%n==0)
            cout<<"0"<<endl;
        else
            cout<<"2"<<endl;
        ll cnt=0;
        for(ll i=0;i<n && cnt<k;i++)
        {
            ll x=0,y=i;
            for(ll j=0;j<n && cnt<k;j++,cnt++)
            {
                a[x][y]=1;
                x=(x+1)%n;
                y=(y+1)%n;
            }
        }
        for(ll i=0;i<n;i++)
        {
            for(ll j=0;j<n;j++)
            {
                cout<<a[i][j];
            }
            cout<<endl;
        }

	}
	return 0;
}


