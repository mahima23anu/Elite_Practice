class Solution {
public:

    vector<int> topKFrequent(vector<int>& nums, int k) {
       struct comp{
            bool operator()(const pair<int,int> &a,const pair<int,int> &b){
                return a.second>b.second;
            }
            }; 

        priority_queue <pair<int,int> ,vector<pair<int,int>>,comp> minh;
        map<int,int> m;
        for(auto x:nums){
            m[x]++;
        }

        for(auto y:m){
            minh.push(y);
            if(minh.size()==k+1){
                minh.pop();
            }
        }
        vector<int> ans;
        while(!minh.empty()){
            auto temp=minh.top();
            ans.push_back(temp.first);
            minh.pop();
        }
        return ans;


    }
};