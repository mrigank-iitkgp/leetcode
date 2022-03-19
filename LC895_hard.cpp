/*
 Author: Mrigank
Science is what we understand well enough to explain to a computer, Art is everything else we do - Donald E. Knuth
Problem Link : https://leetcode.com/problems/maximum-frequency-stack/
*/


class FreqStack {
public:
    int maxFreq;
    unordered_map < int , int > mp;
    unordered_map < int , stack < int > > freqStack;
    FreqStack() 
    {
        mp.clear();
        freqStack.clear();
        maxFreq = 0;
    }
    
    void push(int val) 
    {
        mp[val]++;
        freqStack[mp[val]].push(val);
        maxFreq = max(maxFreq , mp[val]);
    }
    
    int pop() 
    {
        int val = freqStack[maxFreq].top();
        freqStack[maxFreq].pop();
        if(freqStack[mp[val]--].empty())
        {
            maxFreq--;
        }
        return val;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */
