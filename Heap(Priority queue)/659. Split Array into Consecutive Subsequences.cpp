class Solution {
   public:
   bool isPossible(vector<int>& nums) {
      unordered_map <int, int> m;
      int n = nums.size();
      for(int i = 0; i < n; i++){
         m[nums[i]]++;
      }
      int cnt = n;
      for(int i = 0; i < n; i++){
         int x = nums[i];
         if(m[x] && m[x + 1] && m[x + 2]){
            m[x]--;
            m[x + 1]--;
            m[x + 2]--;
            x += 3;
            cnt -= 3;
            while(m[x] > 0 && m[x] > m[x - 1]){
               cnt--;
               m[x]--;
               x++;
            }
         }
      }
      return cnt == 0;
   }
};