#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<climits>
#include<iomanip>
using namespace std;

int n,m,tm;
vector<vector<pair<int,double>>>adj;
vector<double>curr(100,0.0);

void calculate_next_move(){

    int steps = tm/10;

    for(int step=0; step<steps; step++){

        vector<double>updated_porb(n+1,0.0);

        for(int u=1; u<=n; u++){

            if(curr[u]>0.0){

                for(auto v:adj[u]){

                    int node = v.first;
                    double prob = v.second;
                    updated_porb[node]+=curr[u]*prob;//1(0.3)->2(0.2
                }
            }
        }
        curr= updated_porb;
    }
}
int main(){
    int t;
    cin>>t;
    while(t--){

        cin>>n>>m>>tm;
        for(int i=0;i<n;i++){
            int u,v;
            double p;
            cin>>u>>v>>p;
            adj[u].push_back({v,p});
        }
        curr[1]=1.0;
        calculate_next_move();

        int des_node=1;
        double des_prob= curr[1];
        for(int j=2;j<=n;j++){
            if(curr[j]>des_prob){
                des_prob= curr[j];
                des_node=j;
            }
        }
        cout<<des_node<<fixed<<setprecision(6)<<" "<<des_prob<<"\n";

    }
    
}

/*
Input Format
2
6 10 40
1 2 0.3
1 3 0.7
3 3 0.2
3 4 0.8
2 4 1
4 5 0.9
4 4 0.1
5 6 1.0
6 3 0.5
6 6 0.5

6 10 10
1 2 0.3
1 3 0.7
3 3 0.2
3 4 0.8
2 4 1
4 5 0.9
4 4 0.1
5 6 1.0
6 3 0.5
6 6 0.5

Output Format
6 0.774000
3 0.700000
*/