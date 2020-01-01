#include <iostream>
#include <vector>
#include <string>

using namespace std;

class solution{
public:
    string convert(string s, int numRows){
        if(numRows==1)
            return s;
        else{
            string result;
            int substr_size = 2*numRows-2;
            int substr_nums = s.length()%substr_size?s.length()/substr_size+1:s.length()/substr_size;
            vector<string> substr(substr_nums);
            for(int i=0;i<substr_nums-1;i++)
                substr[i] = s.substr(i*substr_size,substr_size);
            substr[substr_nums-1] = s.substr(substr_size*(substr_nums-1),s.length()-substr_size*(substr_nums-1));
            int i = 0;
            do{
                for (vector<string>::iterator iter = substr.begin(); iter != substr.end(); iter++) {
                    //cout<<*iter<<endl;
                    if(i<iter->length())
                        result.push_back(iter->at(i));
                    if((substr_size-i<iter->length())&&(i!=substr_size-i))
                        result.push_back(iter->at(substr_size-i));
                }
            }while(i++!=numRows-1);
            return result;
        }
    }
};

int main() {
    solution test;

    string result = test.convert("LEETCODEISHIRING",4);
    cout<<result<<endl;

    return 0;
}
