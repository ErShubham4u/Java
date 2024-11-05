#include <bits/stdc++.h>
 using namespace std;
 int knapsack(int W, vector<int>& wt, vector<int>& val, int n) {
 vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));
 for (int i = 1; i <= n; i++) {
 for (int w = 0; w <= W; w++) {
 if (wt[i-1] <= w) {
 dp[i][w] = max(val[i-1] + dp[i-1][w- wt[i-1]], dp[i-1][w]);
 } else {
 dp[i][w] = dp[i-1][w];
 }
 }
 }
 return dp[n][W];
 }
 int main() {
 int n; // number of items
 cout << "Enter the number of items: ";
 cin >> n;
 vector<int> val(n); // values of items
 vector<int> wt(n); // weights of items
 cout << "Enter the values of the items:\n";
 for (int i = 0; i < n; i++) {
 cin >> val[i];
 }
 cout << "Enter the weights of the items:\n";
 for (int i = 0; i < n; i++) {
 cin >> wt[i];
 }
 int W; // knapsack capacity
 cout << "Enter the knapsack capacity: ";
 cin >> W;
 cout << "Maximum value: " << knapsack(W, wt, val, n) << endl;
 return 0;
 }