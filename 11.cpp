#include <iostream>
#include <string>
#include <regex>

using namespace std;

class solution{
public:
    int maxArea(vector<int>& height) {
        vector<int>::iterator iter_0 = height.begin(),iter_1 = height.end()-1;
        int max = 0;
        int area;
        while(iter_0!=iter_1){
            area = min(*iter_0,*iter_1)*distance(iter_0,iter_1);
            max = area>max?area:max;
            if(*iter_0<*iter_1)
                iter_0++;
            else iter_1--;
        }
        return max;
    }
};

int main() {
    solution test;
    vector<int> height;
    height.push_back(1);
    height.push_back(8);
    height.push_back(6);
    height.push_back(2);
    height.push_back(5);
    height.push_back(4);
    height.push_back(8);
    height.push_back(3);
    height.push_back(7);
    int result = test.maxArea(height);
    cout<<result<<endl;

    return 0;
}
