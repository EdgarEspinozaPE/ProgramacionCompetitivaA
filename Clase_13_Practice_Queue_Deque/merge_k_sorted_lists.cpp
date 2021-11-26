#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* mergeKLists(vector<ListNode*>& lists) {
    if (lists.size() == 0) return nullptr;
    priority_queue<int> pq;

    for (auto node : lists) {
        ListNode* aux = node;
        while (aux) {
            pq.push(aux->val);
            aux = aux->next;
        }
    }

    if (!pq.empty()) {
        ListNode* head = new ListNode(pq.top());
        pq.pop();

        while (!pq.empty()) {
            ListNode* aux = new ListNode(pq.top());
            pq.pop();
            aux->next = head;
            head = aux;

        }
        return head;
    }
    else return nullptr;
}

int main(int argc, char const* argv[]) {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ListNode* a2 = new ListNode(5, nullptr);
    ListNode* a1 = new ListNode(4, a2);
    ListNode* a0 = new ListNode(1, a1);

    ListNode* b2 = new ListNode(4, nullptr);
    ListNode* b1 = new ListNode(3, b2);
    ListNode* b0 = new ListNode(1, b1);

    ListNode* c1 = new ListNode(6, nullptr);
    ListNode* c0 = new ListNode(2, c1);

    vector<ListNode*> lists;
    lists.push_back(a0);
    lists.push_back(b0);
    lists.push_back(c0);

    ListNode* head = mergeKLists(lists);
    while (head)
    {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;

    return 0;
}