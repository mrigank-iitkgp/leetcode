/*
  Author: Mrigank
 Science is what we understand well enough to explain to a computer, Art is everything else we do - Donald E. Knuth
 Problem Link : https://leetcode.com/problems/erect-the-fence/description/
 */
 
class Solution {
public:
    int crossProduct(vector < int >& O , vector < int >& P , vector < int >& Q) {
        return (P[0] - O[0]) * (Q[1] - O[1]) - (P[1] - O[1]) * (Q[0] - O[0]);
    }
    vector<vector<int>> outerTrees(vector<vector<int>>& trees) 
    {
        vector < vector < int > > hull;
        sort(trees.begin() , trees.end() , 
        [&](const vector < int >& a , const vector < int >& b) {
            if(a[0] == b[0])
                return (a[1] < b[1]);
            return a[0] < b[0];
        });
        trees.erase(unique(trees.begin() , trees.end()) , trees.end());
        int n = trees.size();
        for(int i = 0 ; i < n ; i++) {
            while(hull.size() > 1 && crossProduct(hull[hull.size() - 2] , hull.back() , trees[i]) < 0) {
                hull.pop_back();
            }
            hull.push_back(trees[i]);
        }
        int lowerHullSize = hull.size();
        for(int i = n - 2 ; i >= 0 ; i--) {
            while(hull.size() > lowerHullSize && crossProduct(hull[hull.size() - 2] , hull.back() , trees[i]) < 0) {
                hull.pop_back();
            }
            hull.push_back(trees[i]);
        }
        sort(hull.begin() , hull.end());
        hull.erase(unique(hull.begin() , hull.end()) , hull.end());
        return hull;
    }
};
