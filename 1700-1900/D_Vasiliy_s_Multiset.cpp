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

const int mxn=2e5;
struct node{
	int val;
	int cnt;
	node* child[2];
};
 
node* getnode(){
	node* np = new node;
	np->child[0] = np->child[1] = NULL;
	np->val = 1;
	np->cnt = 0;
	return np;
}
 
void insert(int N , node* root){
	node* tmp = root;

	for(int i=30;i>=0;i--){
		bool b = N & (1<<i);
		if(tmp->child[b]==NULL)
			tmp->child[b] = getnode();

		tmp = tmp->child[b];
		tmp->cnt++;
	}
	tmp->val = N;
}
 
void delNode(int N , node* root){
	node* tmp = root;
	for(int i=30;i>=0;i--){
		bool b = N & (1<<i);
		tmp = tmp->child[b];
		tmp->cnt--;
	}
}
 
int getMax(int N , node* root){
	node* tmp = root;
	node* x;

	for(int i=30;i>=0;i--){
		bool b = !(N & (1<<i));

		if(tmp->child[b]==NULL)
			tmp = tmp->child[!b];
		else{
			x=tmp->child[b];
			if(x->cnt==0)
				tmp = tmp->child[!b];
			else
				tmp = tmp->child[b];
		}
	}

	return tmp->val^N;
}

void solve(){
	node* root = new node;
	root->child[0] = root->child[1] = NULL;
	root->cnt = root->val = 0;
	
	int n,q,x;cin>>q;
	char ch;

	insert(0,root);

	while(q--){
		cin>>ch>>n;
		if(ch=='+') 
			insert(n,root);
		else if(ch=='-') 
			delNode(n,root);
		else
			cout<<getMax(n,root)<<'\n';
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
