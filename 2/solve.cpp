#include "student_list.h"
int solve(student_list &a)
{
    int i=1;
    student_node* max;
    a.goto_head();
    max=a.get_curr();
    while(a.get_curr()->get_next())
    {
        if(*(max)<*(a.get_curr()->get_next()))
        {
            max=a.get_curr()->get_next();
            i=1;
        }
        else i++;
        a.goto_next();
    }
return i;
}
