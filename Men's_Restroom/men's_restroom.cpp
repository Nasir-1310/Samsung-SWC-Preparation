/*
    Men's Restroom Problem
    Problem Description
    In a restroom with a certain number of stalls, visitors prefer to maximize their distance from already occupied stalls. The strategy is to occupy the middle of the longest sequence of unoccupied stalls.

    Given the number of stalls, simulate the process of visitors entering the restroom and occupying stalls according to the described strategy.

    Input
    The input consists of a single integer representing the number of stalls.
    Example
    Input
    10
    Output
    _ _ _ _ _ _ _ _ _ _= maxlen=10, lastidx=9, start= 9-10+1=0, mid(0+9)/2=4
    _ _ _ _ X _ _ _ _ _ = maxlen = 5, lastIdx=9, start=9-5+1=5, mid(5+9)/2=7
    _ _ _ _ X _ _ X _ _= maxlen=4, lastIdx=4, start=4-4+1=1, mid(1+4)/2=2 
    _ X _ _ X _ _ X _ _
    _ X _ _ X _ _ X X _
    _ X _ _ X X _ X X _
    _ X X _ X X _ X X _
    _ X X _ X X _ X X X
    _ X X _ X X X X X X
    _ X X X X X X X X X
    X X X X X X X X X X
    Output Format
    Each line represents the stalls' status after each visitor occupies a stall.
    Use _ for unoccupied stalls and X for occupied stalls.*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k; // num of stall and visitors
        cin>>n>>k;
        vector<int> v(n, 0); // 0 means unoccupied, 1 means occupied
        while(k--){
            int mxLen =0, lastIdx, count=0; //mxLen= max length of unoccupied stalls, lastIdx= index to occupy, count= current unoccupied count
            for(int i=0; i<n; i++){
                if(v[i]==0)
                    count++;
                else
                    count =0;

                if(count >=mxLen){
                    mxLen = count;
                    lastIdx = i;
                }
            }
            int s = lastIdx - mxLen +1;//যে ফাঁকা সেগমেন্ট পাওয়া গেল, তার শুরু last 4, maxlen 5 4-5 = -1 +1 =0

            int mid = (lastIdx + s)/2; //মাঝখানের ইন্ডেক্স
            v[mid] =1; // occupy the stall
            for(int i=0; i<n; i++){
                if(v[i]==0) cout<<"_ ";
                else cout<<"X ";
                //cout<<v[i]; //print with 0 or 1 
            }
            cout<<endl;
        }
        return 0; 
    }
}