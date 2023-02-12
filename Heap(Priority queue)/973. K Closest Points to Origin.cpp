// class Point{
// public:;
//    int x;
//    int y;
//    int d;
//    Point(int x, int y , int d){
//        this->x=x;
//        this->y=y;
//        this->d=d;
//    }
// };


class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        struct comparator{
        bool operator()(const pair<pair<int,int>,int> &x,const pair<pair<int,int>,int> &y){
        return x.second<y.second;
        }
    };
        priority_queue<pair<pair<int,int>,int>, vector<pair<pair<int,int>,int>>,comparator> maxh;
        
        

        for(auto point : points){
            int x=point[0];
            int y=point[1];
            int d=x*x+y*y;
            auto m=make_pair(x,y);
            auto n=make_pair(m,d);
            maxh.push(n);
            if(maxh.size()>k){
                maxh.pop();
            }
        }

        vector<vector<int>> ans(k,{0,0});
        int i=0;
        while(!maxh.empty()){
            auto p=maxh.top();
            maxh.pop();
            ans[i][0]=p.first.first;
            ans[i][1]=p.first.second;
            i+=1;
        }
        return ans;
    }
};