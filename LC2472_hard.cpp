/*
  Author: Mrigank
 Science is what we understand well enough to explain to a computer, Art is everything else we do - Donald E. Knuth
 Problem Link : https://leetcode.com/problems/maximum-number-of-non-overlapping-palindrome-substrings
 */
 
 
class Solution {
public:
    bool dp[2005][2005];
    int memo[2005];
    void palindromeTable(string& s , int n) {
        for(int i = 0 ; i < n ; i++) {
            dp[i][i] = true;
        }
        for(int i = 0 ; i + 1 < n ; i++) {
            if(s[i] == s[i + 1]) {
                dp[i][i + 1] = true;
            }
        }
        for(int len = 3 ; len <= n ; len++) {
            for(int i = 0 ; i + len <= n ; i++) {
                int j = i + len - 1;
                if(s[i] == s[j] && dp[i + 1][j - 1]) {
                    dp[i][j] = true;
                }
            }
        }
    }
    int helper(string& s , int pos , int k , int n) {
        if(pos >= n) return 0;
        if(memo[pos] != -1) return memo[pos];
        int exclude = helper(s , pos + 1 , k , n);
        int include = INT_MIN;
        for(int j = pos + k - 1 ; j < s.length() ; j++) {
            if(dp[pos][j]) {
                include = max(include , 1 + helper(s , j + 1 , k , n));
            }
        }
        return memo[pos] = max(include , exclude);
    }
    int maxPalindromes(string s, int k) {
        int n = s.length();
        memset(memo , -1 , sizeof(memo));
        palindromeTable(s , n);
        int ans = helper(s , 0 , k , n);
        return ans;
    }
};
