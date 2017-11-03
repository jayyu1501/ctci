#include "linked_list.h"

/*
 * Use two pointers, one moves 1 step each time and another moves
 * 2 stpes each time. When they meet first time, we know
 * x+y = t and x+y+c = 2t suppose t is the time, x is the distance from
 * head to the loop start, y is from loop start to where they meet and c
 * is the length of the circle. So we know c = t; 
 * We will know the length of the circular is actually how long they meet.
 * From where they meet, we use another pointer moving from head. So after
 * c-y steps, they will meet together at the start of the loop.
 * 
 */

const Node* get_start_of_loop(const Node* head)
{
    if (head == nullptr || head->next == nullptr) {
        return nullptr;
    }

    const Node* slow = head;
    const Node* fast = head;

    // Get the node when them meet
    do {
        slow = slow->next;
        fast = fast->next->next;
    } while(slow != fast && fast && fast->next);

    if (fast == nullptr || fast->next == nullptr) {
        return nullptr; // no loop at all
    }

    // move both from head and where them meet
    const Node* fromHead = head;
    const Node* fromMeet = slow;
    while(fromHead && fromMeet && fromHead != fromMeet) 
    {
        fromHead = fromHead->next;
        fromMeet = fromMeet->next;
    }
    if (!fromHead || !fromMeet) {
        return nullptr;
    }
    return fromHead;
}