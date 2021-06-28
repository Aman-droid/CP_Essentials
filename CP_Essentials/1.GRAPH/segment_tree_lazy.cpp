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

//LAZY update when only needed otherwise keep a note

const int mxn=2e5;
//node=segment tree index.

ll tree[4*mxn] ,lazy[4*mxn],A[mxn];

void build(int node, int start, int end){
    if(start == end){
        //tree[si]=arr[ss];//here leaf node directly correspond element start=end=idx in the real array..
        // Leaf node will have a single element
        tree[node] = A[start];
    }
    else{
        int mid = (start + end) / 2;
        // Recurse on the left child
        build(2*node, start, mid);
        // Recurse on the right child
        build(2*node+1, mid+1, end);
        // Internal node will have the sum of both of its children
        tree[node] = tree[2*node] + tree[2*node+1];
    }
}

void updateRange(int node, int start, int end, int l, int r, int val)
{
    if(lazy[node] != 0)
    { 
        // This node needs to be updated
        tree[node] += (end - start + 1) * lazy[node];    // Update it
        if(start != end)
        {
            lazy[node*2] += lazy[node];                  // Mark child as lazy
            lazy[node*2+1] += lazy[node];                // Mark child as lazy
        }
        lazy[node] = 0;                                  // Reset it
    }

    if(start > end or start > r or end < l)              // Current segment is not within range [l, r]
        return;
    if(start >= l and end <= r)
    {
        // Segment is fully within range
        tree[node] += (end - start + 1) * val;
        if(start != end)
        {
            // Not leaf node
            lazy[node*2] += val;
            lazy[node*2+1] += val;
        }
        return;
    }
    int mid = (start + end) / 2;
    updateRange(node*2, start, mid, l, r, val);        // Updating left child
    updateRange(node*2 + 1, mid + 1, end, l, r, val);   // Updating right child
    tree[node] = tree[node*2] + tree[node*2+1];        // Updating root with max value 
}

int queryRange(int node, int start, int end, int l, int r)
{
    if(start > end or start > r or end < l)
        return 0;         // Out of range
    
	if(lazy[node] != 0){
        // This node needs to be updated
        tree[node] += (end - start + 1) * lazy[node];            // Update it
        if(start != end)
        {
            lazy[node*2] += lazy[node];         // Mark child as lazy
            lazy[node*2+1] += lazy[node];    // Mark child as lazy
        }
        lazy[node] = 0;                 // Reset it
    }

    if(start >= l and end <= r)             // Current segment is totally within range [l, r]
        return tree[node];

    int mid = (start + end) / 2;
    int p1 = queryRange(node*2, start, mid, l, r);         // Query left child
    int p2 = queryRange(node*2 + 1, mid + 1, end, l, r); // Query right child
    return (p1 + p2);
}

 
signed main()
{
	int n , q ,code, l , r , val;
	cin>>n>>q;
	build(1 , 1 , n);
 
	while(q--)
	{
		cin>>code;
		if(code == 1)
		{
			cin>>l>>r;
			cout<<queryRange(1 , 1 , n , l , r)<<endl;
		}
		else
		{
			cin>>l>>r>>val;
			updateRange(1 , 1 , n , l , r , val);
		}
	}
}
 

// const int maxN = 100001;
// int ar[maxN];
// int st[4*maxN] , lazy[4*maxN];
 
// void build(int si , int ss , int se)
// {
// 	if(ss == se)
// 	{
// 		st[si] = ar[ss];
// 		return;
// 	}
 
// 	int mid = (ss + se) / 2;
 
// 	build(2*si , ss , mid);
// 	build(2*si+1 , mid+1 , se);
 
// 	st[si] = st[2*si] + st[2*si+1];
// }
 
// int query(int si , int ss , int se , int qs , int qe)
// {
// 	if(lazy[si] != 0)
// 	{
// 		int dx = lazy[si];
// 		lazy[si] = 0;
// 		st[si] += dx * (se - ss + 1);
 
// 		if(ss != se)
// 		lazy[2*si] += dx , lazy[2*si+1] += dx;
// 	}
 
// 	if(ss > qe || se < qs) return 0;
 
// 	if(ss >= qs && se <= qe)
// 	return st[si];
 
// 	int mid = (ss + se) / 2;
// 	return query(2*si , ss , mid , qs , qe) + query(2*si+1 , mid+1 , se , qs , qe);
// }
 
// void update(int si , int ss , int se , int qs , int qe , int val)
// {
// 	if(lazy[si] != 0)
// 	{
// 		int dx = lazy[si];
// 		lazy[si] = 0;
// 		st[si] += dx * (se - ss + 1);
 
// 		if(ss != se)
// 		lazy[2*si] += dx , lazy[2*si+1] += dx;
// 	}
 
// 	if(ss > qe || se < qs) return;
 
// 	if(ss >= qs && se <= qe)
// 	{
// 		int dx = (se - ss + 1) * val;
// 		st[si] += dx;
 
// 		if(ss != se)
// 		lazy[2*si] += val , lazy[2*si+1] += val;
// 		return;
// 	}
 
// 	int mid = (ss + se) / 2;
// 	update(2*si , ss , mid , qs , qe , val);
// 	update(2*si+1 , mid+1 , se , qs , qe , val);
 
// 	st[si] = st[2*si] + st[2*si+1];
// }