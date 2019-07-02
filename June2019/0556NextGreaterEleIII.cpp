// https://leetcode.com/problems/next-greater-element-iii/
class Solution {
public:
    int nextGreaterElement(int n) {
        vector<char> ele;
        if(n == 0)
            return -1;
        while(n!=0){
            ele.push_back( n % 10 + '0');
            n /= 10;
        }
        int i = 0;
        for(i = 1; i < ele.size(); i++){
            if(ele[i] < ele[i-1])
                break;
        }
        if(i == ele.size())
            return -1;
        
        int ind = i-1;
        for(int j = 0 ; j < i-1; j++){
            if(ele[j] > ele[i] && ele[j] < ele[ind])
                ind = j;
        }
        iter_swap(ele.begin() + ind, ele.begin() + i);
        sort(ele.begin(), ele.begin() + i, greater<char>());
        long res = 0, exp = 1;
        for(i = 0; i < ele.size(); i++){
            res += (ele[i]-'0')*exp;
            exp *= 10;
        }  
        return (res > INT_MAX || res < 0) ? -1:res;
    }
};