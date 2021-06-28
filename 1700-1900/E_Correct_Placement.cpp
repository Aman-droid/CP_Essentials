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
const int mxn=2e5;

void solve(){
    int n;cin>>n;
    vector<pair<pair<int,int>,int>> v(n,{{0,0},0});
    
    for(int i=0;i<n;i++){
        cin>>v[i].ff.ff>>v[i].ff.ss;
        
        int val = min(v[i].ff.ff,v[i].ff.ss);

        v[i].ff.ff = max(v[i].ff.ff,v[i].ff.ss);
        v[i].ff.ss = val;
        v[i].ss = i;

    }

    int ans[n];
    sort(v.begin(),v.end());
    int idx=-1;

    for(int i=0;i<n;i++){
        int j=i;
        while(j<n&&v[i].ff.ff==v[j].ff.ff)
            j++;

        if(idx==-1){
            for(int p=i;p<j;p++)
                ans[v[p].ss]=-1;
        }
        else{
            for(int p=i;p<j;p++){
                ans[v[p].ss]=-1;
                if(v[p].ff.ss>v[idx].ff.ss){
                    ans[v[p].ss]=v[idx].ss+1;
                }
            }
        }

        for(int p=i;p<j;p++){
            if(idx==-1||v[p].ff.ss<v[idx].ff.ss)
                idx=p;
        }
            i=j-1;
    }

    for(int i=0;i<n;i++)
        cout<<ans[i]<<" ";

    cout<<endl;
}


signed main() {
    FIO;
    int T=1;cin>>T;
    while (T--){
       solve();
    }
    return 0;   
}
