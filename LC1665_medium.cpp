/*
 Author: Mrigank
Science is what we understand well enough to explain to a computer, Art is everything else we do - Donald E. Knuth
Problem Link : https://leetcode.com/problems/ways-to-make-a-fair-array/
*/


class Solution {
public:
    int waysToMakeFair(vector<int>& nums) 
    {
        int n = nums.size();
        vector < int > even(n + 1 , 0);
        vector < int > odd(n + 1 , 0);
        int evenSum = 0 , oddSum = 0 , ans = 0;
        
        for(int i = n - 1 ; i >= 0 ; i--)
        {
            if(i % 2 == 0)
            {
                even[i] += nums[i];
            }
            else
            {
                odd[i] += nums[i];
            }
            odd[i] += odd[i + 1];
            even[i] += even[i + 1];
        }
        
        for(int i = 0 ; i < n ; i++)
        {
            if(evenSum + odd[i + 1] == oddSum + even[i + 1]) ans++;
            
            if(i % 2 == 0) evenSum += nums[i];
            else oddSum += nums[i];
        }
        return ans;
    }
};
