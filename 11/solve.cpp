#include "student_list.h"
int solve(student_list &a)
{
    int i=0;
    a.goto_head();
    while(a.get_curr()->get_next())
    {
        if(*(a.get_curr())<*(a.get_curr()->get_next()))
        {
            i++;
        }
        a.goto_next();
    }
return i;
}
