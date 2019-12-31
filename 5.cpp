#include <iostream>
#include <vector>
#include <string>

using namespace std;

class solution{
public:
    //Manacher algorithm
    string longestPalindrome(string s) {
        string::iterator iter;
        string temp,result;
        temp.insert(0,"$#");
        for(iter=s.begin();iter!=s.end();iter++){
            temp.push_back(*iter);
            temp.push_back('#');
        }
        int R = 1,C = 1,max = 0;//回文右边界，回文中心，最长字符串长度
        int pL,cL;
        vector<int> radius(temp.length());
        radius[0] = 0;
        int round = 0;
        for(int i = 1;i<temp.length();i++){
            if(2*C-i>=0&&2*C-i<temp.length())
                pL = 2*C-i-radius[2*C-i]+1;
            cL = 2*C-R;
            if((i>=R)||(i<R&&cL==pL)){
                if(i<R)
                    round = R-i+1;
                while((i-round)>=0&&(i+round)<=temp.length()-1){
                    if(temp[i+round]==temp[i-round])
                        round++;
                    else
                        break;
                }
                radius[i] = round;
            }
            else
                radius[i] = min(radius[pL],R-i+1);
            if(round>max){
                C = i;
                R = C + round - 1;
                max = round;
            }
            round = 0;
        }
        temp = temp.substr(cL,max*2-1);
        for(iter=temp.begin();iter!=temp.end();iter++)
            if(*iter!='#')
                result.push_back(*iter);
        return result;
    }
};

int main() {
    solution test;

    string result = test.longestPalindrome("lqlvciwekzxapmjxyddlaoqhfhwphamsyfwjinkfvciucjhdgwodvmnpkibumexvlsxxumvrznuuyqfavmgwfnsvfbrvqhlvhpxaqehsiwxzlvvtxsnmlilbnmvnxyxitxwoahjricdjdncvartepfpdfndxqoozkfpdmlpvshzzffsspdjzlhmamqooooor");
    cout<<result<<endl;

    return 0;
}
