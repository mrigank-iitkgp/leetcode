/*
 Author: Mrigank
Science is what we understand well enough to explain to a computer, Art is everything else we do - Donald E. Knuth
Problem Link : https://leetcode.com/problems/maximum-points-in-an-archery-competition/
*/



class Solution {
public:
    vector < vector < int > > ans;
    void helper(int numArrows , vector < int >& aliceArrows , vector < int >& bobArrows , int curr)
    {
        if(curr >= aliceArrows.size())
        {
            ans.push_back(bobArrows);
            return;
        }
        if(numArrows >= aliceArrows[curr] + 1)
        {
            bobArrows[curr] = aliceArrows[curr] + 1;
            helper(numArrows - bobArrows[curr] , aliceArrows , bobArrows , curr + 1);
            bobArrows[curr] = 0;
            helper(numArrows , aliceArrows , bobArrows , curr + 1);
        }
        else
        {
            helper(numArrows , aliceArrows , bobArrows , curr + 1);
        }
    }
    vector<int> maximumBobPoints(int numArrows, vector<int>& aliceArrows) 
    {
        ans.clear();
        int n = aliceArrows.size();
        vector < int > bobArrows(n , 0);
        helper(numArrows , aliceArrows , bobArrows , 0);
        int maxScore = 0;
        vector < int > res;
        for(auto x : ans)
        {
            int score = 0;
            for(int i = 0 ; i < n ; i++)
            {
                if(x[i] > aliceArrows[i]) score += i;
            }
            if(score > maxScore)
            {
                maxScore = score;
                res = x;
            }
        }
        int sum = accumulate(res.begin() , res.end() , 0);
        //cout << sum << endl;
        res[0] += (numArrows - sum > 0) ? numArrows - sum : 0;
        return res;
    }
};
