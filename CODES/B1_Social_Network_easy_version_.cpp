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
    int n,k,N,x;cin>>n>>k;
    int a,b;
    set<int>s;
    deque<int>dq;
    rep(i,0,n-1){
        cin>>x;
        N=SZ(s);
        if(s.count(x)){
            continue;
        }
        else{
            if(N>=k){
                a=dq.back();
                s.erase(a);
                dq.pop_back();
                dq.push_front(x);
                s.insert(x);
            }
            else{
                dq.push_front(x);
                s.insert(x);
            }
        }
    }
    cout<<SZ(dq)<<endl;
    for(auto it:dq){
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