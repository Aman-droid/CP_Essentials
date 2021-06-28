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
multiset<pair<int,int>>inc,exc;

struct edge {
    int w;
    int id;
    int x;
};

bool comp(edge a, edge b){
    if(a.w != b.w)return a.w <b.w;
    else return a.x > b.x; 
}

void solve(){
    int n,m,wi,xi,idx;cin>>n>>m;
    //wt ,idx
    edge v[m];
    rep(i,0,m-1){

        cin>>wi>>xi;
        v[i].w = wi;
        v[i].id = i+1;
        v[i].x = xi;

        if(xi==1)inc.insert({wi,i+1});
        else exc.insert({wi,i+1});
    }
    sort(v,v+m,comp);
    vector<vector<int>>res;
    
    int rem=0; //no of edges possible(using node 1 to cur) - no of egdes included upto cur
    int cur=2,prev=1,fl=0,cnt=1;
    int high=3,low=1;
    rep(i,0,m-1){
        wi=v[i].w;
        xi=v[i].x;
        idx=v[i].id;

        if(xi==1){
            rem = ((cur*(cur-1))/2) - (i+1);
            res.pb({idx,prev,cur});
            prev=cur;
            cur++;
        }
        else{
            if(rem<=0){
                fl=1;
                break;
            }
            else{
                res.pb({idx,high,low});
                if(high-low==2){
                    high++;
                    low=1;
                }
                else{low++;}
                rem--;
            }
        }
    }
    if(fl==1)cout<<"-1"<<endl;
    else{
        sort(all(res));
        for(auto it:res){
            cout<<it[1]<<" "<<it[2]<<endl;
        }
    }

}

signed main() {
    FIO;
    int T=1;//cin>>T;
    while (T--){
       solve();
    }
    return 0;   
}