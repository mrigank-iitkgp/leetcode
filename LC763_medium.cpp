/*
 Author: Mrigank
Science is what we understand well enough to explain to a computer, Art is everything else we do - Donald E. Knuth
Problem Link : https://leetcode.com/problems/partition-labels/
*/


class Solution {
public:
    vector<int> partitionLabels(string s) 
    {
        vector < int > mp(26 , 0);
        int n = s.length();
        for(int i = 0 ; i < n ; i++)
        {
            mp[s[i] - 'a'] = i;
        }
        int idx = 0;
        int start = idx;
        int end;
        vector < int > ans;
        while(idx < n)
        {
            end = mp[s[idx] - 'a'];
            while(idx < end)
            {
                end = max(mp[s[idx++] - 'a'] , end);
            }
            ans.push_back(end - start + 1);
            idx++;
            start = idx;
        }
        return ans;
    }
};
