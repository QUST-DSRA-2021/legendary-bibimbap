/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        Node * q = new Node;
        q->next = head;

        while (head != nullptr) {
            if (head->child != nullptr) {
                Node * tmp = head->next;

                Node * chead = flatten(head->child);
                head->next = chead;
                chead->prev = head;
                head->child = nullptr;

                while (head->next != nullptr)
                    head = head->next;

                head->next = tmp;
                if (tmp != nullptr)
                    tmp->prev = head;
                head = tmp;

            } else
                head = head->next;
        }
        return q->next;
    }
};
