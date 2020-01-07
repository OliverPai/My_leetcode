#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    struct twoTree{
        char val;
        bool done;
        int count_left,count_right;
        twoTree* left;
        twoTree* right;
        twoTree* parent;
        twoTree(char x): val(x),done(0),count_left(0),count_right(0),left(NULL),right(NULL),parent(NULL){}
    };

    twoTree* generateTree(twoTree* root,int n) {
        if (root->count_left == n && root->count_right == n)
            return root;
        if (root->count_left < n) {
            if (root->count_left > root->count_right) {
                twoTree *next_left = new twoTree('(');
                twoTree *next_right = new twoTree(')');
                next_left->count_left = root->count_left + 1;
                next_left->count_right = root->count_right;
                next_right->count_right = root->count_right + 1;
                next_right->count_left = root->count_left;
                next_left = generateTree(next_left, n);
                next_right = generateTree(next_right, n);
                root->left = next_left;
                next_left->parent = root;
                root->right = next_right;
                next_right->parent = root;
            } else {
                twoTree *next_left = new twoTree('(');
                next_left->count_left = root->count_left + 1;
                next_left->count_right = root->count_right;
                next_left = generateTree(next_left, n);
                root->left = next_left;
                next_left->parent = root;
            }
        } else {
            twoTree *next_right = new twoTree(')');
            next_right->count_left = root->count_left;
            next_right->count_right = root->count_right + 1;
            next_right = generateTree(next_right, n);
            root->right = next_right;
            next_right->parent = root;
        }
        return root;
    }

    vector<string> scanTree(twoTree* root, int n){
        vector<string> result;
        twoTree * pointer = root;
        string strs;
        while(1) {
            if (pointer->left != NULL) {
                if(!pointer->done){
                    pointer->done = 1;
                    strs.push_back(pointer->val);
                }
                pointer = pointer->left;
            } else if (pointer->right!=NULL){
                if(!pointer->done) {
                    pointer->done = 1;
                    strs.push_back(pointer->val);
                }
                pointer = pointer->right;
            }
            else{
                if(pointer->count_left==n&&pointer->count_right==n) {
                    strs.push_back(pointer->val);
                    string str_temp = strs;
                    result.push_back(str_temp);
                }
                strs.pop_back();
                twoTree *point_temp = pointer;
                pointer = pointer->parent;
                if(point_temp==pointer->left)
                    pointer->left = NULL;
                else
                    pointer->right = NULL;
                delete point_temp;
                if((pointer==root)&&(pointer->left==NULL)&&(pointer->right==NULL))
                    break;
            }
        }
        delete pointer;
        return result;
    }

    vector<string> generateParenthesis(int n) {
        vector<string> result;
        if(n==0)
            return result;
        twoTree * root = new twoTree('(');
        root->count_left = 1;
        root = generateTree(root,n);
        result = scanTree(root,n);
        return result;
    }
};

int main( )
{
    Solution test;

    vector<string>result = test.generateParenthesis(4);
    vector<string>::iterator iter;
    for(iter = result.begin();iter!=result.end();iter++)
        cout << *iter << endl;

    return 0;
}

