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
    string s;cin>>s;
    int n=SZ(s);
    int x,l,r,pos,ans; 
    char c;
    vector<set<int>>st(26);

    rep(i,0,n-1){
        st[s[i]-'a'].insert(i);
    }
    int q;cin>>q;

    while(q--){
        cin>>x;
        if(x==1){
            cin>>pos>>c;
            pos--;
            st[s[pos]-'a'].erase(pos);
            s[pos]=c;
            st[c-'a'].insert(pos);
        }
        else{
            cin>>l>>r;
            l--;
            r--;
            ans=0;
            for(int ch=0;ch<26;ch++){
                auto it=st[ch].lower_bound(l);
                if(it!=st[ch].end() && *it<=r){
                    ans++;
                }
            }
            cout<<ans<<endl;
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