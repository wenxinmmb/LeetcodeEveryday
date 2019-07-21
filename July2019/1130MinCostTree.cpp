//https://leetcode.com/problems/minimum-cost-tree-from-leaf-values/
class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        int res = 0;
        while(arr.size() > 1){
            auto ele =  std::min_element(arr.begin(),arr.end());
            int minInd = ele - arr.begin();
            int nei = INT_MAX;
            if(minInd > 0)
                nei = arr[minInd-1];
            if(minInd < arr.size()-1)
                nei = min(nei, arr[minInd+1]);
            res += (nei*arr[minInd]) ;
            
            arr.erase(ele);
        }
        return res;
            
    }
};