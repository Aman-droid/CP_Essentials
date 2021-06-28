#include<bits/stdc++.h>
#define ll long long int
#define endl '\n'
#define vll vector< ll >
#define rep(i,a,b)  for(int i=a;i<=b;i++)
#define pii pair<int,int>
#define SZ(x) ((int)x.size())
#define FIO  ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define watch(x) cout << (#x) << " is " << (x) << "\n"
#define mp make_pair
#define pb push_back
#define pf push_front
#define ff first
#define ss second
#define mod 1000000007
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
//--------------------------------------------------------------------------------------------------------//

/*ll solve(ll a[], ll n)
{
    vector<int>res;
    pair<ll,ll>b[n];
    rep(i,0,n-1){
        b[i].ff=a[i];
        b[i].ss=i;
    }
    sort(b,b+n);
    vector<bool> vis(n,false);
    ll ans=0; 
 
    rep(i,0,n-1)
    {
        if(vis[i] || b[i].ss==i)
            continue;
        res.clear();
        int cnt=0;
        int j=i;
        while(!vis[j])
        {
            res.pb(j);
            vis[j]=1;
            j=b[i].ss;
        }
        if(SZ(res)>1)
        {
            
        }
        
    }
 
    // Traverse array elements
    for (int i = 0; i < n; i++)
    {
        // already swapped and corrected or
        // already present at correct pos
        if (vis[i] || arrPos[i].second == i)
            continue;
 
        // find out the number of  node in
        // this cycle and add in ans
        int cycle_size = 0;
        int j = i;
        while (!vis[j])
        {
            vis[j] = 1;
            // move to next node
            j = arrPos[j].second;
            cycle_size++;
        }
 
        // Update answer by adding current cycle. 
        if (cycle_size > 0)
        {
            ans += (cycle_size - 1);
        }
    }
 
    // Return result
    return ans;
}*/
 
void solve(ll a[],ll n)
{
    vector<pair<ll,ll>>res;
    rep(i,0,n-1)
    {
        int x=i;
        rep(j,0,n-1)
        {
            if(a[j]<a[x])
                x=j;
        }
        if(x!=i)
        {
            swap(a[i],a[x]);
            res.pb({i,x});
        }
    }
    cout<<SZ(res)<<endl;
    for(auto it:res)
    {
        cout<<it.ff<<" "<<it.ss<<endl;
    }
}

int main()
{
    ll n;cin>>n;
    ll a[n];
    rep(i,0,n-1)cin>>a[i];
    solve(a, n);
    return 0;
}