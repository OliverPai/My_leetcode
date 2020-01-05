#include <iostream>
#include <vector>
#include <map>

using namespace std;

class solution{
public:
    map<char,string> phoneNumbers;
    solution(){
        phoneNumbers['2'] = "abc";
        phoneNumbers['3'] = "def";
        phoneNumbers['4'] = "ghi";
        phoneNumbers['5'] = "jkl";
        phoneNumbers['6'] = "mno";
        phoneNumbers['7'] = "pqrs";
        phoneNumbers['8'] = "tuv";
        phoneNumbers['9'] = "wxyz";
    }

    vector<string> letterCombinations(string digits) {
        vector<string> result,next_result;
        if(digits.empty())return result;

        vector<string>::iterator iter_result;
        map<char ,string>::iterator iter_index;
        string::iterator hash_find;
        next_result = letterCombinations(digits.substr(1));
        iter_index  = phoneNumbers.find(*digits.begin());
        for(hash_find = iter_index->second.begin();hash_find!=iter_index->second.end();hash_find++){
            if(next_result.empty()) {
                string temp;
                temp.push_back(*hash_find);
                result.push_back(temp);
            }
            else {
                for (iter_result = next_result.begin(); iter_result != next_result.end(); iter_result++)
                    result.push_back(*hash_find + *iter_result);
            }
        }
        return result;
    }
};

int main() {
    solution test;

    vector<string> result = test.letterCombinations("23");
    vector<string>::iterator iter;
    for(iter = result.begin();iter!=result.end();iter++)
        cout << *iter << endl;

    return 0;
}
