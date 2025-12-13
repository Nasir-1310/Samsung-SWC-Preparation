/*
https://www.careercup.com/question?id=5740719907012608
https://stackoverflow.com/questions/39673898/divide-array-into-k-contiguos-partitions-such-that-sum-of-maximum-partition-is-m/39675396
http://ideone.com/r60yH4 - Sameer Code
https://www.careercup.com/question?id=5730470801702912
*/

/*
There is an island surrounded by oil mines. You will be given n companies and m oil mines having values.
You have to distribute the mines to "n" companies in fair manner. Remember the companies can have oil 
mines adjacent to each other and not in between of each others.After distributing them compute the 
difference of oil mines from the company getting highest and company getting lowest. This number 
should be minimum.(then only the distribution can be termed as fair).

Input 
2 
2 4 
6 13 10 2
2 4 
6 10 13 2 

output 
5 
1
*/

#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
#include <algorithm>
using namespace std;

// c= number of companies,
// n= number of oil mines, ans= minimum difference
int c, n, ans;
int oilMine[20]; // oil mine values
bool vis[20]; // tracking which mines are used

void back(int i, int sum, int companies, int mini, int maxi){
    if(vis[i]){
        if(companies == c){
            int newMin = min(sum, mini);
            int newMax = max(sum, maxi);
            ans = min(ans, newMax - newMin);
        }
        return;
    }

    int j = (i+1)%n; // next index in circular manner
    vis[i] = true;

    // add this mine to the same company
    back(j, sum + oilMine[i], companies, mini, maxi);

    int newMin = min(sum, mini);
    int newmax = max(sum, maxi);
    // add this mine to a new company
    back(j, oilMine[i], companies + 1, newMin, newmax);

    vis[i] = false;

}

int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>c>>n;
        for(int i=0; i<n; i++){
            cin>> oilMine[i];
            vis[i]=false;
        }
        if(c>n) {
            ans=-1;
          cout<<ans<<endl;
            continue;
        }
           
        ans = INT_MAX;
        for(int i=0; i<n; i++){
            back(i, 0, 1, INT_MAX, INT_MIN);
            //index, sum, companies, min, max
        }
        cout<<ans<<endl;
        
    }
    return 0;
}