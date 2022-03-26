/*
 Author: Mrigank
Science is what we understand well enough to explain to a computer, Art is everything else we do - Donald E. Knuth
Problem Link : https://leetcode.com/problems/capitalize-the-title/
*/


class Solution {
public:
    string capitalizeTitle(string title) 
    {
        string ans;
        
        stringstream ss(title);
        string word;
        
        while(ss >> word)
        {
            if(word.length() <= 2)
            {
                for(auto& x : word)
                {
                    x = tolower(x);
                }
            }
            else
            {
                word[0] = toupper(word[0]);
                for(int i = 1 ; i < word.length() ; i++)
                {
                    word[i] = tolower(word[i]);
                }
            }
            ans += word;
            ans += " ";
        }
        ans.pop_back();
        return ans;
    }
};
