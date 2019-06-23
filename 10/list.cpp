#include "student_list.h"
int getlist(const char*name,student_list&a)
{
    FILE *fp;
    int i=0;
    char b[1000];
    int c;
    student_node* q;
    if(!(fp=fopen(name,"r"))) return -1;

    if(fscanf(fp,"%s%d",b,&c)==2)
    {
        q->init(b,c);
        a.add_first(*q);
        i++;
    }
    else{fclose(fp);return -3;}

    while(fscanf(fp,"%s%d",b,&c)==2)
    {
        q=new student_node;
        q->init(b,c);
        a.add(*q);
        i++;
    }
    if(!feof(fp))
        {
            fclose(fp);
            return -2;
        }
    fclose(fp);
    printf("q=%s %d\n",q->get_name(),q->get_value());
    return i;
}
void printarray(student_list &a)
{
    int i=0;
    printf("\n\n\n");
   a.goto_head();
    while(a.get_curr()->get_next()&&i<MAX_N) {printf("%s %d\n",a.get_curr()->get_name(),a.get_curr()->get_value());a.goto_next();i++;}
}
