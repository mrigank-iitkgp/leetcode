/*
 Author: Mrigank
Science is what we understand well enough to explain to a computer, Art is everything else we do - Donald E. Knuth
Problem Link : https://leetcode.com/problems/broken-calculator/
*/


class Solution {
public:
    int brokenCalc(int startValue, int target) 
    {
        int ans = 0;
        while(target > startValue)
        {
            ans++;
            if(target % 2 == 0) target = target / 2;
            else target++;
        }
        return ans + (startValue - target);
    }
};
