class Solution {
    
public:
    int lastStoneWeightII(vector<int>& stones) {
        set<int> s{0};
        for(auto x: stones) {
            set<int> tmp;
            for(auto t: s) {
                tmp.insert(t-x);
                tmp.insert(t+x);
            }
            s = tmp;
        }
        return *s.lower_bound(0);
    }   
};
