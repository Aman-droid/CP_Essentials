#include<bits/stdc++.h>
#define ll long long int
#define endl '\n'
#define vll vector< ll >
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
using namespace std;

int main()
{
    FIO;
	ll T;cin>>T;
	while(T--)
	{
        ll n;cin>>n;
        ll a[n];
        for(int i=0;i<n;i++)
            cin>>a[i];
        ll N=power(2,n);
        int flag=0;
        for(ll p=0;p<N;p++)             //all subsets 0,1,2,3,4.......2^n-1
        {
            ll sum=0;
            for(ll i=0;i<n;i++)
            {
                ll f=1<<i;
                if((p&f)!=0)                //if ith bit of p is set then print that index element
                {
                    cout<<a[i];
                }
            }
            cout<<endl;
        }
	}
	return 0;
}


