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
        if(curr!=head)
        {
            node* tmp=head;
            while(tmp->next!=curr)
                tmp=tmp->next;
            if(tmp->next)tmp->next=tmp->next->next;
		tmp=tmp->next;

		delete curr;
		curr=tmp;


        } else
        {
           node* tmp;
           tmp=head->next;

		delete head;
           head=tmp;

        }
    }
    void swap (node* a,node* b)
    {
        char* s=a->name;
        a->name=b->name;
        b->name=s;
    }
};
