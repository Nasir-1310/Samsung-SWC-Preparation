#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<climits>
#include<cstring>
using namespace std;
int main(){
    int n,k;
    cin>>n>>k;
    int arr[n];
    memset(arr,0,sizeof(arr));
    while (k--)
    {
        int max_len=0;
        int count=0;
        int last_index=0;
        for(int i=0;i<n;i++){
            if(arr[i]==0){
                count++;
            }
            else{
                count=0;
            }
            if(count>=max_len){
                max_len=count;
                last_index=i;
            }
        }

        int start_index=last_index-max_len+1;
        int mid=(start_index+last_index)/2;
        arr[mid]=1;
        for(int i=0;i<n;i++){
            if(arr[i]==0)
                cout<<"_"<<" ";
                else
                cout<<"X"<<" ";
        }
        cout<<"\n";
    }
    
}