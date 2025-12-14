#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;


int main() {
       int n,m,k;
        cin>>n>>m>>k;
    map<int,int>mp;
    int val;
    for(int i=0;i<n;i++){
        int number=0;
        int zero_count=0;
        for(int j=0;j<m;j++){
            cin>>val;
                number=number*2+val;
            if(val==0)
                zero_count++;
        }
        if(zero_count<=k && (k-zero_count)%2==0)
            mp[number]++;
            
        
    }
    int ans=0;
    for(auto u:mp){
        ans=max(ans,u.second);
    }
    cout<<ans<<"\n";
    return 0;
}
