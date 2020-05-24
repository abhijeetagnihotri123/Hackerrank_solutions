#include <bits/stdc++.h>

using namespace std;

class DoublyLinkedListNode {
    public:
        int data;
        DoublyLinkedListNode *next;
        DoublyLinkedListNode *prev;

        DoublyLinkedListNode(int node_data) {
            this->data = node_data;
            this->next = nullptr;
            this->prev = nullptr;
        }
};

class DoublyLinkedList {
    public:
        DoublyLinkedListNode *head;
        DoublyLinkedListNode *tail;

        DoublyLinkedList() {
            this->head = nullptr;
            this->tail = nullptr;
        }

        void insert_node(int node_data) {
            DoublyLinkedListNode* node = new DoublyLinkedListNode(node_data);

            if (!this->head) {
                this->head = node;
            } else {
                this->tail->next = node;
                node->prev = this->tail;
            }

            this->tail = node;
        }
};

void print_doubly_linked_list(DoublyLinkedListNode* node, string sep, ofstream& fout) {
    while (node) {
        fout << node->data;

        node = node->next;

        if (node) {
            fout << sep;
        }
    }
}

void free_doubly_linked_list(DoublyLinkedListNode* node) {
    while (node) {
        DoublyLinkedListNode* temp = node;
        node = node->next;

        free(temp);
    }
}

// Complete the sortedInsert function below.

/*
 * For your reference:
 *
 * DoublyLinkedListNode {
 *     int data;
 *     DoublyLinkedListNode* next;
 *     DoublyLinkedListNode* prev;
 * };
 *
 */

DoublyLinkedListNode* sortedInsert(DoublyLinkedListNode* head, int data) {
    
    if(head==NULL)
    {
        head=new DoublyLinkedListNode(data);
        return head;
    }
    else if(data <= head->data)
    {
        DoublyLinkedListNode *current=new DoublyLinkedListNode(data);
        head->prev=current;
        current->next=head;
        head=head->prev;
        return head;
    }
    else if(data > head->data && head->next==NULL)
    {
        DoublyLinkedListNode *current=new DoublyLinkedListNode(data);
        head->next=current;
        current->prev=head;
        return head;
    }
    else
    {
    DoublyLinkedListNode *current=new DoublyLinkedListNode(data);
    DoublyLinkedListNode *temp=head;    
        while(temp->next!=NULL)
        {
            if(current->data < temp->data)
            {
                break;
            }
            else
            {
            temp=temp->next;
            }
        }
        if(temp->next==NULL && current->data > temp->data)
        {
            temp->next=current;
            current->prev=temp;
        }
        else
        {
            temp->prev->next=current;
            current->prev=temp->prev;
            current->next=temp;
            temp->prev=current;
        }
        return head;
    }
}
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        DoublyLinkedList* llist = new DoublyLinkedList();

        int llist_count;
        cin >> llist_count;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        for (int i = 0; i < llist_count; i++) {
            int llist_item;
            cin >> llist_item;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            llist->insert_node(llist_item);
        }

        DoublyLinkedListNode* llist1 = reverse(llist->head);

        print_doubly_linked_list(llist1, " ", fout);
        fout << "\n";

        free_doubly_linked_list(llist1);
    }

    fout.close();

    return 0;
}
