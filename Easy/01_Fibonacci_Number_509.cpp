/*
*** 509. Fibonacci Number ***
---------------------------------
The Fibonacci numbers, commonly denoted F(n) form a sequence, called the Fibonacci sequence, such that each number is the sum of the two preceding ones, starting from 0 and 1. That is,

F(0) = 0, F(1) = 1
F(n) = F(n - 1) + F(n - 2), for n > 1.
Given n, calculate F(n).

Example 1:

Input: n = 2
Output: 1
Explanation: F(2) = F(1) + F(0) = 1 + 0 = 1.
Example 2:

Input: n = 3
Output: 2
Explanation: F(3) = F(2) + F(1) = 1 + 1 = 2.
Example 3:

Input: n = 4
Output: 3
Explanation: F(4) = F(3) + F(2) = 2 + 1 = 3.
 

Constraints: 0 <= n <= 30
*/

// Memoization (Top-down) [O(n), O(n)]
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int helper(int n, vector<int> &dp){
        if(n<=1) return n;
        if(dp[n]!=-1) return dp[n];
        dp[n]=fib(n-1)+fib(n-2);
        return dp[n];
    }
    int fib(int n) {
        vector<int> dp(n+1, -1);
        return helper(n, dp);
    }
};

//Tabulation (Bottom-up) [O(n), O(n)]
class Solution {
public:
    int fib(int n) {
        if (n <= 1) return n;
        vector<int> dp(n + 1);
        dp[0] = 0;
        dp[1] = 1;

        for (int i = 2; i <= n; ++i)
            dp[i] = dp[i - 1] + dp[i - 2];

        return dp[n];
    }
};

//Space Optimized (Iterative) [O(n), O(1)]
class Solution {
public:
    int fib(int n) {
        if (n <= 1) return n;
        int a = 0, b = 1;
        for (int i = 2; i <= n; ++i) {
            int c = a + b;
            a = b;
            b = c;
        }
        return b;
    }
};
