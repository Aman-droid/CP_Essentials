#include<bits/stdc++.h>
#define ll            long long
#define int           long long 
#define endl          '\n'
#define rep(i,a,b)    for(int i=a;i<=b;i++)
#define ren(i,a,b)    for(int i=a;i>=b;i--)
#define pii           pair<int,int>
#define SZ(x)         ((int)x.size())
#define FIO           ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define watch(x)      cout<<(#x)<<" is "<<(x)<<"\n"
#define watch2(x,y)   cout<<(#x)<<" is "<<(x)<<" and "<<(#y)<<" is "<<(y)<<"\n"
#define pb            push_back
#define ff            first
#define ss            second
#define mod           1000000007
#define INF (ll)      (1e18)
#define all(c)        (c).begin(),(c).end()

using namespace std;

ll power(ll a, ll b){ ll res=1; a=a%mod; while(b>0){ if(b&1){
    res=(res*a)%mod;b--;} a=(a*a)%mod;b>>=1;} return res;
}
ll gcd(ll a, ll b){return (b==0)?a:gcd(b,a%b);}
//-------------------soln-----------------------------//

int ar[3];
int I[3][3],T[3][3];

void mul(int A[3][3],int B[3][3], int dim){

    int res[dim+1][dim+1];

    rep(i,1,dim){
        rep(j,1,dim){
            res[i][j]=0;
            rep(k,1,dim){
                ll x=A[i][k]*B[k][j]%mod;
                res[i][j]+=x;
            }
        }
    }

    rep(i,1,dim){
        rep(j,1,dim){
            A[i][j]=res[i][j];
        }
    }
}

ll fibn(ll n){
    if(n<=2)
        return ar[n];
    
    //INDENTITY MATRIX
    I[1][1]=I[2][2]=1;
    I[1][2]=I[2][1]=0;

    //recursion Matrix
    T[1][1]=0;
    T[1][2]=T[2][1]=T[2][2]=1;
    
    n=n-1;

    while(n){
        if(n%2==1)
            mul(I,T,2),n--;
        else 
            mul(T,T,2),n/=2;
    }

    ll x=(ar[1]*I[1][1]+ar[2]*I[2][1])%mod;
    
    return x;
}

signed main() {
    FIO;
    int T=1;//cin>>T;
    while (T--){
        ll n;cin>>n;
        ar[0]= 0;
        ar[1]= 1;
        ar[2]= 1;
        cout<<fibn(n)<<endl;
    }
}


// // C++ program to find value of f(n) where f(n)
// // is defined as
// //    F(n) = F(n-1) + F(n-2) + F(n-3), n >= 3
// // Base Cases :
// //    F(0) = 0, F(1) = 1, F(2) = 1
// #include<bits/stdc++.h>
// using namespace std;
 
// // A utility function to multiply two matrices
// // a[][] and b[][].  Multiplication result is
// // stored back in b[][]
// void multiply(int a[3][3], int b[3][3])
// {
//     // Creating an auxiliary matrix to store elements
//     // of the multiplication matrix
//     int mul[3][3];
//     for (int i = 0; i < 3; i++)
//     {
//         for (int j = 0; j < 3; j++)
//         {
//             mul[i][j] = 0;
//             for (int k = 0; k < 3; k++)
//                 mul[i][j] += a[i][k]*b[k][j];
//         }
//     }
 
//     // storing the multiplication result in a[][]
//     for (int i=0; i<3; i++)
//         for (int j=0; j<3; j++)
//             a[i][j] = mul[i][j];  // Updating our matrix
// }
 
// // Function to compute F raise to power n-2.
// int power(int F[3][3], int n)
// {
//     int M[3][3] = {{1,1,1}, {1,0,0}, {0,1,0}};
 
//     // Multiply it with initial values i.e with
//     // F(0) = 0, F(1) = 1, F(2) = 1
//     if (n==1)
//         return F[0][0] + F[0][1];
 
//     power(F, n/2);
 
//     multiply(F, F);
 
//     if (n%2 != 0)
//         multiply(F, M);
 
//     // Multiply it with initial values i.e with
//     // F(0) = 0, F(1) = 1, F(2) = 1
//     return F[0][0] + F[0][1] ;
// }
 
// // Return n'th term of a series defined using below
// // recurrence relation.
// // f(n) is defined as
// //    f(n) = f(n-1) + f(n-2) + f(n-3), n>=3
// // Base Cases :
// //    f(0) = 0, f(1) = 1, f(2) = 1
// int findNthTerm(int n)
// {
 
//     int F[3][3] = {{1,1,1}, {1,0,0}, {0,1,0}} ;
 
//     //Base cases
//     if(n==0)
//         return 0;
//     if(n==1 || n==2)
//         return 1;
 
//     return power(F, n-2);
// }
 
// // Driver code
// int main()
// {
//    int n = 5;
 
//    cout << "F(5) is " << findNthTerm(n);
 
//    return 0;
// }


/*
#define ll long long
//#define mod 1e9+7
const ll mod=1e9+7;
ll ar[3];
ll I[3][3],T[3][3];

void mul(ll A[3][3],ll B[3][3], ll dim){

    ll res[dim+1][dim+1];

    for(ll i=1;i<=dim;i++){
        for(ll j=1;j<=dim;j++){
            res[i][j]=0;
            for(ll k=1;k<=dim;k++){
                ll x=(A[i][k]*B[k][j])%mod;
                res[i][j]+=x;
            }
        }
    }
    
    for(ll i=1;i<=dim;i++){
        for(ll j=1;j<=dim;j++){
            A[i][j]=res[i][j];
        }
    }
}

// ll fibn(ll n){
    
//     if(n<=2)return ar[n];
        
        
//     I[1][1]=I[2][2]=1;
//     I[1][2]=I[2][1]=0;

//     //recursion Matrix
//     T[1][1]=0;
//     T[1][2]=T[2][1]=T[2][2]=1;
    
//     n=n-1;

//     while(n){
//         if(n%2 == 1)
//             mul(I,T,2),n--;
//         else 
//             mul(T,T,2),n/=2;
//     }

//     ll x =(ar[1]*I[1][1] + ar[2]*I[2][1])%mod;
    
//     return x;
// }
void power(ll A[3][3],ll n){
    while(n>0){
        if(n%2==1){
            mul(I,A,2);
            n--;
        }
        else{
            mul(A,A,2);
            n=n/2;
        }
    }
}
ll fibn(ll n){
    if(n<=2)return ar[n];
    
    I[1][1]=I[2][2]=1;
    I[1][2]=I[2][1]=0;
    
    T[1][1] = 0;
    T[1][2] = 1;
    T[2][1] = T[2][2] = 1;
    
    power(T,n-1);
    
    ll x = (ar[1]*I[1][1] + ar[2]*I[2][1])%mod;
    
    return x;
}
int Solution::solve(int A) {
    ar[0]= 0;
    ar[1]= 1;
    ar[2]= 1;
    //cout<<fibn(A)<<endl;
    return fibn(A);
}
*/