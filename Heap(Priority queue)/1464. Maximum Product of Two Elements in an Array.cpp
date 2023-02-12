class Solution {
public:
    int maxProduct(vector<int>& nums) {
        priority_queue<int> maxh;
        for(int i=0;i<nums.size();i++){
            maxh.push(nums[i]);
        }
        auto x=maxh.top();
        maxh.pop();
        auto y = maxh.top();

        return (x-1)*(y-1);
        
        }
};