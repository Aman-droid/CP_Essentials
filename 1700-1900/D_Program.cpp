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
const int mxn =200010;
vector<int> a(mxn,0);
vector<pair<int,int> > tree(4*mxn);


void build(int idx, int start, int end){
    if(start == end){
        //tree[si]=arr[ss];//here leaf node directly correspond element start=end=idx in the real array..
        // Leaf node will have a single element
        tree[idx].ff = a[start];
        tree[idx].ss = a[start];
    }
    else{
        int mid = (start + end) / 2;
        // Recurse on the left child
        build(2*idx, start, mid);
        // Recurse on the right child
        build(2*idx+1, mid+1, end);
        tree[idx].ff = min(tree[2*idx].ff,tree[2*idx+1].ff);
        tree[idx].ss = max(tree[2*idx].ss,tree[2*idx+1].ss);
        return;        
    }
}

pair<int,int> query(int idx, int start, int end, int l, int r)
{
    if(r < start || end < l){
        // range represented by a node is completely outside the given range
        return {INF,-INF};
    }
    if(l <= start && end <= r){
        // range represented by a node is completely inside the given range
        return tree[idx];
    }
    // range represented by a node is partially inside and partially outside the given range
    int mid = (start + end) / 2;
    pair<int,int> p1 = query(2*idx, start , mid, l, r);
    pair<int,int> p2 = query(2*idx+1, mid+1 , end, l, r);
    return {min(p1.ff,p2.ff),max(p1.ss,p2.ss)};
}
 
// pair<ll,ll> query(ll idx,ll l,ll r,ll tl,ll tr){
//     if(tl>tr)
//         return {1000000000,-1*1000000000};
//     if(tl==l && tr==r)
//             return tree[idx];    
    
//     pair<ll,ll> t1,t2;

//     ll mid = (l+r)/2;
//     t1 = query(2*idx,l,mid,tl,min(tr,mid));
//     t2 = query(2*idx+1,mid+1,r,max(mid+1,tl),tr);
//     return {min(t1.ff,t2.ff),max(t1.ss,t2.ss)};
// }



void solve(){
    ll n,q; cin>>n>>q;
    string s; cin>>s;
 
    for(int i=1;i<=n;i++){
        if(s[i-1]=='+')
                a[i]=a[i-1]+1;
        else
                a[i]=a[i-1]-1;
    }   

    build(1,1,n);
 
    while(q--){
        ll l,r; cin>>l>>r;
        ll mnn=0,mxx=0;
   
        if(l>1){
           pair<ll,ll> pr = query(1,1,n,1,l-1);
           mnn = min(pr.ff,mnn);
           mxx = max(pr.ss,mxx);
        }
   
        ll dif = a[r]-a[l-1];
        if(r!=n){
            pair<int,int> t = query(1,1,n,r+1,n);
            mnn = min(t.ff-dif,mnn);
            mxx = max(t.ss-dif,mxx);
        }
        cout<<mxx-mnn+1<<endl;
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
