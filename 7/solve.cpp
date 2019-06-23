#include "student_list.h"
int solve(student_list &a)
{
    int k=0,n=1;
    a.goto_head();
    while(a.get_curr()->get_next())
    {
       for (;(a.get_curr()->get_next())&&!(*(a.get_curr())<*(a.get_curr()->get_next()))&&!(*(a.get_curr()->get_next())<*(a.get_curr()));a.goto_next())
       {
           n++;
       }
       if (n>1)
       {
           k++;
           n=1;
       }

       a.goto_next();
    }
 return k;
}
