//Kahn's algorithm...can have many topological sorting
//exist when it does not contain any cycle
#include<bits/stdc++.h>
#define ll long long int
#define endl '\n'
#define vll vector< ll >
#define vpll vector<pair<ll,ll>>
#define SZ(x) ((int)x.size())
#define FIO  ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define watch(x) cout << (#x) << " is " << (x) << "\n"
#define watch2(x,y) cout <<(#x)<<" is "<<(x)<<" and "<<(#y)<<" is "<<(y)<<"\n"
#define mp make_pair
#define pb push_back
#define pf push_front
#define mod 1000000007

using namespace std;
vector<int >adj[10001];
vector<int >res;
int inc[10001];
bool kahn(int n)
{
    priority_queue<int ,vector<int>,greater<int>>  q;                     // for the lexigraphic order
    for(int i=1;i<=n;i++)
    {
        if(inc[i]==0)
            q.push(i);
    }
    while(!q.empty())
    {
        int curr=q.top();
        res.pb(curr);
        q.pop();
        for(int child:adj[curr])
        {
            inc[child]--;
            if(inc[child]==0)
                q.push(child);
        }
    }
    return res.size()==n;   //to exist ressize must be  n
}

int main()
{
	ll T=1;
	while(T--)
	{
            int n,m,u,v;cin>>n>>m;

            for(int i=1;i<=m;i++)
            {
                cin>>u>>v;
                adj[u].pb(v);
                inc[v]++;
            }
            bool ans=kahn(n);
            if(ans==false)
                cout<<"topological sort will not exist"<<endl;
            else
                for(int i=0;i<SZ(res);i++)
                    cout<<res[i]<<" ";
	}
	return 0;
}
