#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class solution{
public:
    vector<vector<int>> threeSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        vector<int> aggregation(3);
        vector<int>::iterator iter,iter_left,iter_right;
        int sum_temp;
        if(nums.size()<3)
            return result;
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
                    aggregation[0] = *iter;
                    aggregation[1] = *iter_left;
                    aggregation[2] = *iter_right;
                    result.push_back(aggregation);
                    while (*(iter_left + 1) == *iter_left++)
                        if (iter_left == iter_right)
                            break;
                } else if (sum_temp < target) {
                    while (*(iter_left + 1) == *iter_left++)
                        if (iter_left == iter_right)
                            break;
                } else if (sum_temp > target) {
                    while (*(iter_right - 1) == *iter_right--)
                        if (iter_left == iter_right)
                            break;
                }
            }
        }
        return result;
    }

    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());//升序快排
        vector<vector<int>> result,threeSum_result;
        vector<int>::iterator iter;
        vector<vector<int>>::iterator iter_threeSum;
        if(nums.size()<4)
            return result;
        for(iter = nums.begin();iter!=nums.end()-3;iter++){
            if(iter!=nums.begin()) {
                if (*iter == *(iter - 1))
                    continue;
            }
            vector<int> threeSum_input;
            threeSum_input.insert(threeSum_input.begin(),iter+1,nums.end());
            threeSum_result = threeSum(threeSum_input, target-*iter);
            if(!threeSum_input.empty()){
                for(iter_threeSum = threeSum_result.begin();iter_threeSum!=threeSum_result.end();iter_threeSum++)
                {
                    vector<int> threeSum_push;
                    threeSum_push.push_back(*iter);
                    threeSum_push.push_back(iter_threeSum->at(0));
                    threeSum_push.push_back(iter_threeSum->at(1));
                    threeSum_push.push_back(iter_threeSum->at(2));
                    result.push_back(threeSum_push);
                }
            }
        }
        return result;
    }
};

int main() {
    solution test;

    vector<int> inputs;
    inputs.push_back(1);
    inputs.push_back(-2);
    inputs.push_back(-5);
    inputs.push_back(-4);
    inputs.push_back(-3);
    inputs.push_back(3);
    inputs.push_back(3);
    inputs.push_back(5);
    vector<vector<int>> result = test.fourSum(inputs,-11);
    vector<vector<int>>::iterator iter;
    vector<int>::iterator iter_1;
    for(iter = result.begin();iter!=result.end();iter++) {
        for(iter_1 = iter->begin();iter_1!=iter->end();iter_1++)
            cout << *iter_1 <<" ";
        cout<<endl;
    }

    return 0;
}
