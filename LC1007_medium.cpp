/*
 Author: Mrigank
Science is what we understand well enough to explain to a computer, Art is everything else we do - Donald E. Knuth
Problem Link : https://leetcode.com/problems/minimum-domino-rotations-for-equal-row/
*/


class Solution {
public:
    
    int helper(vector < int >& tops , vector < int >& bottoms , int val)
    {
        int n = tops.size();
        int cntA = 0;
        int cntB = 0;
        for(int i = 0 ; i < n ; i++)
        {
            if(tops[i] != val && bottoms[i] != val) return -1;
            
            if(tops[i] != val) cntA++;
            if(bottoms[i] != val) cntB++;
        }
        return min(cntA , cntB);
    }
    
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) 
    {
        int res1 = helper(tops , bottoms , tops[0]);
        int res2 = helper(tops , bottoms , bottoms[0]);
        
        return min(res1 , res2) > 0 ? min(res1 , res2) : max(res1 , res2);
    }
};
