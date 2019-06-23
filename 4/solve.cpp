#include "student_list.h"
int solve(student_list &a)
{
    int i=1;
    student_node* prev;
    student_node* current;
    a.goto_head();
    prev=a.get_curr();
    a.goto_next();
    while(a.get_curr()->get_next())
    {
        current=a.get_curr();
        if((*(prev)<*(current))&&(*(a.get_curr()->get_next())<*(current)))
        {
            i++;
        }
        prev=current;
        current=a.get_curr()->get_next();
        a.goto_next();
    }
return i;
}
