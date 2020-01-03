#include <iostream>
#include <string>
#include <map>

using namespace std;

class solution{
public:
    int romanToInt(string s) {
        string::iterator iter;
        int result = 0;
        map<char,int> roman_map;
        map<char,int>::iterator value_0,value_1;
        roman_map['I'] = 1;
        roman_map['V'] = 5;
        roman_map['X'] = 10;
        roman_map['L'] = 50;
        roman_map['C'] = 100;
        roman_map['D'] = 500;
        roman_map['M'] = 1000;
        if(s.empty())
            return 0;
        value_0 = roman_map.find(*s.begin());
        for(iter = s.begin()+1;iter!=s.end();iter++){
            value_1 = roman_map.find(*iter);
            if(value_0->second<value_1->second)
                result-=value_0->second;
            else
                result+=value_0->second;
            value_0 = value_1;
        }
        result+=value_0->second;
        return result;
    }
};

int main() {
    solution test;

    int result = test.romanToInt("LVIII");
    cout<<result<<endl;

    return 0;
}
