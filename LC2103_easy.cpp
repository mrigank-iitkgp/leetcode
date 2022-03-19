/*
 Author: Mrigank
Science is what we understand well enough to explain to a computer, Art is everything else we do - Donald E. Knuth
Problem Link : https://leetcode.com/problems/rings-and-rods/
*/


class Solution {
public:
    int countPoints(string rings) 
    {
        unordered_map < int , unordered_set < char > > mp;
        
        int n = rings.length();
        for(int i = 0 ; i + 1 < n ; i += 2)
        {
            char c = rings[i];
            int rod = rings[i + 1] - '0';
            
            mp[rod].insert(c);
        }
        int ans = 0;
        for(auto& x : mp)
        {
            if(x.second.find('R') != x.second.end() && x.second.find('G') != x.second.end() && x.second.find('B') != x.second.end()) ans++;
        }
        return ans;
    }
};
