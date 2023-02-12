class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
    vector<pair<int,int>> t;
        int n=mat.size(),cnt=0;;
        vector<int> temp;
        vector<int> ans;
        for(int i=0;i<mat.size();i++){
            cnt=0;
            for(int j=0;j<mat[i].size();j++){
                if(mat[i][j]==1)
                cnt++;
            }
            temp.push_back(cnt);
        }
        for(int i=0;i<n;i++){
            auto x=make_pair(temp[i],i);
            t.push_back(x);
            
        }
        sort(t.begin(),t.end());
        for(int i=0;i<k;i++){
             ans.push_back(t[i].second);
        }
        return ans;
    }
};