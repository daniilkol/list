#include "student_list.h"
int solve(student_list &a)
{
    int el_num=1,p=0,len=0,max_len=0;
    a.goto_head();
    while(a.get_curr()->get_next())
    {
       p=el_num;
       for (;(a.get_curr()->get_next())&&!(*(a.get_curr())<*(a.get_curr()->get_next()))&&!(*(a.get_curr()->get_next())<*(a.get_curr()));a.goto_next())
       {
           el_num++;
       }
       len=el_num-p+1;
       if (len>max_len)
       {
          max_len=len;
       }


       a.goto_next();
       el_num++;
    }
 return max_len;
}
