/*
 Author: Mrigank
Science is what we understand well enough to explain to a computer, Art is everything else we do - Donald E. Knuth
Problem Link : https://leetcode.com/problems/longest-palindrome-by-concatenating-two-letter-words/
*/


class Solution {
public:
    int longestPalindrome(vector<string>& words) 
    {
        unordered_map < string , int > mp;
        unordered_set < string > st;
        
        for(auto& word : words)
        {
            mp[word]++;
        }
        int ans = 0;
        int maxFreq = 0;
        for(auto word : words)
        {
            if(st.find(word) != st.end()) continue;
            string newWord = word;
            reverse(newWord.begin() , newWord.end());
            if(word == newWord)
            {
                ans += 2 * ((mp[word] % 2 == 0) ? mp[word] : mp[word] - 1);
                if(mp[word] % 2 != 0)
                {
                    maxFreq = max(maxFreq , mp[word]);
                }
                st.insert(word);
            }
            else
            {
                ans += 4 * min(mp[word] , mp[newWord]);
                st.insert(word);
                st.insert(newWord);
            }
        }
        ans += (maxFreq % 2 == 0) ? 0 : 2;
        return ans;
    }
};
