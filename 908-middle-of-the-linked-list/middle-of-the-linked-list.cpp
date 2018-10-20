// Given a non-empty, singly linked list with head node head, return a middle node of linked list.
//
// If there are two middle nodes, return the second middle node.
//
//  
//
//
// Example 1:
//
//
// Input: [1,2,3,4,5]
// Output: Node 3 from this list (Serialization: [3,4,5])
// The returned node has value 3.  (The judge's serialization of this node is [3,4,5]).
// Note that we returned a ListNode object ans, such that:
// ans.val = 3, ans.next.val = 4, ans.next.next.val = 5, and ans.next.next.next = NULL.
//
//
//
// Example 2:
//
//
// Input: [1,2,3,4,5,6]
// Output: Node 4 from this list (Serialization: [4,5,6])
// Since the list has two middle nodes with values 3 and 4, we return the second one.
//
//
//  
//
// Note:
//
//
// 	The number of nodes in the given list will be between 1 and 100.
//
//
// " />
//
//     <meta name="keywords" content="LeetCode, 领扣, 领扣网, 领扣网络, 领扣中国, lingkou, LC, LCCN, LeetCode中国, LeetCode官网, 刷题, 在线编程, LeetCode题库, 面经, 算法, 面试, 面试题, 机器学习, 大数据, 代码, 汇编, 编程, 开发, 程序员, 工程师, 码农, 程序猿, BAT, BAT面试, OJ, online judge, coding , interview, 技术面试, LeetCode中文版, leetcodechina


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast)
        {
            if(fast->next&&fast->next->next)              
            {
                fast=fast->next->next;
                slow=slow->next;
            }
            else if(fast->next&&!fast->next->next)
            {
                fast=fast->next->next;
                slow=slow->next;
            }
            else if(!fast->next)
                fast=nullptr;
        }
        return slow;
        
    }
};
