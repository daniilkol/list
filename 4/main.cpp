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

int readarray(const char*name,student *a,int n)
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
void printarray(student*a,int n)
{
    int i;
    int m=(n>MAX_N?MAX_N:n);
    for(i=0;i<m;i++) printf("%s %d\n",a[i].get_name(),a[i].get_value());
}
int solve(student_list &a)
{
    int i=1;
    student_node* prev;
    student_node* current;
    prev=new student_node;
    current=new student_node;
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

int main()
{
    student_list a;
    int otvet;
    getlist("a.txt",a);
    printarray(a);
    printf("\n");
    otvet=solve(a);
    printarray(a);
    printf("\n\nOtvet=%d",otvet);
    return 0;
}
