#include <iostream>
#include<cmath>
#include<algorithm>
#include <climits>
#include<cmath>
using namespace std;


//SOLUTION 1 (optimal) 
int main(){ 
    int n,k;
    cin>>n>>k;
    int a[n];
    for(int i=0; i<n; i++){
        cin>>a[i];
    }

    if(k<0 || k>n){
        cout<<-1;
        return 0;
    }

    sort(a, a+n);//ascending order
    // for(auto i:a){
    //     cout<<i<<" ";
    // }
    long long int stones = 1ll * n* a[k-1];
    cout<<stones<<endl;
}


/*
// SOLUTION 2
int main(){
    int n,k;
    cin>>n>>k; // num of pot , k= num of por overflow
    int a[n];
    for(int i=0; i<n; i++){
        cin>>a[i];
    }

    if(k<0 || k>n){
        cout<<-1;
        return 0;
    }
    sort(a, a+n, greater<int>()); // descending order
    int stones =0;
    int d= n-1;
    while(k--){
        for(int i=0; i<n; i++){
        stones += a[d];
        a[i]-=a[d];
    }
    d--;
    }
    cout<<stones<<endl;
}
*/