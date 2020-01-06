#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    string str_Compare_2(string str_0,string str_1){
        string::iterator iter_0 = str_0.begin(),iter_1 = str_1.begin();
        string result;
        while (iter_0!=str_0.end()){
            if(*iter_0==*iter_1){
                result.push_back(*iter_0);
                iter_0++;
                iter_1++;
            }
            else break;
        }
        return result;
    }
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty())
            return "";
        else if (strs.size()==1)
            return *strs.begin();
        else if(strs.size()==2)
            return str_Compare_2(
                    strs.begin()->length()<(strs.begin()+1)->length()?*strs.begin():*(strs.begin()+1),
                    strs.begin()->length()>=(strs.begin()+1)->length()?*strs.begin():*(strs.begin()+1)
                    );
        else {
            sort(strs.begin(), strs.end(), [](string &a, string &b) {
                return a.size() < b.size();
            });
            vector<string>::iterator iter=strs.begin()+2;
            string prefix = str_Compare_2(*strs.begin(), *(strs.begin() + 1));
            do {
                if(prefix.empty())
                    break;
                else{
                    prefix = str_Compare_2(prefix, *iter);
                }
            }while(++iter != strs.end());
            return prefix;
        }
    }
};

int main( )
{
    Solution test;

    vector<string> strs;
    strs.push_back("flower");
    strs.push_back("flow");
    strs.push_back("flight");
    string outputs = test.longestCommonPrefix(strs);
    cout<<outputs<<endl;

    return 0;
}

