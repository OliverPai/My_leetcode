#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

class solution{
public:
    bool isPalindrome(int x) {
        string x_str = to_string(x);
        int half = x_str.length()%2?x_str.length()/2+1:x_str.length()/2;
        string x_left = x_str.substr(0,half);
        string x_right = x_str.substr(x_str.length()/2,half);
        reverse(x_right.begin(),x_right.end());
        return x_left==x_right;
    }
};

int main() {
    solution test;

    bool result = test.isPalindrome(12212);
    cout<<result<<endl;

    return 0;
}
