#include "student_node.h"
class student_list
{
private:
    student_node*head;
    student_node*curr;
public:
    student_list(){head=0;curr=0;}
    ~student_list(){curr=head;while(head->next)del();}
    void add(student_node&a) {a.next=curr->next;curr->next=&a;goto_next();}
    int del();
    void goto_next(){if(curr->next)curr=curr->next;else return;}
    void goto_head(){if(!empty()) curr=head;}
    student_node* add_first(student_node&i){head=&i;curr=head;return head;}

    student_node* get_curr(){return curr;}
    bool empty(){if(head) return false; return true;}
};
int getlist(const char*name,student_list& a);
void printarray(student_list &a);
student_node* solve(student_list &a,student* s);
