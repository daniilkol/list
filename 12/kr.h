#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

class node
{
private:
    char*name;
    node*next,*prev;
public:
    node(const char*in){if(in)name=new char[strlen(in)+1];if(name) strcpy(name,in);next=0;prev=0;}
    node(){name=0;next=prev=0;}
    ~node(){if(name)delete[]name;next=0;prev=0;}
    void add(node*a){if(a){a->prev=this;next=a;}}
    node* getend(){node*p=this;while(p->next)p=p->next;return p;}
    node* gnext(){return next;}
    node* gprev(){return prev;}
    int operator<(const node*a){return strcmp(this->name,a->name)>0;}
    char* gname(){return name;}
    node* delel (node* head,node* curr)
    {
        if(curr->next&&curr->prev)
        {

                node*p=curr->next;
                p->prev=curr->prev;
                curr->prev->next=p;
                curr->next=0;
                curr->prev=0;
                delete curr;
                curr=p;
                return curr;
        }else if(curr->next)
                {
                    curr=curr->next;
                    head->next=0;
                    curr->prev=0;
                    delete head;
                    head=curr;
                    return curr;
                } else if(curr->prev)
                        {
                            node *p=curr;
                            curr=curr->prev;
                            p->prev=0;
                            delete p;
                            curr->next=0;
                            return curr;
                        }else
                            {
                                delete curr;
                                head->next=0;
                                head->prev=0;
                                head=curr=0;
                                return curr;
                           }
    }
    void swap (node* a,node* b)
    {
        char* s=a->name;
        a->name=b->name;
        b->name=s;
    }
};
