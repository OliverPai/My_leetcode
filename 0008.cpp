#include <iostream>
#include <string>
#include <regex>

using namespace std;

class solution{
public:
    int myAtoi(string str) {
        str.erase(0,str.find_first_not_of(" "));
        int result = 0,flag = 0;
        regex integer("^[\\+-]?\\d+");
        regex none("\\s*");
        smatch answer;
        flag = regex_search(str,answer,integer);
        if(flag) {
            regex_replace(answer[0].str(),none,"");
            string number = answer[0].str();
            cout<<number<<endl;
            string::iterator iter;
            for(iter=number.begin();iter!=number.end();iter++){
                if(number[0]=='-') {
                    if (*iter != '-') {
                        if(result>=INT32_MIN/10) {
                            if ((-(*iter-48) >= INT32_MIN - 10 * result))
                                result = 10 * result - (*iter - 48);
                            else result = INT32_MIN;
                        }
                        else result = INT32_MIN;
                    }
                }
                else if(*iter!='+'){
                    if(result<=INT32_MAX/10) {
                        if (((*iter-48) <= INT32_MAX - 10 * result))
                            result = 10 * result + (*iter - 48);
                        else result = INT32_MAX;
                    }
                    else result = INT32_MAX;
                }
            }
        }
        return result;
    }
};

int main() {
    solution test;

    int result = test.myAtoi("2147483646");
    cout<<result<<endl;

    return 0;
}
