#include<bits/stdc++.h>
using namespace std;

int main() {
    string str1,str2;
    cin>>str1>>str2;
    int n=str1.length();
    int m=str2.length();
    while(1){
        size_t found=str1.find(str2);
        if( found != string::npos){
            str1.erase(found,m);
        }
        else{
            break;
        }
    }
    //cout<<str1<<endl;
    cout<<str1.length()<<endl;    

    return 0;   
}