#include<bits/stdc++.h>
#define ll long long 
#define endl '\n'
#define rep(i,a,b)  for(int i=a;i<=b;i++)
#define pll pair<ll,ll>
#define pii pair<int,int>
#define vpll vector<pll>
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
while(b>0){
    if(b&1){res=(res*a);b--;}
    a=(a*a);
    b>>=1;
}
    return res;
}
ll gcd(ll a, ll b){return (b==0)?a:gcd(b,a%b);}
//--------------------------------------------------------------------------------------------------------//
int main() {
    FIO;
    int T=1;//cin>>T;
    while (T--){
        ll a,b;cin>>a>>b;
        ll x=log2(a)+1;
        //watch(x);
        ll y=log2(b)+1;
        //watch(y);
        //ll c=(1<<x)-1;
        //ll d=(1<<y)-1;
        ll ans=0;
        for(ll k=y;k>=x;k--){
            ll tmp=power(2,k)-1;
            //watch(tmp);
            for(ll i=0;i<=k-2;i++){
                ll p=tmp-power(2,i);
                //watch(p);
                if(p>=a && p<=b){
                    ans++;
                    //watch(p);
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;   
}
/*
int main() {
	long long a, b;
	scanf("%lld%lld", &a, &b);
	int c = 0;
	for(int i = 0; (1LL << i) / 2 <= b; ++i)
		for(int j = 0; j <= i - 2; ++j) {
			long long x = (1LL << i) - 1 - (1LL << j);
			c += a <= x && x <= b;
		}
	printf("%d\n", c);
	return 0;
}
*/