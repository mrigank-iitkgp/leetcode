/*
 Author: Mrigank
Science is what we understand well enough to explain to a computer, Art is everything else we do - Donald E. Knuth
Problem Link : https://leetcode.com/problems/score-of-parentheses/
*/


class Solution {
public:
    int scoreOfParentheses(string s) {
        stack < int > st;
        int score = 0;
        for(auto x : s)
        {
            if(x == '(')
            {
                st.push(score);
                score = 0;
            }
            else
            {
                score = st.top() + max(2 * score , 1);
                st.pop();
            }
        }
        return score;
    }
};
