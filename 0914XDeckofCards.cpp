// https://leetcode.com/problems/x-of-a-kind-in-a-deck-of-cards/
// if only I used std:__gcd
class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        map<int,int> mm;
        if(deck.size() < 2)
            return false;
        
        for(auto dk: deck){
            mm[dk]++;
        }
        
        int num = mm.begin()->second;
        if(num == 1)
            return false;
        for(auto m:mm){
            // cout<< num<<","<<m.second<<endl;
            if(num <= 1 || m.second <= 1)
                return false;
            if(m.second == num)
                continue;
            
            if(m.second > num){
                if(m.second % num == 0)
                    continue;
                
                int temp = num/2;
                while(temp > 1){
                    if(m.second % temp == 0 && num % temp == 0)
                    {
                        num = temp;
                        break;
                    }
                    temp--;
                }
                if(temp == 1)
                    return false;
            }
            else{
                if(num % m.second == 0)
                    continue;
                
                int temp = m.second/2 ;
                while(temp > 1){
                    if(m.second % temp == 0 && num % temp == 0)
                    {
                        num = temp;
                        break;
                    }
                    temp--;
                }
                if(temp == 1)
                    return false;
            } 
        }
        return true;
    }
};