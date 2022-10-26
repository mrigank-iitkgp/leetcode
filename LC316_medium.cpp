#include <bits/stdc++.h>
/*
 Author: Mrigank
Science is what we understand well enough to explain to a computer, Art is everything else we do - Donald E. Knuth
Problem Link : https://leetcode.com/problems/remove-duplicate-letters/
*/


class Solution {
public:
    string removeDuplicateLetters(string s) 
    {
        vector < char > mp(26 , 0);
        vector < bool > visited(26 , false);
        
        for(auto x : s)
        {
            mp[x - 'a']++;
        }
        
        stack < char > st;
        
        for(auto x : s)
        {
            mp[x - 'a']--;
            if(visited[x - 'a']) continue;
            while(!st.empty() && st.top() > x && mp[st.top() - 'a'] != 0)
            {
                visited[st.top() - 'a'] = false;
                st.pop();
            }
            st.push(x);
            visited[x - 'a'] = true;
        }
        string ans;
        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin() , ans.end());
        return ans;
    }
};
