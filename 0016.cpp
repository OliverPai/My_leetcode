#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());//升序快排
        int result;
        vector<int>::iterator iter,iter_left,iter_right;
        int sum_temp;
        if(nums.size()<3)
            return result;
        result = *nums.begin()+*(nums.begin()+1)+*(nums.end()-1);
        for(iter = nums.begin();iter!=nums.end()-2;iter++){
            if(iter!=nums.begin()){
                if(*iter == *(iter-1))
                    continue;
            }
            iter_left = iter+1;
            iter_right = nums.end()-1;
            while(iter_left!=iter_right){
                sum_temp = *iter+*iter_left+*iter_right;
                if(sum_temp == target){
                    return sum_temp;
                } else if (sum_temp < target) {
                    if (abs(result-target)>abs(sum_temp-target))
                        result = sum_temp;
                    while (*(iter_left + 1) == *iter_left++)
                        if (iter_left == iter_right)
                            break;
                } else {//sum_temp > target
                    if (abs(result-target)>abs(sum_temp-target))
                        result = sum_temp;
                    while (*(iter_right - 1) == *iter_right--)
                        if (iter_left == iter_right)
                            break;
                }
            }
        }
        return result;
    }
};
