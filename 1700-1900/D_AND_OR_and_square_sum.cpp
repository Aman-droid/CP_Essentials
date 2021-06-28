#include<bits/stdc++.h>
#define ll long long
#define int long long 
#define endl '\n'
#define rep(i,a,b)  for(int i=a;i<=b;i++)
#define SZ(x) ((int)x.size())
#define FIO  ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define mod 1000000007
#define INF (ll)(1e18)
#define all(c) (c).begin(),(c).end()
using namespace std;

const int mxn=2e5;

void solve(){
    FIO;    
	int n,x;cin>>n;
	vector<int> cnt(20);
	rep(i,0,n-1){
		cin>>x;
		rep(j,0,19){
            if(x & 1<<j){
			    cnt[j]++;
		    }
        }
	}
	int ans=0;

	rep(i,0,n-1){
		x=0;
		rep(j,0,19){
            if(i<cnt[j])
                x += 1<<j;
        }
		ans+= (x*x);
	}
    cout<<ans<<endl;
}
signed main() {
    FIO;
    int T=1;//cin>>T;
    while (T--){
       solve();
    }
    return 0;   
}