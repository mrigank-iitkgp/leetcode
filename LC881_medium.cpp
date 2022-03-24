/*
 Author: Mrigank
Science is what we understand well enough to explain to a computer, Art is everything else we do - Donald E. Knuth
Problem Link : https://leetcode.com/problems/boats-to-save-people/
*/


class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) 
    {
        sort(people.begin() , people.end());
        int ans = 0;
        int n = people.size();
        int l = 0 , r = n - 1;
        while(l < r)
        {
            if(people[l] + people[r] <= limit)
            {
                ans++;
                l++;
                r--;
            }
            else
            {
                ans++;
                r--;
            }
        }
        if(l == r) ans++;
        return ans;
    }
};
