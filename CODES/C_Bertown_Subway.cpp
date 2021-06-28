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

const int mxn=2e5;
int R[mxn]; // Rank no of node connected to current par..
int par[mxn];

int find(int v) {
    if(par[v]==-1)
        return v;
    else{
        int x=find(par[v]);
        par[v]=x;
        return x;
    }
}

//Union by rank node having larger number of childs will be parent 
void merge(int a,int b){
    a=find(a);
    b=find(b);
    if(a==b)return;

    if(R[a]>R[b]){	//a will be parent 
        par[b]=a;
        R[a]+=R[b];
    }
    else {	//b will be parent 
        par[a]=b;
        R[b]+=R[a];
    }
} 

signed main()
{
	int n , x;
	cin>>n;
	rep(i,1,n){
        par[i] = -1 ; 
        R[i] = 1;
    }
	
	rep(i ,1 ,n){
	    cin>>x ; 
        merge(find(i) , find(x));
    }
	
	vector<int> res;
   
	rep(i ,1, n){
	    if(par[i] == -1)
	        res.pb(R[i]);
    }
	
	sort(res.begin() , res.end());
	
	if(res.size() == 1){
		cout<<res[0]*res[0]<<endl;
	}
	else
	{
		int ans = res[res.size()-1] + res[res.size()-2];
		ans *= ans;
		res.pop_back();
		res.pop_back();
		
		for(int i=0;i<res.size();i++)
		ans += res[i]*res[i];
		cout<<ans<<endl;
	}
    return 0;
}



