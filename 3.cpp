#include <iostream>
#include <string>
#include <regex>

using namespace std;

class solution{
public:
    int lengthOfLongestSubstring(string s) {
        if(s.empty())
            return 0;
        string::iterator index = s.begin(),iter,index_ = s.begin();
        int max = 1,result = 1;
        while(index!=s.end()){
            for(iter=index_;iter!=index;iter++){
                if(*index==*iter){
                    index_ = iter+1;
                    break;
                }
            }
            index++;
            max = distance(index_,index);
            result = max>result?max:result;
        }
        return result;
    }
};

int main() {
    solution test;

    int result = test.lengthOfLongestSubstring("a");
    cout<<result<<endl;

    return 0;
}
