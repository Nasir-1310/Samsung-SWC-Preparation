/*
https://www.geeksforgeeks.org/samsung-interview-experience-set-39-campus-r-d-noida/
https://www.careercup.com/page?pid=samsung-interview-questions

A Doctor travels from a division to other division where divisions are connected like a graph(directed graph) and 
the edge weights are the probabilities of the doctor going from that division to other connected division but the 
doctor stays 10mins at each division now there will be given time and had to find the division in which he will be 
staying by that time and is determined by finding division which has high probability.

Input is number of test cases followed by the number of nodes, edges, time after which we need to find the division 
in which he will be there, the edges starting point, end point, probability.

Note: If he reaches a point where there are no further nodes then he leaves the lab after 10 mins and the traveling 
time is not considered and during that 10min at 10th min he will be in next division, so be careful

Sample Input
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

Sample Output
6 0.774000
3 0.700000
*/

#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<climits>
#include<iomanip>
using namespace std;

int n, m, time_limit;
vector<vector<pair<int, double>>> adj;
vector<double> curr;

void calculate_next_move() {
    int steps = time_limit / 10;

    for(int step = 0; step < steps; step++) {
        vector<double> updated_prob(n + 1, 0.0);

        for(int u = 1; u <= n; u++) {
            if(curr[u] > 0.0) {
                // If node has no outgoing edges, probability disappears (doctor leaves)
                if(adj[u].empty()) {
                    continue;
                }
                
                for(auto v : adj[u]) {
                    int node = v.first;
                    double prob = v.second;
                    updated_prob[node] += curr[u] * prob;
                }
            }
        }
        curr = updated_prob;
    }
}

int main() {
    int t;
    cin >> t;
    
    while(t--) {
        cin >> n >> m >> time_limit;
        
        // Clear and resize for each test case
        adj.clear();
        adj.resize(n + 1);
        curr.assign(n + 1, 0.0);
        
        for(int i = 0; i < m; i++) {
            int u, v;
            double p;
            cin >> u >> v >> p;
            adj[u].push_back({v, p});
        }
        
        curr[1] = 1.0;  // Doctor starts at node 1
        calculate_next_move();

        int des_node = 1;
        double des_prob = curr[1];
        
        for(int j = 2; j <= n; j++) {
            if(curr[j] > des_prob) {
                des_prob = curr[j];
                des_node = j;
            }
        }
        
        cout << des_node << " " << fixed << setprecision(6) << des_prob << "\n";
    }
    
    return 0;
}

/*


```

## এই code এ যা যা ঠিক আছে:

✅ **Variable name conflict fix**: `tm` → `time_limit`  
✅ **Vector initialization**: প্রতিটা test case এ `adj` এবং `curr` clear/resize হচ্ছে  
✅ **Dead-end handling**: Node এ outgoing edge না থাকলে probability হারিয়ে যায়  
✅ **Probability calculation**: সঠিকভাবে previous node থেকে next node এ probability transfer হচ্ছে  
✅ **Output format**: Node number এবং probability ঠিকভাবে print হচ্ছে  

## Expected Output:
```
6 0.774000
3 0.700000

*/