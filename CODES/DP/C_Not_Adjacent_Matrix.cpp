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
    int n;cin>>n;
    if(n==1){
        cout<<"1"<<endl;
        return; 
    }
    else if(n==2){
        cout<<"-1"<<endl;
        return; 
    }
    else{
        int tmp=1;
        deque<int>od,ev;
        rep(i,1,n*n){
            if(i%2==1){
                od.push_back(i);
            }
            else{
                ev.push_back(i);
            }
        }
        rep(i,1,n){
            rep(j,1,n){
                if(!od.empty()){
                    cout<<od.front()<<" ";
                    od.pop_front();
                }
                else{
                    cout<<ev.front()<<" ";
                    ev.pop_front();
                }
            }
            cout<<endl;
        }
    }
}
signed main() {
    FIO;
    int T=1;cin>>T;
    while (T--){
       solve();
    }
    return 0;   
}