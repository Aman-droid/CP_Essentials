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
int spf[mxn];
vector<int>dp(mxn,0);
vector<int>vis(mxn,0);
void sieve()
{
    spf[0] = spf[1] = 1;
    for (int i = 2; i < mxn; i++) {
        if (spf[i] == 0) {
            for (int j = i * 2; j < mxn; j += i) {
                if (spf[j] == 0) {
                    spf[j] = i;
                }
            }
            spf[i] = i;
        }
    }
}

void solve(){
    int n,x,tmp,mx;cin>>n;
    map<int,int>mp;
    
    rep(i,0,n-1){
        cin>>x;
        mx=0;
        set<int>s;
        int num=x;
        
        while(num!=1){
            tmp=spf[num];
            s.insert(tmp);
            num=num/tmp;
        }
        
        for(auto it:s){
            mx=max(mx,mp[it]);
        }
        for(auto it:s){
            mp[it] = mx+1;
        }
    }

    int ans=1;
    for(auto it:mp){
        ans=max(ans,it.second);
    }
    cout<<ans<<endl;
}

signed main() {
    FIO;
    int T=1;//cin>>T;
    sieve();
    while (T--){
       solve();
    }
    return 0;   
}

