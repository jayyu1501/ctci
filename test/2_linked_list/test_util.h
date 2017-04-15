#include <linked_list/linked_list.h>
#include <gtest/gtest.h>

using namespace std;

Node *create_linked_list(const vector<int>& nums);
void destroy_linked_list(Node* head);
vector<int> dump_data(Node *head);

class BaseTest : public ::testing::Test
{
public:
    BaseTest()
        : mHead(nullptr)
    {}

    ~BaseTest()
    {
        destroy_linked_list(mHead);
    }

    void create_list(vector<int>& val)
    {
        mHead = create_linked_list(val);
    }

    vector<int> to_vector()
    {
        return dump_data(mHead);
    }

    Node* get_nth_node(int n)
    {
        if (n <= 0)
        {
            return nullptr;
        }

        Node *p = mHead;
        Node *prev = nullptr;
        while (n > 0 && p)
        {
            prev = p;            
            p = p->next;
            n--;
        }

        if (n > 0)
        {
            return nullptr;
        }
        return prev;
    }
    
    Node *mHead;
};
