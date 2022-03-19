/*
 Author: Mrigank
Science is what we understand well enough to explain to a computer, Art is everything else we do - Donald E. Knuth
Problem Link : https://leetcode.com/problems/minimum-white-tiles-after-covering-with-carpets/
*/


class Solution {
public:
    vector < vector < int > > dp;
    int helper(string& floor , int numCarpets , int carpetLen , int curr)
    {
        if(curr >= floor.length()) return 0;
        if(dp[curr][numCarpets] != -1) return dp[curr][numCarpets];
        
        if(floor[curr] == '0') return dp[curr][numCarpets] = helper(floor , numCarpets , carpetLen , curr + 1);
        else
        {
            int ans = INT_MAX;
            ans = 1 + helper(floor , numCarpets , carpetLen , curr + 1);
            if(numCarpets > 0) ans = min(ans , helper(floor , numCarpets - 1 , carpetLen , curr + carpetLen));
            return dp[curr][numCarpets] = ans;
        }
        
    }
    int minimumWhiteTiles(string floor, int numCarpets, int carpetLen) 
    {
        int sz = floor.length();
        dp.resize(sz , vector < int > (numCarpets + 1 , -1));
        return helper(floor , numCarpets , carpetLen , 0);
    }
};

