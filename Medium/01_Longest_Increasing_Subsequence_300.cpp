/*
300. Longest Increasing Subsequence
---------------------------------------------
Given an integer array nums, return the length of the longest strictly increasing subsequence.

 

Example 1:

Input: nums = [10,9,2,5,3,7,101,18]
Output: 4
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.
Example 2:

Input: nums = [0,1,0,3,2,3]
Output: 4
Example 3:

Input: nums = [7,7,7,7,7,7,7]
Output: 1
 

Constraints:

1 <= nums.length <= 2500
-104 <= nums[i] <= 104
*/


/*
Concept:

1. Create a dp array:
    - dp[i] means the length of the longest increasing subsequence ending at index i.
    - Initially, every dp[i] = 1, because any single number is a valid subsequence by itself.
2. Compare every element with previous ones:
    - For each element at position i, you look at all the elements before it (from 0 to i-1).
    - If nums[j] < nums[i], it means you can add nums[i] after nums[j] to form a longer increasing      subsequence.
    - So, you update dp[i] = max(dp[i], dp[j] + 1)
3. Find the maximum in the dp array:
    - The answer is the largest value in dp, because that represents the longest increasing subsequence in the whole array.
*/

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n, 1);
        for(int i=1; i<n; i++){
            for(int j=0; j<i; j++){
                if(nums[j]<nums[i]) dp[i]=max(dp[i], dp[j]+1);
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};