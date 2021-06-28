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

/*int main() {
    int T=1;cin>>T;
    while (T--)
    {
        ll n,;cin>>n;
        ll a[n];
        ll tot=0;
        rep(i,0,n-1){
            cin>>a[i];
            tot+=a[i];
        }
        ll csum=a[0];
        ll msum=a[0];
        int fl=0;
        for(ll i=1;i<n;i++)
        {
            csum=a[i]+csum;
            if(csum<msum)
                fl=1;
            if(a[i]>csum){
                csum=a[i];
            }
           // csum=max(a[i],a[i]+csum);
            msum=max(msum,csum);
        }
        //watch(msum);
        //watch(tot);
        if(msum == tot && fl==0)
            cout<<"YES"<<endl;
        else if(msum >=tot)
            cout<<"NO"<<endl;
        else {
            cout<<"YES"<<endl;
        }
    }
}*/
int main() {
    FIO;
	int t=1;cin>>t;
	while(t--){
		ll n,x=0,l=0,csum=0,r=0,msum=0;
		cin>>n;
		for(ll i=1;i<=n;i++){
			cin>>x;
			csum+=x;
			if(csum>msum)msum=csum,r=i;
			if(csum<=0)csum=0,l=i;
		}
		if(r==n && l==0)
            cout<<"YES"<<endl;
		else
		    cout<<"NO"<<endl;
	}
}

