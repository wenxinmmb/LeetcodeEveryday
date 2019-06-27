// https://leetcode.com/problems/random-flip-matrix/
// https://en.wikipedia.org/wiki/Fisher–Yates_shuffle#Examples
class Solution {
public:
    long t, total, r ;
    unordered_map<int,int> called;
    Solution(int n_rows, int n_cols) {
        total = n_rows* n_cols;
        t = total;
        r = n_cols;
    }
    
    vector<int> flip() {
        
        int v2 = rand() % t;
        int v1;
        if(called.count(v2) == 0){
            v1 = v2;    
        }
        else{
            v1 = called[v2];           
        }
        
        if(called.count(t-1) == 0){
            called[v2] = t - 1;
        }
        else{
            called[v2] = called[t-1];
        }
        
        t --;
        return vector<int>{v1 / r, v1 % r};
    }
    
    void reset() {
        t = total;
        called.clear();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(n_rows, n_cols);
 * vector<int> param_1 = obj->flip();
 * obj->reset();
 */