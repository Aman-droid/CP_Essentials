#include<bits/stdc++.h>
#define ll long long
#define int long long 
#define endl '\n'
#define rep(i,a,b)  for(int i=a;i<=b;i++)
#define pii pair<int,int>
#define vpii vector<pii>
#define SZ(x) ((int)x.size())
#define FIO  ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define watch(x)cout<<(#x)<<" is "<<(x)<<"\n"
#define watch2(x,y)cout<<(#x)<<" is "<<(x)<<" and "<<(#y)<<" is "<<(y)<<"\n"
#define pb push_back
#define pf push_front
#define ff first
#define ss second
#define mod 1000000007
#define INF (int)(1e18)
#define all(c) (c).begin(),(c).end()

using namespace std;
const int mxn=1e7+2;

//spf smallest prime factor upto mxn // T==O(mxn)
int spf[mxn];

void sieve(){
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
vector<int>vec;
map<int,int>mp;
int pfac(int N){
    vec.clear();    
    mp.clear();

    int res=1;
    while(N!=1){
        vec.pb(spf[N]);
        N = N/spf[N];
    }

    for(auto it:vec){
        mp[it]++;
    }
    for(auto it:mp){
        if(it.ss%2==1){
            res*=it.ff;
        }
    }
    return res;
}

void solve(){
    int n,k,x;cin>>n>>k;
    int a[n];

    set<int>st;
    int cnt=1;

    rep(i,0,n-1){
        cin>>x;
        a[i] = pfac(x);
    }

    rep(i,0,n-1){
        if(st.find(a[i]) != st.end()){
            st.clear();
            cnt++;
            st.insert(a[i]);
        }
        else{
            st.insert(a[i]);
        }
    }

    cout<<cnt<<endl;

}

signed main() {
    FIO;
    //prefac();
    sieve();
    int T=1;cin>>T;
    while (T--){
       solve();
    }
    return 0;   
}

