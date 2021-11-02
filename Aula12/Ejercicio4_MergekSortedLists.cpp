#include <bits/stdc++.h>
using namespace std;

/*
link: https://leetcode.com/problems/merge-k-sorted-lists/

Input: lists = [[1,4,5],[1,3,4],[2,6]]
Output: [1,1,2,3,4,4,5,6]

*/


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists){
        ListNode *result = nullptr; 
        priority_queue<int> pq;
        for(int i=0;i<lists.size();i++){
            ListNode *next=lists[i];
            while(next){
                pq.push(next->val);
                next = next->next;
            }
        }
        
        while (! pq.empty() ) {
            ListNode *prev = new ListNode(pq.top(),result);
            result = prev; 
            pq.pop();
        }
        return result;
    }
};


int main(){
    
    vector<ListNode*>lists;
    ListNode* l;

    int n,value,k;
    cin >> k;
    for (int i = 0; i <k;i++){
        ListNode* list = new ListNode(2);
        ListNode* temp = list;
        cin>>n;
        for (int j = 0; j <n;j++)  {
            cin>> value;
            temp->next = new ListNode(value);
            temp = temp->next;
        }
         lists.push_back(list);
    }

    Solution s;
    l=s.mergeKLists(lists);
    while (l!=nullptr)
    {
        cout << l->val << " ";
        l=l->next;
    }
    

    return 0;
}