/*
 Author: Mrigank
Science is what we understand well enough to explain to a computer, Art is everything else we do - Donald E. Knuth
Problem Link : https://leetcode.com/problems/watering-plants-ii/
*/


class Solution {
public:
    int minimumRefill(vector<int>& plants, int capacityA, int capacityB) 
    {
        int alice = capacityA;
        int bob = capacityB;
        
        int totalRefill = 0;
        
        int n = plants.size();
        int i = 0 , j = n - 1;
        
        while(i <= j)
        {
            if(i == j)
            {
                if(alice >= bob)
                {
                    if(alice < plants[i])
                    {
                        alice = capacityA;
                        totalRefill++;
                    }
                    alice -= plants[i];
                    i++;
                }
                else
                {
                    if(bob < plants[j])
                    {
                        bob = capacityB;
                        totalRefill++;
                    }
                    bob -= plants[j];
                    j--;
                }
            }
            else
            {
                if(alice < plants[i])
                {
                    alice = capacityA;
                    totalRefill++;
                }
                alice -= plants[i];
                i++;
                
                if(bob < plants[j])
                {
                    bob = capacityB;
                    totalRefill++;
                }
                bob -= plants[j];
                j--;
            }
        }
        return totalRefill;
    }
};
