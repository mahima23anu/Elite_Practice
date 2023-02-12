class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue <int, vector<int>, greater<int> > minh;
      for(int i=0;i<k;i++){
        minh.push(nums[i]);
      }

      for(int i=k;i<nums.size();i++){
        if(nums[i]>minh.top())
        {
            minh.pop();
            minh.push(nums[i]);
        }
      }
    //   vector<int> ans;
    //   for(int i=0;i<k;i++){
    //     ans.push_back(minh.top());
    //     minh.pop();
    //   }
      return minh.top();

    }
};