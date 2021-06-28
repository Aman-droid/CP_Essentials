#include<bits/stdc++.h>
#define ll long long 
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
    int n,m,x;cin>>n>>m;
    multiset<int>s;
    rep(i,0,n-1){
        cin>>x;
        s.insert(x);
    }
    rep(i,0,m-1){
        cin>>x;
        auto it= s.lower_bound(x);
        if(it==s.end()){
            if(s.empty())
                cout<<"-1"<<endl;
            else{
                auto it1 = s.rbegin();
                cout<<*it1<<endl;
                s.erase(--s.end());
            }
        }
        else if(*it == x){
            cout<<*it<<endl;
            s.erase(it);
        }
        else{
            if(it==s.begin()){
                cout<<"-1"<<endl;
            }
            else{
                it--;
                cout<<*it<<endl;
                s.erase(it);
            }
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