/*
 Author: Mrigank
Science is what we understand well enough to explain to a computer, Art is everything else we do - Donald E. Knuth
Problem Link : https://leetcode.com/problems/divide-array-into-equal-pairs/
*/

class Solution {
public:
    bool divideArray(vector<int>& nums) 
    {
        unordered_map < int , int > mp;
        for(auto num : nums)
        {
            mp[num]++;
        }
        bool ans = true;
        
        for(auto& x : mp)
        {
            if(x.second % 2 != 0)
            {
                return false;
            }
        }
        return ans;
    }
};

