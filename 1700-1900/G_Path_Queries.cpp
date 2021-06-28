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
const int mxn=2e5+2;

vector<pair<int,pair<int,int>>>arr;
int par[mxn];
int R[mxn]; // Rank no of node connected to current par..
unordered_map<int,int>mp;
int res;
int find(int v) {
    if(par[v]==-1)
        return v;
    else{
        int x = find(par[v]);
        par[v] = x;
        return x;
    }
}

bool merge(int a,int b){
    a=find(a);
    b=find(b);
    if(a==b)
        return false;
    
    if(R[a]<R[b]) swap(a,b); //a will be parent 
    res -= (R[a]*1LL*(R[a]-1)/2);
    res -= (R[b]*1LL*(R[b]-1)/2);

    par[b] = a;
    R[a] += R[b];
    
    res += (R[a]*1LL*(R[a]-1)/2);
    //watch(res);
    return true;
}

void solve(){
    int n,q,u,v,a,b,w,x;cin>>n>>q;
    vector<pii>query; 
    int m=n-1;
    //initials
    for(int i =1;i<=n;i++){
        par[i]=-1;
        R[i]=1;
    }
    
    for(int i=0;i<m;i++){
        cin>>u>>v>>w;
        arr.pb({w,{u,v}});
    }

    sort(all(arr));
    reverse(all(arr));

    res=0;
    int ans[q+1]={0};

    rep(i,1,q){
        cin>>x;
        query.pb({x,i});
    }

    sort(all(query));
    pair<int,pii> cur;
    //watch(n);

    rep(i,0,q-1){
        int Q = query[i].ff;
        while(!arr.empty()){
            cur = arr.back();
            if(cur.ff<=Q){
                merge(cur.ss.ff,cur.ss.ss);
                arr.pop_back();
            }
            else{
                break;
            }
        }
        
        // for(auto it:mp){                 //giving TLE
        //     //cout<<it.ss<<endl;
        //     tmp+=(it.ss)*1LL*(it.ss-1)/2;
        // }   
        ans[query[i].ss]=res;
    }

    rep(i,1,q){
        cout<<ans[i]<<" ";
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