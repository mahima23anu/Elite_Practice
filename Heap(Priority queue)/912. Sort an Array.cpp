class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        priority_queue<int,vector<int>,greater<int>> minh;
        //vector<int> ans;
        for(int i=0;i<nums.size();i++){
           minh.push(nums[i]);
        }
        nums.clear();
        while(minh.size()){
            auto x=minh.top();
            nums.push_back(x);
            minh.pop();
        }
        return nums;

    }
};