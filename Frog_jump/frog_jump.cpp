#include<iostream>
#include<queue>
#include<climits>
#include<cstring>
using namespace std;

int n;
int mat[20][20];
int visited[20][20];
pair<int,int>source,des;
struct node{
    int x;
    int y;
    int cost;
};
bool is_valid(int x,int y){
    return(x>=0 && x<n && y>=0 && y<n);
}
int find_min_step(int x,int y){
    queue<node>q;
    q.push({x,y,0});
    visited[x][y]=1;
    
    
    while(!q.empty()){
        node curr=q.front();
        q.pop();
        if(curr.x==des.first && curr.y==des.second)
            {
                return curr.cost;
            }
        
        if(mat[curr.x][curr.y]==1){
            //left
            if(is_valid(curr.x,curr.y-1) && visited[curr.x][curr.y-1]==-1 && mat[curr.x][curr.y-1]==1){
                q.push({curr.x,curr.y-1,curr.cost});
                visited[curr.x][curr.y-1]=1;
            }
             //right
            if(is_valid(curr.x,curr.y+1) && visited[curr.x][curr.y+1]==-1 && mat[curr.x][curr.y+1]==1){
                q.push({curr.x,curr.y+1,curr.cost});
                visited[curr.x][curr.y+1]=1;
            }
             //up
            if(is_valid(curr.x-1,curr.y) && visited[curr.x-1][curr.y]==-1 ){
                q.push({curr.x-1,curr.y,curr.cost+1});
                visited[curr.x-1][curr.y]=1;
            }
             //down
            if(is_valid(curr.x+1,curr.y) && visited[curr.x+1][curr.y]==-1){
                q.push({curr.x+1,curr.y,curr.cost+1});
                visited[curr.x+1][curr.y]=1;
            }
        }
        else{
             //up
            if(is_valid(curr.x-1,curr.y) && visited[curr.x-1][curr.y]==-1){
                q.push({curr.x-1,curr.y,curr.cost});
                visited[curr.x-1][curr.y]=1;
            }
             //down
            if(is_valid(curr.x+1,curr.y) && visited[curr.x+1][curr.y]==-1){
                q.push({curr.x+1,curr.y,curr.cost});
                visited[curr.x+1][curr.y]=1;
            }
            
        }
    }
    return -1;
}

int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int val;
            cin>>val;
            mat[i][j]=val;
        }
    }
    cin>>source.first>>source.second>>des.first>>des.second;
    
    memset(visited,-1,sizeof(visited));
    
    int ans=find_min_step(source.first,source.second);
    cout<<ans;
    
}

