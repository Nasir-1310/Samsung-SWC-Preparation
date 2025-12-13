/*
https://www.geeksforgeeks.org/samsung-r-d-noida-question-september-2018

** You can run your code here:
https://leetcode.com/problems/tallest-billboard/


Maximum Pole Problem
Problem Description
You need to place an electronic banner on top of two pillars of equal height to maximize visibility across the city. You are given an array of integers representing possible pillar heights. Your task is to choose two pillars of the same height from this array to maximize the combined height of the two pillars.

If no two pillars of equal height can be found, return 0.
Input
The first line contains the number of test cases.
For each test case:
The first line contains an integer N, the number of possible pillar heights.
The second line contains N integers representing the heights of the pillars.
Example
Input
1
5
1 2 3 4 6
Output
8


--------------------
The question was like this... You have to place an electronic banner of a company as high as it can be, so that whole the city can view the banner standing on top of TWO PILLERS. 
The height of two pillers are to be chosen from given array.. say [1, 2, 3, 4, 6]. We have to maximise the height of the two pillars standing side by side, so that 
the pillars are of EQUAL HEIGHT and banner can be placed on top of it. In the above array, (1, 2, 3, 4, 6) we can choose pillars like this, say two pillars as p1 and p2.. 
Then pillars can be, p1 = 3 unit... Choosing element (3) from array, Similarly p2 = 3 choosing (2 + 1) from array. Since, two pillars are equal, we can put board on it...
 But we have two maximise the height of the pillars, And if we check for other heights, we can see p1 = 6 p2 = 4 + 2 which is greater than 3 ( the previous height).. 
 We have to see if we can further maximize the height... Yes it can be 8. I.e. p1 = 6 + 2 = 8. p2 = 4 + 3 + 1 = 8. Both pillars are equal and banner can be placed...
  And since this is the maximum height attainable for two pillars, we print the answer as 8. In case, there is no combination possible, print 0 (zero). 
  INPUT : 1 5 1 2 3 4 6 First line is  T  number of test cases to be followed. Second line of input is number of different pillars. Third line of input is  
  different available heights of pillars. Note : heights of given pillars can be same .. I.e. array can have same elements repeated. Output. 8 
  Simply print the maximum height attainable so that board/ banner can be placed. In case there is no possible combination for placing banner with equal weighted pillars, 
  then print 0. Constraint's : some general constraints were given*/

#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;

int n; // number of poles
vector<int> a; // heights of the poles
int ans; // max height

void solve(int index, int p1, int p2){
    if(index == n){ // index == n means all poles are considered
        if(p1 == p2)
            ans = max(ans, p1);
        return;
    }

    // Option 1: Add current pole to pillar 1
    solve(index +1, p1 + a[index], p2);
    // Option 2: Add current pole to pillar 2
    solve(index+1, p1, p2 + a[index]);
    // Option 3: Do not use current pole
    solve(index + 1, p1, p2);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin>>t;
    while(t--){
        cin>>n; // num of poles
        a.assign(n,0); //size n and all element 0
        for(int i=0; i<n; i++) cin>>a[i];
        ans = 0;
        solve(0, 0, 0); // index, p1(pillar 1), p2(pillar 2)
        cout<<ans<<"\n"; 
    }
    return 0;
}