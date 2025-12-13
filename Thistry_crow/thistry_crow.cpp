/* 
https://codereview.stackexchange.com/questions/136165/the-thirsty-crow

There are N pots. Every pot has some water in it. They may be partially
filled. So there is a Overflow Number O associated with every pot which tell how many minimum stone pieces are require for that pot to overflow. So if for a pot O-value is 5 it means minimum 5 stone pieces should be put in that pot to make it overflow.

Initially a crow watched those pots and by seeing the water level he anticipated O-value correctly for every pot (that is he knew O1 to On). But when he came back in evening he found that every pot is painted from outside and he is not able to know which pot has what O-value. The Crow wants some K pots to overflow so that he can serve his child appropriately. For overflowing the pots he needs to search for the stones in forest (assume that every stone has same size).

He wants to use minimum number of stones to overflow the K pots. But he doesn't know now which pot has what O-value. So the task is to find out the minimum number of stones that the crow requires to make the K pots overflow in the worst case.

Input Specification:

A array O corresponding to O-value of N pots {O1, O2, ....... , On}
Number of pots
K -value ( number of pots which the crow wants to overflow)
Output Specification:

Minimum number of stones required to make K pots overflow in worst case or -1 if input is invalid.

Example:

Let's say there are two pots:

Pot 1 has O value of 5 , O1= 5
Pot 2 has O value of 58, O2= 58
Let's say the crow wants to make one of the pots overflow. If he knows which pot has what O-value he would simply search for 5 stones and put them in pot 1 to make it overflow. But in a real case he doesn't know which pot has what O-value so just 5 stones may not always work. However he does know that one pot has O-value 5 and other has 58. So even in the worst case he can make one of the pot overflow just by using 10 stones. He would put 5 stones in one pot if it doesn't overflow he would try the remaining 5 in the other pot which would definitely overflow because one of the pot has O-value of 5. So the answer for above question is minimum 10 stones even in worst case.
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