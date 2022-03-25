/*
 Author: Mrigank
Science is what we understand well enough to explain to a computer, Art is everything else we do - Donald E. Knuth
Problem Link : https://leetcode.com/problems/two-city-scheduling/
*/



class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) 
    {
        sort(costs.begin() , costs.end() , [&](const vector < int >& a , const vector < int >& b )
             {
                 return a[0] - a[1] < b[0] - b[1];
             }
            );
        int ans = 0;
        int n = costs.size();
        for(int i = 0 ; i < n / 2 ; i++)
        {
            ans += costs[i][0];
            ans += costs[i + (n / 2)][1];
        }
        return ans;
    }
};
