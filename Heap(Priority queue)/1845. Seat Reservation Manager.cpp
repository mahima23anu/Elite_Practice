class SeatManager {
public:

    struct comp{
    bool operator()(const int &a, const int &b){
        return a>b;
    }
    };
        
    priority_queue <int,vector<int>,comp> pq;
    SeatManager(int n) {
        for(int i=1;i<=n;i++){
            pq.push(i);
        }
    }
    
    int reserve() {
        if(!pq.empty()){
            auto x= pq.top();
            pq.pop();
            return x;
        }
        return 0;
    }
    
    void unreserve(int seatNumber) {
        pq.push(seatNumber);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */