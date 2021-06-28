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
    int n;cin >> n;
    int ans=0;
    for(int i=1;i<=30;i++){
		if(n == (1LL << i)){
			cout << "-1" << endl;
			return;
		}
	}
    
    //1, 3, 5, 7, 9   ans+= terms *1( except for 1)
    //2, 6, 10, 14, 18  ans+=terms *2
    //4, 12, 20 ,    ans+=terms*4

	for (int i = 1; i <= n; i = (i << 1)) {
		ans += ((n - i) / (2 * i)) * i;
	}

	for (int i = 2; i < n; i = (i << 1)) {
		ans += i;
	}

	cout << ans <<endl;
}

signed main() {
    FIO;
    int T=1;cin>>T;
    while (T--){
       solve();
    }
    return 0;   
}