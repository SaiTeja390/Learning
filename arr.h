//
// Created by sai on 04/12/19.
//

#ifndef CLION1_ARR_H
#define CLION1_ARR_H

#include <vector>
#include <array>
#include <algorithm>
#include <queue>
#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

void print(vector<int>::iterator b, vector<int>::iterator e);
int factorial(int n);

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};




class arr {

public:
    static int arr_max(vector<int> &a, vector<int> &start, vector<int> &end, vector<int> &values);
    static bool next_permutation(vector<int> &vec);
    static bool transform(string &s1, string &s2);
    static int maximumProduct(vector<int>& nums);
    static string longestCommonPrefix(vector<string>& strs);
    static int climbStairs(int n);
    static void sortColors(vector<int>& nums);
    static int searchInsert(vector<int>& nums, int target);
    static string countAndSay(int n);
    static bool isSymmetric(TreeNode* root);
    static vector<vector<int>> levelOrder(TreeNode* root);
    static int maxSubArray(vector<int>& nums);
    static int singleNonDuplicate(vector<int>& nums);
    static int coin_change(vector<int> &nums, int n);
    static vector<int> findDuplicates(vector<int>& nums);
    static int romanToInt(string s);
};

class NumArray {
public:
    int* a;
    int size;
    NumArray(vector<int>& nums) {
        size = nums.size();
        a = new int[nums.size()];
        a[0] = nums[0];
        for(int i=1;i<nums.size();i++){
            a[i] = a[i-1]+nums[i];
        }
    }

    int sumRange(int i, int j) {
        return this->a[j] - this->a[i-1];
    }
};


#endif //CLION1_ARR_H
