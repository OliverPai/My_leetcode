#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class solution{
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());//升序快排
        vector<vector<int>> result;
        vector<int> aggregation(3);
        vector<int>::iterator iter,iter_left,iter_right;
        int sum_temp;
        if(nums.size()<3)
            return result;
        for(iter = nums.begin();iter!=nums.end()-2;iter++){
            if(iter!=nums.begin())
                if(*iter == *(iter-1))
                    continue;//跳过重复
            if(*iter>0)
                return result;//排除无谓情况
            iter_left = iter+1;
            iter_right = nums.end()-1;
            while(iter_left!=iter_right){
                sum_temp = *iter+*iter_left+*iter_right;
                if(sum_temp == 0){
                    aggregation[0] = *iter;
                    aggregation[1] = *iter_left;
                    aggregation[2] = *iter_right;
                    result.push_back(aggregation);
                    if(*(iter_left+1)==*iter_left) {
                        while (*(iter_left + 1) == *iter_left++)
                            if (iter_left == iter_right)
                                break;
                    }
                    else
                        iter_left++;
                    continue;
                } else if (sum_temp < 0){
                    iter_left++;
                    continue;
                } else if (sum_temp > 0){
                    iter_right--;
                    continue;
                }
            }
        }
        return result;
    }
};

int main() {
    solution test;

    vector<int> inputs;
    inputs.push_back(-2);
    inputs.push_back(0);
    inputs.push_back(1);
    inputs.push_back(1);
    inputs.push_back(1);
    inputs.push_back(1);
    vector<vector<int>> result = test.threeSum(inputs);
    vector<vector<int>>::iterator iter;
    vector<int>::iterator iter_1;
    for(iter = result.begin();iter!=result.end();iter++) {
        for(iter_1 = iter->begin();iter_1!=iter->end();iter_1++)
            cout << *iter_1 <<" ";
        cout<<endl;
    }

    return 0;
}
