#include <iostream>
#include <string>
#include <regex>

using namespace std;

class solution{
public:
    string intToRoman(int num) {
        string result;
        int selection[13] = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
        string Roman[13] = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        for(int i = 0;i<13;i++){
            while (num/selection[i]>0){
                num-=selection[i];
                result.append(Roman[i]);
            }
        }
        return result;
    }
};

int main() {
    solution test;

    string result = test.intToRoman(3);
    cout<<result<<endl;

    return 0;
}
