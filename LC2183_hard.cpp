/*
 Author: Mrigank
Science is what we understand well enough to explain to a computer, Art is everything else we do - Donald E. Knuth
Problem Link : https://leetcode.com/problems/count-array-pairs-divisible-by-k/
*/


class Solution {
public:
    typedef long long int ll;
    long long countPairs(vector<int>& nums, int k) 
    {
        ll ans = 0;
        unordered_map < ll , ll > mp;
        
        for(auto num : nums)
        {
            ll gcd1 = __gcd(num , k);
            for(auto& x : mp)
            {
                if((x.first * gcd1) % k == 0)
                    ans += x.second;
            }
            mp[gcd1]++;
        }
        return ans;
    }
};
