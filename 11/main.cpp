#include "student_list.h"
int student::operator<(const student&b) const
{
    return strcmp(name,b.name)<0;
}
int student::init(const char*in,int iv)
{
    value=iv;
    if(in)
    {
        name = new char[strlen(in)+1];
        if(name) strcpy(name,in);
        else return 1;
    }
    return 0;
}

student::student(const char*in,int iv)
{
    init(in,iv);
}

student::student(const student&rhs)
{
    init(rhs.name,rhs.value);
}

student::~student()
{
    if(name) delete [] name;
    name=0;value=0;
}

student& student::operator=(const student&rhs)
{
    this->student::~student();
    init(rhs.name,rhs.value);
    return *this;
}



void student::swaps(student&b)
{
    char*n;int v;
    n=b.name;b.name=name;name=n;
    v=b.value;b.value=value;value=v;
}

int read_array(const char*name,student *a,int n)
{
    FILE *fp;
    int i;
    char b[1000];
    int c;
    if(!(fp=fopen(name,"r"))) return -1;
    for(i=0;i<n;i++)
    {

         if(fscanf(fp,"%s%d",b,&c)!=2)
        {
            if(!feof(fp))
            {
                fclose(fp);
                return -2;
            }
        }
       a[i].init(b,c);
    }
    fclose(fp);
    return i;
}
void print_array(student*a,int n)
{
    int i;
    int m=(n>MAX_N?MAX_N:n);
    for(i=0;i<m;i++) printf("%s %d\n",a[i].get_name(),a[i].get_value());
}
int student_list:: del()
{
    student_node* p;
    if (curr==head)
    {
        head=head->next;
        delete curr;
        curr=head;
    }
    else
    {
        p=head;
        while(p->next!=curr)
            p=p->next;
        p->next=curr->next;
        delete curr;
        curr=p;
    }
}
student_node* solve(student_list &a)
{
    int n=1;
    student_node* prev;
    a.goto_head();
    prev=a.get_curr();
   while (a.get_curr()->get_next())
   {

      if ((!(*(a.get_curr())<*(a.get_curr()->get_next()))&&!(*(a.get_curr()->get_next())<*(a.get_curr())))||(!(*(a.get_curr())<*prev)&&!(*prev<*(a.get_curr()))))
        {prev=a.get_curr();a.del();printf("1\n");}


       a.goto_next();
   }

}

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
    printf("%s %d\n",a.get_curr()->get_name(),a.get_curr()->get_value());

}

int main()
{
    student_list a;
    student* p;
    int k;
    getlist("a.txt",a);
    printarray(a);
    p=solve(a);
    printarray(a);
    return 0;
}
