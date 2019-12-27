#include <iostream>
#include <vector>

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x): val(x),next(NULL){};
};

class solution{
public:
    int reverse(int x){
        int result = 0;
        int x_ = x;
        bool flag = 0;
        std::vector<int>temp;
        if(x_<0){
            x_=(x_==-2147483648)?0:0-x;
            flag = 1;//标记为负
        }
        while(x_>=10){
            temp.push_back(x_%10);
            x_/=10;
        }
        temp.push_back(x_);
        std::vector<int>::iterator iter;
        for(iter=temp.begin();iter!=temp.end();iter++){
            if(result<=2147483647/10)
                if(*iter<=(2147483647-10*result))
                    result=10*result+*iter;
                else result = 0;
            else result = 0;
        }
        return flag?0-result:result;
    }
};

int main() {
    solution test;
    int result = test.reverse(1534236469);
    std::cout<<result<<std::endl;

    return 0;
}
