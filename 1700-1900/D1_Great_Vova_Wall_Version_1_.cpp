#include<bits/stdc++.h>
#define ll long long
#define int long long 
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
#define INF (ll)(1e18)
#define all(c) (c).begin(),(c).end()

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
//-------------------soln-----------------------------//

const int mxn=2e5;
int n;
int a[mxn];

void solve(){
    int j;
    cin>>n;
	rep(i,0,n-1){
        cin>>a[i];
		a[i] &= 1;
	}
	
	set<pair<int, int>> seg, even;
	rep(i,0,n-1){
		j = i;
        while (j + 1 < n && a[j + 1] == a[i]) 
            j++;

		seg.insert({i, j});
		if ((j - i + 1) % 2 == 0)
			even.insert({i, j});

		i = j;
	}
	
	while (seg.size() > 1 && !even.empty()){
		auto cur = *even.begin();

		even.erase(cur);
		seg.erase(cur);
		
        auto it = seg.lower_bound(cur);//right

		if (it != seg.end()){
			cur.second = it->second;
			if ((it->second - it->first + 1) % 2 == 0)
				even.erase(*it);

			seg.erase(it);
		}

		it = seg.lower_bound(cur);
		if (it != seg.begin()){
			--it;                   //left
			cur.first = it->first;
			if ((it->second - it->first + 1) % 2 == 0)
				even.erase(*it);
			seg.erase(it);
		}

		seg.insert(cur); //new segment 

		if ((cur.second - cur.first + 1) % 2 == 0)
			even.insert(cur);
	}
	
	if(seg.size() == 1)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
}

signed main() {
    FIO;
    int T=1;//cin>>T;
    while (T--){
       solve();
    }
    return 0;   
}



