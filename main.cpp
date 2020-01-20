#include <iostream>
#include <vector>
#include <array>
#include "arr.h"

using namespace std;
int factorial(int n){

    return (n == 1 || n == 0) ? 1 : factorial(n - 1) * n;
}


void print(vector<int>::iterator b, vector<int>::iterator e){

    vector<int>::iterator iter;
    for(iter=b;iter!=e;iter++)
        cout<<*iter<<" ";

    cout<<"\n";
}





int main() {
    std::cout << "Hello, World!" << std::endl;
    vector<int> vec({1,2,2,3,3,5,6,8,7});
//    vector<int> vec({0});
    vector<int>::iterator iter;
    for(iter = vec.begin();iter!=vec.end();iter++){
        cout<<*iter<<" ";
    }
    vector<int> v1({0,2});
    vector<int> v2({1,3});
    vector<int> v3({5,6});
    int x = arr::arr_max(vec, v1, v2, v3);
    cout<<"max "<<x<<endl;

    cout<<"Starting Next Permutaion"<<endl;
//    while(arr::next_permutation(vec)){
//        print(vec);
//    }

    string s1("sairam");
    string s2("saiamr");

    if(arr::transform(s1,s2)){
        cout<<"converted"<<endl;
    }
    else{
        cout<<"Not Anagrams"<<endl;
    }

//    int max_p = arr::maximumProduct(vec);
//    cout<<max_p<<endl;

    vector<string> strs;
    strs.push_back("flower");
//    strs.push_back("flower");
//    strs.push_back("flower");

    string str = arr::longestCommonPrefix(strs);
    cout<<str<<endl;

    int n = 25;
//    n = arr::climbStairs(n);
    cout<<n;

//    arr::sortColors(vec);
//    n = arr::searchInsert(vec,1);
//      str = arr::countAndSay(4);
//    string line("1,2,2,3,4,4,3")
//    TreeNode* root = stringToTreeNode(line);
    TreeNode root(5);
    TreeNode z(1);
    TreeNode y(2);
    root.left = &z;
    root.right = &y;
    TreeNode a(10);
    z.right = &a;
//    bool b = arr::isSymmetric(&root);
//    vector<vector<int>> out = arr::levelOrder(&root);


//    n = arr::singleNonDuplicate(vec);
//    n = arr::coin_change(vec, 7);
//    cout<<"\ncoin_change: "<<n<<endl;
//    vector<int> out = arr::findDuplicates(vec);

    n = arr::romanToInt("VII");
    NumArray* obj = new NumArray(vec);
    int param_1 = obj->sumRange(1,2);

return 0;
}










//vector<int>:: iterator p = find_if(v.begin(), v.end(), [](int i)
//{
//    return i > 4;
//});
//cout << "First number greater than 4 is : " << *p << endl;