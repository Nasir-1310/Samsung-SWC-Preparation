/*
Problem Description
A company sells products, each identified by a unique serial number. Some serial numbers are considered "ominous" if they contain a specific digit or pattern that affects the product's sales. You need to determine which products are likely to sell based on their serial numbers.

A product is considered to not sell if its serial number contains at most k occurrences of a specified ominous digit or pattern. You need to count how many products in a given range do not contain the ominous digit or pattern more than k times.
*/

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a, b, k;
    cin >> a >> b >> k;
    int n;
    cin >> n;
    int ar[n];
    for (int i = 0; i < n; i++)
        cin >> ar[i];
    int ans = 0;
    for (int i = a; i <= b; i++)
    {
        int nm = i;
        int frq[10] = {0};
        while (nm)
        {
            int dig = nm % 10;
            frq[dig]++;
            nm /= 10;
        }
        int cnt = 0;
        for (int j = 0; j < n; j++)
            cnt += frq[ar[j]];
        if (cnt < k)
            ans++;
        else
            cout << i << endl;
    }
    cout << ans << endl;
    return 0;
}