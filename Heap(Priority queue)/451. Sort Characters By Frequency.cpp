class Solution {
public:
    string frequencySort(string s) {
     struct comp{
            bool operator()(const pair<char,int> &a,const pair<char,int> &b){
                return a.second<b.second;
            }
            };    
            priority_queue <pair<int,int> ,vector<pair<int,int>>,comp> maxh;
            map<char,int> m;
            for(auto x:s){
                m[x]++;
            }
            for(auto y:m){
                maxh.push(y);
            } 
            string ans="";
            while(!maxh.empty()){
                auto c=maxh.top();
                maxh.pop();
                while(c.second--){
                    ans+=c.first;
                }
            }
    return ans; 
    }
};