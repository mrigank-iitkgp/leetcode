class Solution {
public:
    vector<vector<string>> mostPopularCreator(vector<string>& creators, vector<string>& ids, vector<int>& views) {
        unordered_map < string , unordered_map < string , int > > mp;
        int n = creators.size();
        for(int i = 0 ; i < n ; i++) {
            mp[creators[i]][ids[i]] = views[i];
        }
        vector < vector < string > > ans;
        vector < pair < string , int > > creatorsViews;
        for(auto& x : mp) {
            int sum = 0;
            for(auto& y : x.second) {
                sum += y.second;
            }
            creatorsViews.push_back({x.first , sum});
        }
        sort(creatorsViews.begin() , creatorsViews.end() , 
        [&](const pair < string , int >& a , const pair < string , int >& b) {
            return a.second > b.second;
        }
        );
        vector < string > topCreators;
        int maxView = creatorsViews[0].second;
        for(auto& creator : creatorsViews) {
            if(creator.second != maxView) break;
            topCreators.push_back(creator.first);
        }
        for(auto& creator : topCreators) {
            unordered_map < string , int > temp = mp[creator];
            int maxView = INT_MIN;
            for(auto& x : temp) {
                maxView = max(x.second , maxView);
            }
            string id = "";
            for(auto& x : temp) {
                if(x.second == maxView) {
                    if(id == "") id = x.first;
                    else id = min(id , x.first);
                }
            }
            vector < string > res;
            res.push_back(creator);
            res.push_back(id);
            ans.push_back(res);
        }
        return ans;
    }
};
