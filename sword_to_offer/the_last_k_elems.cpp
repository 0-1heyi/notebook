#include <iostream>
#include <vector>
#include <stack>
using namespace std;
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
            val(x), next(NULL) {
    }
};
ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        stack<ListNode*> s;
        ListNode* pth = pListHead;
        while(pth != NULL) {
            s.push(pth);
            pth = pth -> next;
        }
        while(-- k) s.pop();
        return s.top();
}
ListNode* createList(ListNode* pListHead, vector<int>& v) {
    ListNode* ptr = pListHead;
    for(int i =0; i < v.size(); i ++) {
        ListNode* current = new ListNode(v[i]);
        ptr -> next = current;
        ptr = ptr -> next;
    }
    return pListHead;
}
int main()
{
    vector<int> v;
    for(int i =0; i <10; i ++) {
        v.push_back(i);
    }
    ListNode* pListHead = new ListNode(0);
    ListNode* pt = createList(pListHead, v);
    cout << FindKthToTail(pt, 4) -> val;
    return 0;
}