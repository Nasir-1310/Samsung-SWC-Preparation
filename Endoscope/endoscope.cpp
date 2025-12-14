#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

struct node{
    int x;
    int y;
    int l;
};
int mat[60][60];
int visited[60][60];
int row,col;

bool is_valid(int x, int y){
    return (x>=0 && x<row && y>=0 && y<col);
}
bool left(int x,int y){
    return (mat[x][y]==1 || mat[x][y]==3 || mat[x][y]==6 || mat[x][y]==7);
}
bool right(int x,int y){
    return (mat[x][y]==1 || mat[x][y]==3 || mat[x][y]==4 || mat[x][y]==5);
}
bool up(int x,int y){
    return (mat[x][y]==1 || mat[x][y]==2 || mat[x][y]==4 || mat[x][y]==7);
}
bool down(int x,int y){
    return (mat[x][y]==1 || mat[x][y]==2 || mat[x][y]==5 || mat[x][y]==6);
}

int find_max_len(int x,int y, int len){
    // if(visited[x][y]!=-1)
    //         return visited[x][y];
    
    queue<node>q;
    q.push({x,y,len});
    visited[x][y]=1;
    int max_len=0;
    while(!q.empty()){
        node curr=q.front();
        q.pop();
        
        if(curr.l==0)
            continue;
        // if(visited[curr.x][curr.y]!=-1)
        //     return visited[curr.x][curr.y];
        max_len++;
        //left
        if(is_valid(curr.x,curr.y-1) && left(curr.x,curr.y) && right(curr.x, curr.y-1) && visited[curr.x][curr.y-1]==-1){
            q.push({curr.x,curr.y-1, curr.l-1});
            visited[curr.x][curr.y-1]=1;
        }
        //right
        if(is_valid(curr.x,curr.y+1) && right(curr.x,curr.y) && left(curr.x, curr.y+1) && visited[curr.x][curr.y+1]==-1){
            q.push({curr.x,curr.y+1, curr.l-1});
            visited[curr.x][curr.y+1]=1;
        }
        //up
        if(is_valid(curr.x-1,curr.y) && up(curr.x,curr.y) && down(curr.x-1, curr.y) && visited[curr.x-1][curr.y]==-1){
            q.push({curr.x-1,curr.y, curr.l-1});
            visited[curr.x-1][curr.y]=1;
        }
        //down
        if(is_valid(curr.x+1,curr.y) && down(curr.x,curr.y) && up(curr.x+1, curr.y) && visited[curr.x+1][curr.y]==-1){
            q.push({curr.x+1,curr.y, curr.l-1});
            visited[curr.x+1][curr.y]=1;
        }
        
        
            
    }
    return max_len;
    
    // return 0;
}

int main() {
   int t;
    cin>>t;
    
    for(int i=0;i<t;i++){
        
        int x,y,l;
        cin>>row>>col>>x>>y>>l;
        for(int j=0;j<row;j++){
            for(int k=0;k<col;k++){
                cin>>mat[j][k];
            }
        }
        memset(visited,-1,sizeof(visited));
        cout<<(mat[x][y]? find_max_len(x,y,l): 0)<<"\n";
        
    }
    return 0;
}
