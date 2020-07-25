#include<iostream>
#include<math.h>
#include<iomanip>
#include <unordered_map>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <unordered_set>
using namespace std;

//1、给定一个字符串，找出不含有重复字符的最长子串的长度。
//Given a string, find the length of the longest substring without repeating characters.
//示例 1:
//
//输入: "abcabcbb"
//输出 : 3
//解释 : 因为无重复字符的最长子串是 "abc"，所以其长度为 3。

//示例 2 :
//
//输入 : "bbbbb"
//输出 : 1
//解释 : 因为无重复字符的最长子串是 "b"，所以其长度为 1。
//1
//2
//3
//示例 3 :
//
//输入 : "pwwkew"
//输出 : 3
//解释 : 因为无重复字符的最长子串是 "wke"，所以其长度为 3

//example1 ✔
//解法一：滑动窗口
/*思路：设立左指针a和右指针b
b指针向右侧伸缩｛
    对每个A[b]判断是否在之前的数组出现过；
    如果出现，指针a指向出现过的位置的下一个位置；
    更新右指针和最大长度；
｝
时间复杂度O(n^2)，空间复杂度O(1)。

执行结果：通过
显示详情
执行用时：20  ms, 在所有 C++ 提交中击败了71.14%的用户
内存消耗：7 MB, 在所有 C++ 提交中击败了100.00%的用户
*/
int lengthOfLongestSubstring(string s)
{
    int start(0), end(0), length(0), result(0);
    int size = s.size();
    while (end < size)
    {
        char end_word = s[end];
        for (int i = start; i < end; i++)
        {
            if (s[i] == end_word) {
                start = i + 1;
                length = end - start;
                break;
            }
        }
        end++;
        length++;
        result = length > result ? length : result;
    }
    return result;
}

//解法二：hashmap
//map的key存字符，但是value不存什么0或1了。直接存当前的有序下标，解决了多个字母出现的问题。
/*思路：判断是否出现过时，利用hashmap优化时间。
时间复杂度O(n)，空间复杂度O(n)。

执行结果：通过
显示详情
执行用时：36  ms, 在所有 C++ 提交中击败了60.40%的用户
内存消耗：8.7 MB, 在所有 C++ 提交中击败了100.00%的用户
*/
int lengthOfLongestSubstringHashMap(string s) {
        //s[start,end) 前面包含 后面不包含
        int start(0), end(0), length(0), result(0);
        int sSize = int(s.size());
        unordered_map<char, int> hash;
        while (end < sSize)
        {
            char tmpChar = s[end];
            //仅当s[start,end) 中存在s[end]时更新start
            if (hash.find(tmpChar) != hash.end() && hash[tmpChar] >= start)
            {
                start = hash[tmpChar] + 1;
                length = end - start;
            }
            hash[tmpChar] = end;

            end++;
            length++;
            result = length > result ? length : result;
        }
        return result;
}

//利用数组（桶）代替hashmap
/*思路：判断是否出现过时，利用桶来代替hashmap优化时间。
时间复杂度O(n)，空间复杂度O(n)。

执行结果：通过
显示详情
执行用时：4 ms, 在所有 C++ 提交中击败了99.09%的用户
内存消耗：7.9 MB, 在所有 C++ 提交中击败了100.00%的用户
*/
int lengthOfLongestSubstringVector(string s)
{
    //s[start,end) 前面包含 后面不包含
    int start(0), end(0), length(0), result(0);
    int sSize = int(s.size());
    vector<int> vec(128, -1);
    while (end < sSize)
    {
        char tmpChar = s[end];
        //仅当s[start,end) 中存在s[end]时更新start
        if (vec[int(tmpChar)] >= start)
        {
            start = vec[int(tmpChar)] + 1;
            length = end - start;
        }
        vec[int(tmpChar)] = end;

        end++;
        length++;
        result = length > result ? length : result;
    }
    return result;
}

//给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。
//你可以假设每种输入只会对应一个答案。但是，数组中同一个元素不能使用两遍。
//示例:
//给定 nums = [2, 7, 11, 15], target = 9
//因为 nums[0] + nums[1] = 2 + 7 = 9
//所以返回[0, 1]
//通过
//执行用时：12 ms, 在所有 C++ 提交中击败了87.82 %的用户
//内存消耗：8.3 MB, 在所有 C++ 提交中击败了100.00 %的用户

//example2 ✔
vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> m_hash;
    vector<int> result;
    for (int i = 0; i < nums.size(); i++) {
        if (m_hash.count(nums[i]) != 0) {
            result = { i,m_hash[nums[i]] };
            return result;
        }
        else
        {
            m_hash[target - nums[i]] = i;
        }
    }
}

//给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。
//如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。
//您可以假设除了数字 0 之外，这两个数都不会以 0 开头。
//示例：
//输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
//输出：7 -> 0 -> 8
//原因：342 + 465 = 807

//example3 ✔
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
//我的解法，耗时36ms，空间9.4M
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    int carry = 0;//进位
    ListNode* result = new ListNode(0);
    result->next = new ListNode(0);
    ListNode* cur = result->next;
    while (l1 != NULL || l2 != NULL || carry)
    {
        if (l1 == NULL)l1 = new ListNode(0);
        if (l2 == NULL)l2 = new ListNode(0);
        cur->val = (l1->val + l2->val+ carry) % 10;
        carry = (l1->val + l2->val + carry) / 10;
        l1 = l1->next;
        l2 = l2->next;
        if (l1 != NULL || l2 != NULL || carry) {
            cur->next = new ListNode(0);
            cur = cur->next;
        }
    }
    return result->next;
}
//别人的解法，耗时24ms，空间8.6M
ListNode* addTwoNumbers2(ListNode* l1, ListNode* l2) {
    int c = 0, temp = 0;
    ListNode* t1 = l1, * t2 = l2;
    while (t1->next != NULL && t2->next != NULL) {
        temp = (t1->val + t2->val + c) / 10;
        t1->val = (t1->val + t2->val + c) % 10;
        c = temp;
        t1 = t1->next;
        t2 = t2->next;
    }
    if (t1->next == NULL && t2->next == NULL) {
        temp = t1->val + t2->val + c;
        if (temp > 9)
            t1->next = new ListNode(temp / 10);
        t1->val = temp % 10;
    }
    else {
        if (t1->next == NULL)
            t1->next = t2->next;
        temp = (t1->val + t2->val + c) / 10;
        t1->val = (t1->val + t2->val + c) % 10;
        c = temp;
        t1 = t1->next;
        while (c != 0 && t1->next != NULL) {
            temp = t1->val + c;
            t1->val = temp % 10;
            c = temp / 10;
            t1 = t1->next;
        }
        if (c != 0) {
            if (t1->val + c > 9)
                t1->next = new ListNode(1);
            t1->val = (t1->val + c) % 10;
        }
    }
    return l1;
}

int main()
{
    //example1 ✔
    /*string input = "abcabcbb";
    int Maxlength = lengthOfLongestSubstring(input);
    cout << Maxlength << endl;*/

    //example2 ✔
    /*vector<int> a = { 11,2,15,7 };
    vector<int> b = twoSum(a, 9);
    cout << b[0] << b[1] << endl;*/

    //example3 ✔
    //输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
    /*ListNode* a1 =  new ListNode(2);
    a1->next = new ListNode(4);
    a1->next->next = new ListNode(3);
    ListNode* a2 = new ListNode(5);
    a2->next = new ListNode(6);
    a2->next->next = new ListNode(4);
    ListNode* b = addTwoNumbers(a1,a2);*/

    return 0;
}
