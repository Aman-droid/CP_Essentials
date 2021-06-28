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
multiset<int>m1;
multiset<int>m2;
void solve(){
    int x,n,p,val1,val2;cin>>x>>n;
    m1.insert(0);
    m1.insert(x);

    m2.insert(x);
    vector<int>ans;
    while(n--){
        cin>>p;
        auto it1 = m1.lower_bound(p);
        val1=*it1;
        it1--;
        val2=*it1;
        int val= val1-val2;
        m1.insert(p);
        //cout<<"it1===>  "<<*it1<<endl;
        //cout<<"val===>  "<<val<<endl;
        m2.erase(m2.find(val));
        m2.insert(val1-p);
        m2.insert(p-val2);
        int res= *m2.rbegin();
        ans.push_back(res);
    }
    for(auto it:ans){
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