#include <iostream>
#include <stack>
#include <map>

using namespace std;

class Solution {
public:
    map<char,uint8_t> embrace_class;

    Solution(){
        embrace_class['('] = 0;
        embrace_class['['] = 1;
        embrace_class['{'] = 2;
        embrace_class[')'] = 3;
        embrace_class[']'] = 4;
        embrace_class['}'] = 5;
    }

    bool isValid(string s) {
        stack<char> storage;
        if(s.empty())
            return true;
        string::iterator iter = s.begin();
        while (iter!=s.end()) {
            if (embrace_class[*iter] < 3)
                storage.push(*iter);
            else if(storage.empty())
                return false;
            else if(embrace_class[*iter] == (embrace_class[storage.top()] + 3))
                storage.pop();
            else
                return false;
            iter++;
        }
        if (storage.empty())
            return true;
        else
            return false;
    }
};

int main( )
{
    Solution test;

    bool result = test.isValid("[]");
    cout << result << endl;

    return 0;
}

