class Solution {
public:
    string reorganizeString(string s) {
        struct valueCompare {
        char operator()(pair<char, int> &x, pair<char, int> &y) {
            return y.second > x.second;
        }
    };
     unordered_map<char, int> m;
        for(char ch : s) {
            m[ch]++;
        }
        priority_queue<pair<char, int>, vector<pair<char, int>>, valueCompare> max_heap;
        for(auto x : m) {
            max_heap.push(x);
        }
        pair<char, int> prev(-1, -1);
        string res = "";
        while(!max_heap.empty()) {
            pair<char, int> temp = max_heap.top();
            max_heap.pop();
            res += temp.first;
            if(prev.second > 0) {
                max_heap.push(prev);
            }   
            prev = temp;
            prev.second--;
            
        }
        
        if(res.length() == s.length()) {
            return res;
        }
        else {
            return "";
        }
    }
    
};