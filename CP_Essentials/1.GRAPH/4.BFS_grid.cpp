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
int vis[9][9], dis[9][9];
int x2,y2;
int dx[] = { -2 , -1 , 1 , 2 , 2 , 1 , -1 , -2};
int dy[] = { 1 , 2 , 2 , 1 , -1 , -2 , -2 , -1};

bool isValid(int x,int y)
{
    if(x<1 || x>8 || y<1 || y>8)
        return false;
    if(vis[x][y]==1)
        return false;
    return  true;
}

int BFS(int x,int y)
{
    queue<pair<int,int >>q;
    dis[x][y]=0;
    vis[x][y]=1;
    q.push({x,y});
    if(x==x2 && y==y2)
        return dis[x][y];
    while(!q.empty())
    {
        int cur_x=q.front().first;
        int cur_y=q.front().second;
        q.pop();
        for(int i=0;i<8;i++)
        {
            if(isValid(cur_x +dx[i],cur_y +dy[i]))
            {
                x=cur_x +dx[i];
                y=cur_y +dy[i];
                dis[x][y]=dis[cur_x][cur_y]+1;
                vis[x][y]=1;
                q.push({x,y});
                if(x==x2 && y==y2)
                    return dis[x][y];
            }
        }
    }
}


int f1(char c)
{
    int res = c-'a' +1;
    return res;
}

int main()
{
	ll T=1;
	while(T--)
	{
        int x1,y1,t;
        cin>>t;
        while(t--)
        {
            char a,b;
            cin>>a>>b;
            x1=f1(a);
            y1=b-'0';

            cin>>a>>b;
            x2=f1(a);
            y2=b-'0';
            rep(i,1,8)
                rep(j,1,8)
                {
                    vis[i][j]=0;
                    dis[i][j]=0;
                }
            int ans =BFS(x1,y1);
            cout<<ans<<endl;
        }

	}
	return 0;
}
