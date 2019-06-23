#include "student_list.h"
int solve(student_list &a)
{
    int f1=1,f2=1,f3=1;
    student_node* prev;
    student_node* current;
    a.goto_head();
    prev=a.get_curr();
    a.goto_next();
    while(a.get_curr()->get_next())
    {
        current=a.get_curr();

        if(f1&&(*(prev)<*(current)))
        {
           f2=0;
           f3=0;
        } else
        {
            if (f2&&(*(current)<*(prev)))
            {
                f1=0;
                f3=0;
            } else
                {
                    if (f3&&!(*(current)<*(prev))&&!(*(prev)<*(current)))
                    {
                        f1=0;
                        f2=0;
                    }
                }
        }
        prev=current;
        current=a.get_curr()->get_next();
        a.goto_next();
    }
    if (f1)
        return 1;
    if (f2)
        return 2;
    if (f3)
        return 3;
    if (!f1&&!f2&&!f3)
        return 4;
return 0;
}
