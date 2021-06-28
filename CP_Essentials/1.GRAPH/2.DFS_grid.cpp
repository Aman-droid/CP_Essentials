/*
You are given a map of a building, and your task is to count the number of its rooms. The size of the map is n×m squares, and each square is either floor or wall. You can walk left, right, up, and down through the floor squares.
Input
The first input line has two integers n and m: the height and width of the map.
Then there are n lines of m characters describing the map. Each character is either . (floor) or # (wall).

Output
Print one integer: the number of rooms.
*/
#include<bits/stdc++.h>
#define ll long long int
#define endl '\n'
#define vll vector< ll >
 
#define rep(i,a,b)  for(ll i=a;i<=b;i++)
#define vpll vector<pair<ll,ll>>
#define SZ(x) ((int)x.size())
#define FIO  ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define watch(x) cout << (#x) << " is " << (x) << "\n"
#define watch2(x,y) cout <<(#x)<<" is "<<(x)<<" and "<<(#y)<<" is "<<(y)<<"\n"
#define mp make_pair
#define pb push_back
#define pf push_front
#define mod 1000000007
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
using namespace std;
int vis[1005][1005];
vector<string> t;
int dx[] = { 1 , -1 , 0, 0};
int dy[] = { 0 , 0, 1 , -1};
int n,m;
bool isValid(int x,int y){
    if(x<0 || x>n-1 || y<0 || y>m-1)
        return false;
    if(vis[x][y]==1)
        return false;
    return  true;
}
 
void dfs_grid(int x,int y)
{
    vis[x][y]=1;
    //cout<<"x==    "<<x<<"     y===   "<<y<<endl;
    for(int i=0;i<4;i++)
    {
        //xn = x + dx[i] ;
        //yn = y + dy[i] ;
        if(isValid(x + dx[i],y + dy[i]) && t[x + dx[i]][y + dy[i]]=='.'){
            dfs_grid(x+dx[i],y + dy[i]);
        }
    }
}
 
int main()
{
	ll T=1;
	while(T--)
	{
        cin>>n>>m;
        t.clear();
        rep(i,1,n){
            string x;cin>>x;
            t.pb(x);
        }
        memset(vis,0,sizeof(vis));
 
        int cc=0;
 
        rep(i,0,n-1){
            rep(j,0,m-1){
                if(!vis[i][j] && t[i][j]=='.'){
                    //cout<<cc<<endl;
                    dfs_grid(i,j);
                    cc++;
                }
            }
        }
        cout<<cc<<endl;
 
	}
	return 0;
}