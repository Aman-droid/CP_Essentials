// /*
//     minimum spanning tree   =>not unique
//     cost =weight of all egges
//     METHOD-1==>Kruskal
//         TC==(E*logV)
//         space comp = O(E+V)

//         1.sort all edges in increaing order of the weight
//         2.take edge from start 
//             i.)if it doesnot make cycle then include it
//             ii.)otherwise discard
            

//     METHOD-2==>prim (greedy)
//         1.select a vectex to start
//         2.while(there are still nontree vertices)
//             select the edge of min w bw tree and nontree vertex
//             add selected edge and vertex to the tree 

// */


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
//--------------------------------------------------------------------------------------------------------//
using namespace std;
struct edge
{
    int a;
    int b;
    int w;
};

edge arr[100000];       // array of type edge
int par[10001];

bool comp(edge a,edge b)
{
    if(a.w < b.w)
        return true ;        //true means a will come before b
    else
        return false;       //b will come before a
}

int find(int a)
{
    if(par[a]== -1)
        return a;
    else
    {
        int x=find(par[a]);             //can also return par[a]=find(par[a]);
        par[a]=x;
        return x;
    }
}
void merge(int a,int b)                //same as union of dsu
{
    par[a]=b;
}

int main()
{
    //FIO;
	ll T=1;
	while(T--)
	{
        int n,m,a,b,w;
        cin>>n>>m;
        for(int i =1;i<=n;i++)
            par[i]=-1;
        for(int i=0;i<m;i++)
        {
            cin>>arr[i].a>>arr[i].b>>arr[i].w;
        }
        sort(arr,arr+m,comp);
        int sum=0;
        for(int i=0;i<m;i++)
        {
            a=find(arr[i].a);
            b=find(arr[i].b);
            if(a!=b)
            {
                merge (a,b);
                sum+=arr[i].w;
            }
        }
        cout<<sum<<endl;
	}
	return 0;
}

/*
union normal find = O(n)
union path compression = O(log(n))
union by rank/size =
*/
