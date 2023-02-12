#include<iostream>

class Solution {
public:
    
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        int curr_ht=0;
        vector<pair<int,int>> temp;
        vector<vector<int>> ans;
        multiset<int> pq;
        for(int i=0;i<buildings.size();i++){
            auto x= make_pair(buildings[i][0],-buildings[i][2]);
            auto y= make_pair(buildings[i][1], buildings[i][2]);
            temp.emplace_back(x);
            temp.emplace_back(y);

        }
        sort(temp.begin(),temp.end());
        pq.insert(0);
        for(int i=0;i<temp.size();i++){
            if(temp[i].second<0){
                pq.insert(-temp[i].second);
            }
            if(!pq.empty() && temp[i].second>0){
                pq.erase(pq.find(temp[i].second));
            }
            auto top=*pq.rbegin();
            if(!pq.empty() && curr_ht!=top){
                curr_ht=top;
                ans.push_back({temp[i].first,top});
            }
        }
        return ans;
    }
};