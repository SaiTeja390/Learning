//
// Created by sai on 04/12/19.
//

#include <stack>
#include <map>
#include "arr.h"


int arr::arr_max(vector<int> &a, vector<int> &start, vector<int> &end, vector<int> &values){

    vector<int> arr(a.size(),0);

    for(int i=0; i<start.size(); i++){
        try{
            arr.at(start[i]) += values[i];
            arr.at(end[i]+1) -= values[i];
        }

        catch (const out_of_range &e){
            cout<<e.what()<<endl;
            continue;
        }

    }

    int res,sum = 0, max_val = INT32_MIN;

    for(int i=0; i<arr.size(); i++){
        sum+=arr.at(i);
        res = sum+a.at(i);
        max_val = max(res,max_val);
    }
    return max_val;
}

bool arr::next_permutation(vector<int> &vec){

    vector<int>::iterator iter,iter2;
//     print(vec);

    for(iter=--vec.end();iter>vec.begin() && *iter < *(prev(iter));--iter){
//         cout<<*iter<<"\n";

    }
    if(iter==vec.begin())
        return false;
    iter--;
//     cout<<*(iter)<<"\n\n";
    int x = *iter;
    for(iter2 = --vec.end();iter2!=vec.begin() && *iter2<=x;--iter2){
//        cout<<*iter2<<"\n";
    }
//     cout<<*iter2<<"\n\n";

    swap(*iter2,*iter);
//     print(vec);

//     cout<<"\n";

    reverse(++iter,vec.end());
//     print(vec);

//     cout<<"\n";




//     cout<<*iter<<"\n";

    return true;

}

 bool arr::transform(string &s1, string &s2){
    if(s1.size() != s2.size())
        return false;

    unordered_multimap<char, int> map;
    vector<int> not_matched;

    for(int i=0;i<s1.size();i++){
        if(s1.at(i) != s2.at(i)) {
            map.insert(make_pair(s1.at(i), i));
            not_matched.push_back(i);
        }
    }
    unordered_multimap<char, int>::iterator pos;
//    for(auto iter=not_matched.begin();iter!=not_matched.end();iter++){
//        pos = map.find('a');
//        if(pos==map.end())
//            return false;
//        else
//    }
     return true;
}

int arr::maximumProduct(vector<int>& nums) {


    const int n = min((const int)nums.size(),5);

    vector<int> copy_n(n);
    vector<int> values(n);
    copy(nums.begin(), nums.begin()+n,copy_n.begin());

    sort(nums.begin(), nums.begin()+n);
    copy(nums.begin(), nums.begin()+n,values.begin());

    vector<int>::iterator p,q,b_min,e_min;
    vector<int>::iterator b_max,e_max;

    e_max = values.end();
    b_max = e_max - 3;
    b_min = values.begin();
    e_min = b_min+2;

    for(auto iter=nums.begin()+n; iter!=nums.end(); iter++){
        p = upper_bound(b_max,e_max,*iter);
        if(p!=b_max){
            if(p==e_max){
              rotate(e_min,e_min+1,e_max);
              p = e_max -1;
            }
            else {
                rotate(b_max, b_max + 1, p);
            }
            *(p-1) = *iter;

        }
        if(*iter < 0){
            q = upper_bound(b_min, e_min, *iter);
            if(q!=e_min){
                rotate(q,e_min-1,e_min);
                *q = *iter;
            }
        }

    }
    copy(copy_n.begin(), copy_n.end(), nums.begin());
    if(*(e_max - 1) <= 0)
        return values.at(n-3)*values.at(n-2)*values.at(n-1);

    const int neg_max = *(b_min)*(*(b_min+1));
    const int pos_max = *(b_max)*(*(b_max+1));


//    return (max(neg_max,pos_max)*values[n-1]);
    return 1;
}

string arr::longestCommonPrefix(vector<string>& strs) {

    int j =0, n_str = strs.size();
    bool flag = true;

    if(n_str==0)
        return "";
    else if (n_str==1)
        return strs.at(0);

    try{
        while(flag){
            for(int i=0; i<n_str-1; i++){
                if(strs.at(i).at(j) != strs.at(i).at(j)) {
                    flag = false;
                    break;
                }
            }
            j++;
        }
    }
    catch(const out_of_range &e) {
        if(j==0) {
            return "";
        }
        else {
            return strs[0].substr(0, j);
        }
    }
    return strs[0].substr(0, j - 1);
}

int arr::climbStairs(int n) {

    int tot_ways = n;
    int n_two=2;
    int ways=n-1;


    int k=2;

    while(2*n_two <= n){

        for(int i=k;i<k+2;i++){
            ways*= n-i;
        }
        ways/=n_two;
        ways  /= (n-n_two+1);

        tot_ways += ways;
        n_two++;
        k+=2;
    }
    return tot_ways;

}

void arr::sortColors(vector<int>& nums) {
    auto last_non_zero = find_if(nums.begin(), nums.end(), [](int i){return i!=0;});
    auto first_non_two = find_if(nums.rbegin(), nums.rend(), [](int i){return i!=2;});
    bool found_one=false;

    vector<int>::iterator iter;
    //    last_non_zero =
    //    first_non_two ;
    //    cout<<"PRINTING"<<endl;
    //    for(auto iter = nums.rbegin();iter!=nums.rend();iter++){
    //        cout<<*iter<<" ";
    //    }
    for(iter = last_non_zero; iter!=nums.end() && iter<=first_non_two.base()-1; ){
        print(nums.begin(),nums.end());
        cout<<*iter<<" ";
        cout<<*first_non_two<<" ";
        cout<<*last_non_zero<<endl<<endl;
        if(*iter ==0){
            iter_swap(iter,last_non_zero);
            // first_non_two = find_if(first_non_two, nums.rend(), [](int i){return i!=2;});
            iter++;
            if(found_one){
                last_non_zero = find_if(last_non_zero, nums.end(), [](int i){return i!=0;});
            }
            else{
                last_non_zero=iter;
            }

            continue;
        }
        if(*iter == 2){
            iter_swap(iter, first_non_two);
            first_non_two = find_if(first_non_two, nums.rend(), [](int i){return i!=2;});
            continue;
            //            iter--;
        }
        if(*iter==1){
            found_one=true;
            iter++;
            continue;
        }
    }
    print(nums.begin(),nums.end());
    cout<<*iter<<" ";
    cout<<*first_non_two<<" ";
    cout<<*last_non_zero<<endl<<endl;



}
int arr::searchInsert(vector<int>& nums, int target) {
    auto iter = lower_bound(nums.begin(),nums.end(),target);
    auto iter2 = iter - nums.begin();

    return iter - nums.begin();
}

string arr::countAndSay(int n) {
    string inp("1");
    string out;
    for(int i=2;i<=n;i++){
        for(auto iter=inp.begin();iter!=inp.end();){
            auto iter2 = adjacent_find(iter,inp.end(),[](char i, char j){return i!=j;});

            if(iter2==inp.end()) {

                out.append(to_string(iter2 - iter));
                out.append(to_string(*iter - 48));
                iter = inp.end();
            }
            else{
                out.append(to_string(iter2 - iter +1));
                out.append(to_string(*iter - 48));
                iter = iter2+1;
            }

        }
        swap(out,inp);
        out.erase();

    }
    return inp;

}

bool arr::isSymmetric(TreeNode* root) {
    bool similar = true;

    if(root==NULL || (root->left == NULL && root->right==NULL))
        similar= true;

    else if (root->left != NULL && root->right!=NULL){
        queue <TreeNode*> s1;
        queue <TreeNode*> s2;

        TreeNode* x_r, *x_l;
        s1.push(root->left);
        s2.push(root->right);


        while(!s1.empty()){
            x_l = s1.front();
            s1.pop();
            x_r = s2.front();
            s2.pop();

            if(!(((x_l->left == NULL && x_r->right == NULL) || (x_l->left != NULL && x_r->right != NULL)) && ((x_l->right == NULL && x_r->left == NULL) || (x_l->right != NULL && x_r->left != NULL)))){
                similar = false;
                break;
            }
            if(x_l->left != NULL) {
                if(x_l->left->val == x_r->right->val) {
                    s1.push(x_l->left);
                    s2.push(x_r->right);
                }
                else{
                    similar = false;
                    break;
                }
            }
            if(x_l->right != NULL){
                if(x_l->right->val == x_r->left->val) {
                    s1.push(x_l->right);
                    s2.push(x_r->left);
                }
                else{
                    similar = false;
                    break;
                }

            }

        }
    }

    else{
        similar = false;
    }
    return similar;
}

vector<vector<int>> arr::levelOrder(TreeNode* root) {
    vector<vector<int>> out;
    vector<int> nodes;
    queue<TreeNode *> q1;
    queue<TreeNode *> q2;
    TreeNode *node;
    if (root != NULL) {
        nodes.push_back(root->val);
        out.push_back(nodes);
        nodes.clear();
        q1.push(root);
        while (!q1.empty()) {
            while (!q1.empty()) {
                node = q1.front();
                q1.pop();
                if (node->left != NULL) {
                    nodes.push_back(node->left->val);
                    q2.push(node->left);
                }
                if (node->right != NULL) {
                    nodes.push_back(node->right->val);
                    q2.push(node->right);
                }
            }
            if (!nodes.empty()) {
                out.push_back(nodes);
            }
            swap(q1, q2);
            nodes.erase(nodes.begin(), nodes.end());
        }

    }
    return out;
}


int arr::maxSubArray(vector<int>& nums) {
    int largest_neg = INT32_MIN;
    int max_sum,sum=0;
    max_sum=0;
    for(auto iter = nums.begin();iter!=nums.end(); iter++){
        if(*iter<0 && *iter>largest_neg){
            largest_neg = *iter;
        }

        if(*iter+sum>0){
            sum = *iter+sum;

        }
        else{
            sum=0;
        }
        max_sum = max(sum,max_sum);
    }
    return max_sum;
}
int arr::singleNonDuplicate(vector<int>& nums) {

    if(nums.size() ==1) {
        return nums[0];
    }

    int start = 0;
    int end = nums.size()-1;
    int middle = end-start/2;
    while(start<end){
        middle = (start+end)/2;
        if(middle%2 == 0 ){
            middle+=1; //the index is odd
        }

        if(nums.at(middle-1) == nums.at(middle)){
                start = middle+1;
        }
        else if(nums.at(middle) == nums.at(middle+1)){
                end = middle-1;
        }
        else{
            return nums.at(middle);
        }
    }
}

int arr::coin_change(vector<int> &nums, int n){
    int upper_bound;
    sort(nums.begin(), nums.end());
    upper_bound = n - nums.front();
    unordered_map<int,vector<int> > table;
    for(int i =1; i<=n; i++){
        vector<int> n_comb(nums.size(),0);
        for(auto iter=nums.begin(); iter!=nums.end();iter++){
            int v;
            int coin=*iter;
            int coin_pos = iter-nums.begin();
             int res = i-coin;
             if(res<0){
                 break;
             }
             else if(res==0){
                 v=1;
             }
             else{
                 v = table.at(res).at(coin_pos);
             }
             n_comb[coin_pos] = v;
        }
        partial_sum(n_comb.rbegin(), n_comb.rend(), n_comb.rbegin());
        table[i] = n_comb;
    }

    return table.at(n).at(0);

}

vector<int> arr::findDuplicates(vector<int>& nums) {
    vector<int> out;
    int pos=0;
    for(auto iter=nums.begin(); iter!=nums.end();){
        pos = iter-nums.begin();
        if(*iter == pos+1 || *iter == 0){
            iter++;
            continue;
        }
        else{
            auto index_iter = nums.begin()+*iter -1;

            if(*index_iter == *iter){
                out.push_back(*iter);
                *iter=0;
                iter++;
            }

            else{
                iter_swap(iter, index_iter);
            }
        }

    }
    return out;

}

int arr::romanToInt(string s) {
    map<char,short> rom_to_int = {{'I', 1},
                                {'V',5},
                                {'X',10},
                                {'L',50},
                                {'C',100},
                                {'D',500},
                                {'M',1000}
    };
    short prev_v=0,current_v,sum=0;

    string::iterator prev_iter = s.begin();
    for(auto iter=s.begin(); iter!=s.end(); ){
        auto p = adjacent_find(iter,s.end(),[](char x, char y) { return x!=y;});
        if(p!=s.end()) p+=1;
        current_v = (p-iter)*rom_to_int[*iter];

        sum += current_v;
        try {
            if (rom_to_int[*iter] > rom_to_int.at(*prev_iter)){
                sum-=2*prev_v;
            }
        }
        catch (const out_of_range &e){

        }
        prev_iter = iter;
        prev_v = current_v;
        iter = p;
    }
    return sum;
}


//void fun(vector<int> &nums){
//    const int n = nums.end() - nums.begin();
//    array<int,n> arr({1,2,3});
//    unordered_multimap<char,string> x;
//    x.insert()
//
//}