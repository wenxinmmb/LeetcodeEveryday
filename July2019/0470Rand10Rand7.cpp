// https://leetcode.com/problems/implement-rand10-using-rand
// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
    int rand10() {
        int r1 = 7, r2 = 7;
        while(r1 > 5)
            r1 = rand7();
        while(r2 > 6)
            r2 = rand7();
        if(r2 > 3)
            return r1*2;
        else
            return r1*2-1;
        
    }
};