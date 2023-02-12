class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        auto x=0,y=0;
        priority_queue <int> maxh;
        for(int i=0;i<stones.size();i++){
            maxh.push(stones[i]);

        }
        while(maxh.size()!=1){
            x=maxh.top();
            maxh.pop();
            if(maxh.size())
            {y=maxh.top();
            maxh.pop();}
            cout<<x<<" "<<y<<endl;
            if(x-y){
                maxh.push(abs(x-y));
                
            }
            if(maxh.size()==0)
            return 0;
        }
        
        return maxh.top();
    }
};