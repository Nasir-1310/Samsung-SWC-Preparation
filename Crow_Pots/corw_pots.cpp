/*
https://www.careercup.com/question?id=5166688897073152
http://forums.codeguru.com/showthread.php?560529-Core-Java-programming
https://codereview.stackexchange.com/questions/136165/the-thirsty-crow
*/

/*
There are N pots. Every pots has some water in it. They may be partially filled. 
Every pot is associated with overflow number O which tell how many minimum no. of stones required 
for that pot to overflow. The crow know O1 to On(overflow no. for all the pots). Crow wants some K 
pots to be overflow. So the task is minimum number of stones he can make K pots overflow in worst case.

Array of overflow no--. {1,...,On}
Number of pots--n
No of pots to overflow-- k

Let say two pots are there with overflow no.s {5,58}, and crow has to overflow one pot(k=1). 
So crow will put 5 stones in pot with overflow no.(58), it will not overflow, then he will put in 
pot with overflow no.(5), hence the total no. of stones to make overflow one pot is=10.
*/



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