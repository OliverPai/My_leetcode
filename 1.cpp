class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>::iterator iter_1,iter_2;
        vector<int> result;
        for(iter_1=nums.begin();iter_1!=nums.end();iter_1++){
            for(iter_2=iter_1+1;iter_2!=nums.end();iter_2++){
                if(target==*iter_1+*iter_2){
                    result.push_back(distance(nums.begin(),iter_1));
                    result.push_back(distance(nums.begin(),iter_2));
                    return result;
                }
            }
        }
        return result;
    }
};
