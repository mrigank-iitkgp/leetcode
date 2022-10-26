#include<bits/stdc++.h>
/*
Problem Link : https://leetcode.com/problems/number-of-subarrays-with-gcd-equal-to-k/

*/

class Solution {
public:
    int subarrayGCD(vector<int>& nums, int k) {
        int ans = 0;
        int n = nums.size();
        for(int i = 0 ; i < n ; i++) {
            int gcd = nums[i];
            for(int j = i ; j < n ; j++) {
                if(gcd < k) break;
                gcd = __gcd(gcd , nums[j]);
                if(gcd == k) ans++;
            }
        }
        return ans;
    }
};
