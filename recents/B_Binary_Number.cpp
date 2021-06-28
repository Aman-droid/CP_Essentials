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

const int mxn=1e6+5;
int a[mxn];

void solve(){
    string s;cin>>s;
    int n=s.size();

    for(int i=1;i<=n;i++)
    	a[i]=s[i-1]-'0';

    int ct1=0;
    for(int i=2;i<=n;i++){
    	ct1+= (a[i]==1);
    }
    int ans=0, carry=0;
    
    for(int i=n;i>=1;i--){
    	a[i]+=carry;
    	if(a[i]==1){
    		a[i]++;
    		ans++;
    	}
    	carry=a[i]/2;
    	ans++;
    }

    if(ct1==0)
    	ans-=2;
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