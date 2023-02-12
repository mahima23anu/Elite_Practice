class Solution {
public:
    
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {

         
        priority_queue <int, vector<int>, greater<int> > minh;
        vector<pair<int,int>> temp;
        for(int i=0;i<speed.size();i++){
          auto x=make_pair(speed[i],efficiency[i]);
          temp.emplace_back(x);
        }
        sort(temp.begin(),temp.end(),[](const pair<int,int> &a,const pair<int,int> &b){
            return (a.second > b.second);
        });
        for(int i=0;i<temp.size();i++){
            cout<<temp[i].first<<" "<<temp[i].second<<endl;
        }
        long speedSum=0,perf=0;
        for(auto x : temp){
            auto currEff=x.second;
            auto currSpeed = x.first;
            if(minh.size()>=k){
                speedSum-=minh.top();
                minh.pop();
            }
            minh.push(currSpeed);
            speedSum+=currSpeed;
            perf=max(perf,speedSum * currEff);
        }

        return (int)(perf%1000000007);

        
    }
};