#include <linked_list/linked_list.h>
#include <gtest/gtest.h>
#include <iostream>

using namespace std;

Node *create_linked_list(const vector<int>& nums);
void destroy_linked_list(Node* head);
vector<int> dump_data(Node* head);
void append(Node* left, Node* right);

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

    Node* create_list(vector<int>& val)
    {
        mHead = create_linked_list(val);
        return mHead;
    }

    vector<int> to_vector()
    {
        return dump_data(mHead);
    }

    void print_data()
    {
        Node *p = mHead;
        cout << "data:";
        while(p)
        {
            cout << p->data  << " ";
            p = p->next;
        }
        cout << endl;
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

    bool is_same(std::initializer_list<int> values, Node* head)
    {
        auto it = values.begin();
        while(head && it != values.end())
        {
            if (*it != head->data)
            {
                return false;
            }
            it++;
            head = head->next;
        }
        if (head || it != values.end())
        {
            return false;
        }
        return true;
    }
    
    Node *mHead;
};
