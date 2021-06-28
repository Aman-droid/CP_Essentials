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
//TRIE..
//0(length of maximum string*queries)

const int SIZE = 26;

struct Trienode{
    char val;
    int count;
    int endsHere;
    Trienode *child[SIZE];
};
 
Trienode *getNode(int index){
    Trienode *newnode = new Trienode;
    newnode->val = 'a'+index;
    newnode->count = newnode->endsHere = 0;
    for(int i=0;i<SIZE;i++)
        newnode->child[i] = NULL;
    
    return newnode;
}

/** Inserts a word into the trie. */
void insert(Trienode *root,string word) {
    Trienode *curr = root;
    int index;
    for(int i=0;word[i]!='\0';++i)
    {
        index = word[i]-'a';
        if(curr->child[index]==NULL)
            curr->child[index] = getNode(index);

        curr->child[index]->count +=1;
        curr = curr->child[index];
    }
    curr->endsHere +=1;
}


 /** Returns if the word is in the trie. */
bool search(Trienode *root , string word) {
    Trienode *curr = root;
    int index;
    for(int i=0;word[i]!='\0';++i){
        index = word[i]-'a';
        if(curr->child[index]==NULL)
            return false;
        curr = curr->child[index];
    }
    return (curr->endsHere > 0);
}

/** Returns if there is any word in the trie that starts with the given prefix. */
bool startsWith(Trienode *root ,string prefix) {
    Trienode *curr = root;
    int index;
    for(int i=0;prefix[i]!='\0';++i){
        index = prefix[i]-'a';
        if(curr->child[index]==NULL)
            return false;
            curr = curr->child[index];
        }
    return (curr->count > 0);
}

void solve(){
    Trienode *root = getNode('/'-'a');
 
    int n ,q, code;cin>>q;
    string st;
 
    while(q--)
    {
        cin>>code;
        if(code == 1){
            cout<<"Enter string to insert"<<endl;
            cin>>st;
            cout<<st<<endl;
            insert(root , st);
        }
        else if(code == 2){
            cout<<"Enter string to search\n";
            cin>>st;
            cout<<st<<endl;
            cout<<search(root , st)<<endl;
        }
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


//TECH DOSE
//Code n code

// struct node{
//     bool endOfWord;
//     node* ar[SIZE];
// };

// node* getNode()
// {
//     node* n = new node;
//     n->endOfWord = false;
 
//     for(int i=0;i<SIZE;i++)
//     n->ar[i] = NULL;
 
//     return n;
// }

 
// bool search(node *root , string st)
// {
//     node *tempRoot = root;
 
//     for(int i=0;i<st.size();i++)
//     {
//         int index = st[i] - 'a';
 
//         if(tempRoot->ar[index] == NULL)
//         return false;
 
//         tempRoot = tempRoot->ar[index];
//     }
 
//     return tempRoot->endOfWord;
// }

// void insert(node *root , string st)
// {
//     node *tempRoot = root;
 
//     for(int i=0;i<st.size();i++)
//     {
//         int index = st[i] - 'a';
 
//         if(tempRoot->ar[index] == NULL)
//         tempRoot->ar[index] = getNode();
 
//         tempRoot = tempRoot->ar[index];
//     }
 
//     tempRoot->endOfWord = true;
// }


/*
https://codeforces.com/contest/706/problem/D

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

*/