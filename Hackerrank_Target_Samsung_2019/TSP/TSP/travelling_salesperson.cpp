#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int ans;
int arr[20][20];
int n;
int visited[20];
int func_call=0;

void backtrack(int k, int count, int sum){
    func_call++;
    if(count==n-1)
    {
        sum+=arr[k][0];
        ans=min(ans, sum);
        return;
    }
    
    if(sum>=ans)
        return;
    for(int i=1;i<n;i++){
        if(visited[i]==0){
            visited[i]=1;
            backtrack(i,count+1,sum+arr[k][i]);
            visited[i]=0;
        }
    }
}



int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=0;i<n;i++){
            visited[i]=0;
            for(int j=0;j<n;j++)
            {
                cin>>arr[i][j];
            }
        }
        
        ans=1e9;
        backtrack(0,0,0);//(start(0), traversal_count(0), total_cost(0))
        cout<<ans<<endl;
        cout<<func_call<<endl;
    }
    
    return 0;
}
