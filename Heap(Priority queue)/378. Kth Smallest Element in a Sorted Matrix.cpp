class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        
        priority_queue<int> maxh;
        vector<int> temp;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[i].size();j++){
                temp.push_back(matrix[i][j]);
                
            }
        }
        for(int i=0;i<temp.size();i++){
            cout<<temp[i]<<" ";
        }
        for(int i=0;i<k;i++){
            maxh.push(temp[i]);
           // cout<<i<<" ";
        }
        for(int i=k;i<temp.size();i++){
            if(temp[i]<maxh.top()){
                // cout<<endl;
                // cout<<maxh.top();
                maxh.pop();
                maxh.push(temp[i]);
            }
        }
        //cout<<maxh.size();
        
        // while(cnt<k && minh.size()){
        //     auto xxx=minh.top();
        //    minh.pop();
           
        //    cnt++;
        //    if(matrix[xxx.first.second][xxx.second+1]){
        //        auto y=make_pair(matrix[xxx.first.second][xxx.second+1],xxx.first.second);
        //        auto yy=make_pair(y,xxx.second+1);
        //      minh.push(yy);
        //    }

        // }
        return maxh.top();
    }
};