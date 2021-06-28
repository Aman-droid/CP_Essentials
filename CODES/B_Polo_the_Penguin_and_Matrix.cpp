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

int main()
{
	int n,m,d; cin>>n>>m>>d;
	vector<int> vec(1);
	cin>>vec[0];
	int val = vec[0]%d;
	bool fl=1;
	for(int i=1;i<n*m;++i){
		int x; cin>>x;
		vec.pb(x);
		if(x%d!=val)
			fl=0;
	}
	if(!fl){
		cout<<-1<<endl;
	}
	else if(n*m==1){
		cout<<0<<'\n';

	}
    else{
	    sort(vec.begin(),vec.end());
	    vector<int> psum;
	    psum.pb(vec[0]);
	    for(int i=1;i<m*n;++i){
		    psum.pb(psum[i-1]+vec[i]);
	    }
	    int total = psum[m*n-1];
        //watch(total);
	    int ans = (total - (n*m-1)*vec[0])/d;
        //watch(ans);
	    for(int i=1;i<m*n;++i){
		    int present = (i*vec[i] - psum[i-1])/d + (total - psum[i] - (n*m-1-i)*vec[i])/d;
		    ans = min(ans,present);
	    }
	    cout<<ans<<'\n';
    }
	return 0;
}
