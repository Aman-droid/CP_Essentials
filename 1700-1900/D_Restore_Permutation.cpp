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
const int mxn=2e5+5;
int BIT[mxn], a[mxn], n;

//add "delta" at index "x"
void update(int x, int delta){
    for(; x <= n; x += x&-x)
          BIT[x] += delta;
}

//returns the sum of first x elements in given array a[]
int query(int x){
    int sum = 0;
    for(; x > 0; x -= x&-x)
        sum += BIT[x];
    return sum;
}


int binary_search(int v) // v is the value we are searching
{
	int l = 1, r = n;
    int res = 0;
	while(l <= r){
		int mid = (l+r) / 2;
		if(query(mid) <= v){
			l = mid+1;
            res = mid;
        }
		else{
			r = mid-1;
        }
	}
	return res+1;
}

void solve(){    
    cin>>n;
    int s[n+1];
    vector<int>res;
    rep(i,1,n){
        cin>>s[i];
    }
    for(int i = 1; i <= n; i++){
        update(i, i); //add value a[i] at the index i initially BIT[i] = 0
    }
    for(int i=n;i>=1;i--){
        int x=binary_search(s[i]);//idx
        //watch(x);
        // rep(i,1,n){
        //     cout<<BIT[i]<<" ";
        // }
        update(x,-x);
        res.pb(x);
    }
    reverse(all(res));
    for(auto it:res){
        cout<<it<<" ";
    }
    cout<<endl;
}

signed main() {
    FIO;
    int T=1;//cin>>T;
    while (T--){
       solve();
    }
    return 0;   
}

