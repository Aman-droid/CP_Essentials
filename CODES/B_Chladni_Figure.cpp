#include<bits/stdc++.h>
#define ll            long long
#define int           long long 
#define endl          '\n'
#define rep(i,a,b)    for(int i=a;i<=b;i++)
#define ren(i,a,b)    for(int i=a;i>=b;i--)
#define pii           pair<int,int>
#define SZ(x)         ((int)x.size())
#define FIO           ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define watch(x)      cout<<(#x)<<" is "<<(x)<<"\n"
#define watch2(x,y)   cout<<(#x)<<" is "<<(x)<<" and "<<(#y)<<" is "<<(y)<<"\n"
#define pb            push_back
#define ff            first
#define ss            second
#define mod           1000000007
#define INF (ll)      (1e18)
#define all(c)        (c).begin(),(c).end()

using namespace std;

ll power(ll a, ll b){ ll res=1; a=a%mod; while(b>0){ if(b&1){
    res=(res*a)%mod;b--;} a=(a*a)%mod;b>>=1;} return res;
}
ll gcd(ll a, ll b){return (b==0)?a:gcd(b,a%b);}
//-------------------soln-----------------------------//

const int mxn=2e5+5;
int a[mxn],b[mxn];
//KMP Algo
/*
vector<int> prefix_function(vector<int> v) {
    int n = (int)v.size();

    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        while (j > 0 && v[i] != v[j])
            j = pi[j-1];
        if (v[i] == v[j])
            j++;
        pi[i] = j;
    }
    return pi;
}
*/
void solve(int T){
    int n,m;cin>>n>>m;
    set<pii> st;

    rep(i,0,m-1){
        cin>>a[i]>>b[i];
        a[i]--;
        b[i]--;
        if(a[i]>b[i]) swap(a[i],b[i]);
        st.insert({a[i],b[i]});
    }

    int fl=0;

    for(int k=1;k<n;k++) {
        bool flag = 1;
        if(n%k==0) {
            for(int i=0;i<m;i++) {
                int nA = (a[i] + k)%n; 
                int nB = (b[i] + k)%n;
                
                if(nA>nB) swap(nA,nB);
                //check 
                if(!st.count({nA,nB})){ 
                    flag = 0;
                }
            }
            if(flag){
                cout<<"YES"<<endl;
                return;
            }
        }
    }
    cout<<"NO"<<endl;
}

signed main() {
    FIO;
    int T=1;//cin>>T;
    for(int i=1;i<=T;i++){
        solve(i);
    }
    return 0;   
}
 
