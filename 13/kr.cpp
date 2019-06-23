#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
class node
{
private:
    char*name;
    node*next;
public:
    node(const char*in){if(in)name=new char[strlen(in)+1];if(name) strcpy(name,in);next=0;}
    node(){name=0;next=0;}
    ~node(){if(name)delete[]name;next=0;}
    void add(node*a){next=a;}
    node* getend(){node*p=this;while(p->next)p=p->next;return p;}
    node* gnext(){return next;}
    int operator<(const node*a){return strcmp(this->name,a->name)>0;}
    char* gname(){return name;}
    node* delel (node* head,node* curr)
    {
        node* tail=getend();
        if(curr!=head&&curr!=tail)
        {
            node* tmp=head;
            while(tmp->next!=curr)
                tmp=tmp->next;
            if(tmp->next)tmp->next=tmp->next->next;
		tmp=tmp->next;

		delete curr;
		curr=tmp;
		return curr;


        } else
        {
            if(curr==tail)
            {
                node* tmp=head;

                while (tmp->next!=tail)
                    tmp=tmp->next;
                    tmp->next=0;
                    delete curr;
                curr=tmp;
                return curr;

            }else{
           node* tmp;
           tmp=head->next;

		delete head;
           head=tmp;
           return head;
            }

        }
    }
    void swap (node* a,node* b)
    {
        char* s=a->name;
        a->name=b->name;
        b->name=s;
    }
};
node* getlist(const char*name);
void print(node*beg);
void del(node*beg);
int Fun(node*beg,int k);
int Fun1(node*beg,int k)
{
    node*c=beg,*p=beg;
    for(int i=0;i<k;i++)
    {
        c=c->gnext();
        if(c==0) c=beg;
    }
    print(c);
    while(p!=c) {printf("%s\n",p->gname());p=p->gnext();}
return 0;
}
node* Fun2 (node* beg, char* s)
{
    node* head=beg->gnext();
    while(head)
    {
        if(strcmp(head->gname(),s)<0)
            head=head->delel(beg,head);
        else head=head->gnext();

    }
    head=beg;
    if(strcmp(beg->gname(),s)<0)
            head=head->delel(beg,head);
    beg=head;
    return beg;
}
/*node* Fun3(node* beg)
{
    node* head=beg->gnext();
    while(head->gnext())
    {
        if(strcmp(head->gprev()->gname(),head->gname())<0&&strcmp(head->gname(),head->gnext()->gname())<0)
            {head=head->delel(beg,head);}
        else {head=head->gnext();}
    }

    return beg;

}*/
void del(node*beg)
{
    node*p=beg,*q=p;
    while(p)
    {
        p=q->gnext();
        delete q;
        q=p;
    }
}
void print(node*beg)
{
    node*c=beg;
    int i=0;
    while(c&&(i++)<15)
    {
        printf("%s\n",c->gname());
        c=c->gnext();
    }
}
void delnewline(char* buf)
{
    int i;
    for(i=0;buf[i];i++)
        if (buf[i]=='\n')
        {
            buf[i]=0;
            break;
        }
}
node* getlist(const char*name)
{
    FILE *fp;
    node *p,*q,*beg;
    char buf[1000];
    fp=fopen(name,"r");

    if(fgets(buf,1000,fp)) {delnewline(buf); beg=new node(buf);}
    else return 0;
    p=beg;
    q=beg;
    while(fgets(buf,1000,fp))
    {
        delnewline(buf);
        p=new node(buf);
        if(!q) break;
        if(q&&p)q->add(p);
        q=p;
    }
    fclose(fp);
    return beg;
}
int main()
{
    node*beg=0;
    node*tmp=0;
    int k;
    char s[1000];
    FILE* fp;
    fp=fopen("s.txt","r");
    if(fscanf(fp,"%s",s)!=1) return -1;
    printf("%s\n",s);
    //scanf("%d",&k);
    beg=getlist("str.txt");
    printf("List before:\n");
    print(beg);
    printf("List after:\n");
    beg=beg->delel(beg,beg);
    tmp=beg->gnext();
   // printf("%s\n",tmp->gname());
    tmp=tmp->delel(beg,tmp);
    tmp=tmp->getend();
    tmp=tmp->delel(beg,tmp);
    printf("%s\n",tmp->gname());
    //beg=Fun2(beg,s);
    //node* c=beg->gnext();
   // c=c->delel(beg,c);
    //printf("%s\n",c->gname());
    print(beg);
    del(beg);
}
