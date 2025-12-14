#include <iostream>
#include<climits>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;

int n,m;
int mat[20][20];
int visited[20][20];
pair<int,int>source,des;


bool canReach(int maxHeight){
    
    memset(visited,-1,sizeof(visited));
    queue<pair<int,int>>q;
    q.push({source.first,source.second});
    visited[source.first][source.second]=1;
    
    while(!q.empty()){
        auto [x,y] =q.front();
        q.pop();
        if(x==des.first && y==des.second)
            return true;
        
        //horizontal move
        for(int dy=-1;dy<=1;dy+=2){
            int ny=y+dy;
            while(ny>=0 && ny<m && visited[x][ny]==-1 && mat[x][ny]!=0){
                q.push({x,ny});
                visited[x][ny]=1;
                ny+=dy;
            }
        }
        //vertical move
        for(int dx=0;dx<n;dx++){
            if(abs(x-dx)<=maxHeight && visited[dx][y]==-1 && (mat[dx][y]==1 || mat[dx][y]==3)){
                q.push({dx,y});
                visited[dx][y]=1;
            }
        }
    }
    return false;
}



int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>mat[i][j];
            if(mat[i][j]==3)
                des={i,j};
        }
    }
    
    source={n-1,0};
    
    int low=0,high=n-1,ans=n-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(canReach(mid)){
            ans=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    
    cout<<ans<<"\n";
    
}