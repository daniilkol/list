#include "student_list.h"
int solve(student_list &a)
{
    int f1=1,f2=0,k1max=1,k2max=1,kmax;
    student_node* prev;
    student_node* current;
    a.goto_head();
    prev=a.get_curr();
    a.goto_next();
    while(a.get_curr()->get_next())
    {
        current=a.get_curr();
        if (f1&&(*(prev)<*(current)))
        {
            k1max++;
        } else
        {
            f1=0;
            f2=1;
        }
        if (f2&&(*(prev)<*(current)))
        {
            k2max++;
        } else
        {
            f1=1;
            f2=0;
            if (k1max>k2max)
                kmax=k1max;
            else kmax=k2max;
            k1max=k2max=1;

        }
        prev=current;
        current=a.get_curr()->get_next();
        a.goto_next();
    }
 return kmax;
}
