#include<bits/stdc++.h>
#define ll long long
#define int long long 
#define endl '\n'
#define rep(i,a,b)  for(int i=a;i<=b;i++)
#define SZ(x) ((int)x.size())
#define pb push_back
#define pf push_front
#define ff first
#define ss second
#define mod 1000000007
#define INF (ll)(1e18)
#define all(c) (c).begin(),(c).end()

using namespace std;
const int mxn=2e5;

int n;
int ans[300005];
vector<pair<pair<int, int>, int> > v(300005);


signed main() {
	cin >> n;
	v.resize(n);

	rep(i,0,n-1) {
		cin >> v[i].ff.ff >> v[i].ff.ss;
		v[i].ss = i; 
	}

	sort(v.begin(), v.end());

	int rooms = 0, last = 0;
	priority_queue<pair<int, int> > pq; // min heap to store departure times.
	// priority_queue <pii, vector<pii>, greater<pii> > pq;
    
    rep(i,0,n-1) {
		if (pq.empty()) {
			last++;
			pq.push({-v[i].ff.ss, last});  // make the departure time negative so that we create a min heap (cleanest way to do a min heap... default is max in c++)
			ans[v[i].ss] = last;
		}
		else {
			pair<int, int> cur = pq.top(); // accessing the minimum departure time.
			if (-cur.ff < v[i].ff.ff) {
				pq.pop();
				pq.push({-v[i].ff.ss, cur.ss});
				ans[v[i].second] = cur.ss;
			}
			else {
				last++;
				pq.push({-v[i].ff.ss, last});
				ans[v[i].second] = last;
			}
		}

        int tmp=SZ(pq);
		rooms = max(rooms,tmp);
	}

	cout << rooms << "\n";
	for (int i = 0; i < n; i++) {
		cout << ans[i] << " ";
	}
    return 0;
}

