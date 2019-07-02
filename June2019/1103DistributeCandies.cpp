// https://leetcode.com/problems/distribute-candies-to-people/
class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> res;
        
        float base = 1+8*(float)candies;
        int times = (-1 + sqrt(base))/2;
        int count = times/num_people;
        int rem = times%num_people;

        for(int i=0; i< num_people; i++){
            int sum = 0;
            if(i >= rem){
                sum = (1+i)* count+ (count)*(count-1)*num_people/2;
                cout<< sum <<endl;
            }
            else{
                sum = (1+i)* (count+1)+ (count+1)*(count)*num_people/2;
                cout<< sum <<endl;
            }
            res.push_back(sum);
        }
        
        int suff = candies - (times + times*(times-1)/2);
        res[(rem)%num_people]+=suff;
        return res;
    }
};