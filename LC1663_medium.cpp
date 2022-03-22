/*
 Author: Mrigank
Science is what we understand well enough to explain to a computer, Art is everything else we do - Donald E. Knuth
Problem Link : https://leetcode.com/problems/smallest-string-with-a-given-numeric-value/
*/


class Solution {
public:
    string getSmallestString(int n, int k) 
    {
        string ans;
        if(n == 0 || k == 0) return ans;
        
        for(int i = 0 ; i < n ; i++) ans.push_back('a');
        k = k - n;
        
        for(int i = n - 1 ; i >= 0 ; i--)
        {
            if(k <= 0) break;
            else if(k >= 25)
            {
                ans[i] += 25;
                k = k - 25;
            }
            else
            {
                ans[i] += k;
                k = 0;
            }
        }
        return ans;
    }
};
