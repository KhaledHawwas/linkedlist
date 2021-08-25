#include<stdio.h>
#include<time.h>
typedef int link_t ;
struct linkedlist {
    link_t val;
    struct linkedlist *next;
};
typedef struct linkedlist linkedlist;

//get list length
int getlen(linkedlist *head) {
    if(head==NULL)
        return 0;
    int re=1;
    linkedlist * lastmem= head;
    while(lastmem->next!=NULL) {
        lastmem=lastmem->next;
        re++;
    }
    return re;

}

//add a new member to memory and set is's val
//and link it at end of list
//!!hint : you should set head pointer to NUll when you creat new head
void addnewmem(link_t val,linkedlist **head) {
    //creat new member{
    linkedlist * s ;
    s=(linkedlist *)malloc(sizeof (linkedlist));
    s->val=val;
    //}
    if(*head!=NULL) {//set head to new member
        linkedlist * lastlist= *head;
        while(lastlist->next!=NULL) //got to last member
            lastlist=lastlist->next;
        linkmem(s,lastlist);//link new member
    } else {///if head == null head will be the new member
        *head=s;
        (*head)->next=NULL;
    }
}
//link two member
void  linkmem(linkedlist *newmem, linkedlist * lastmem) {
    newmem->next=NULL;
    if(lastmem !=NULL) {
        lastmem->next=newmem;
    }
}

//print list
void printll(struct linkedlist * head) {
    struct linkedlist * thislist= head;
    while(1) {
        printf("%i",thislist->val);
        if(thislist->next!=NULL) {
            printf(" -> ");
            thislist=thislist->next;
        } else {
            return ;
        }
    }
}


//get member at index
// return  null if index is greater than size
linkedlist* getat(linkedlist* head,int index) {
    if(head==NULL) {
        return NULL;
    }
    linkedlist *re =head;
    while(re->next!=NULL) {

        re=re->next;
        index--;
        if(index<=0) {
            return re;
        }
    }
    return NULL;//out of index
}
//move all member left if steps>0 else right ex -->
//0 -> 1 -> 2 -> 3 -> 4 -> 5 steps=2
//2 -> 3 -> 4 -> 5 -> 0 -> 1
//0 -> 1 -> 2 -> 3 -> 4 -> 5 steps=-2
//4 -> 5 -> 0 -> 1 -> 2 -> 3
void moveall(linkedlist **head,int steps) {
    if(steps==0) {
        return;
    }
    if(steps<0) {
        steps=getlen(*head)+steps;
    }
    linkedlist *l=getat(*head,steps-1);//this member will be last member
    linkedlist *l2=getat(*head,steps);//this member will set as head
    linkedlist *lastmem=getat(*head,getlen(*head)-1);
    l->next=NULL;
    lastmem->next=(*head);
    *head=l2;
}

//convert list to array
int listtoarray(linkedlist *head,link_t *arr,int n) {
    linkedlist*lastlist=head;
    if(head==NULL) {
        return 0;
    }
    int i=0;
    while(lastlist->next!=NULL&&n>=0) {
        arr[i]=lastlist->val;
        lastlist=lastlist->next;
        i++;
        n--;
    }
    arr[i]=lastlist->val;//last one
    return i;
}

//convert from array to liked list
void arraytolist(link_t *arr,int n,linkedlist **head) {
    for(int i=0; i<n; i++) {
        addnewmem(arr[i],head);
    }
}

//switch two member ex -->
//0->1->2->3->4->5   fromindex=1 toindex=3
//0->3->2->1->4->5
void movemem(linkedlist*head,int fromindex,int toindex) {
    int len=getlen(head);
    if(toindex>len||fromindex>len) {
        return ;
    }
    linkedlist*pfrom=getat(head,fromindex-1);//the member before from member
    linkedlist*pto=getat(head,toindex-1);//the member before to member
    linkedlist*from=getat(head,fromindex);
    linkedlist*to=getat(head,toindex);
    //0->1->2->3->4->5
    //0->1->4->3->2->5
    pfrom->next=to;
    pto->next=from;
    linkedlist*temp=from->next;
    from->next=to->next;
    to->next=temp;
}

//delete member by index
void deletemem(linkedlist *head,int index) {
    linkedlist *g=getat(head,index-1);
    linkedlist *delmem=getat(head,index);
    g->next=delmem->next;
    free(delmem);
}

//clear all list
void clearlist(linkedlist **head) {
    linkedlist*delmem= *head;//member which will  be romved
    linkedlist*next=delmem->next;//this pointer save next member
    while(next!=NULL) {
        free(delmem);
        delmem=next;
        next=next->next;
    }
    free(delmem);//last one
    *head=NULL;
}

//add at index
void addat(linkedlist *head,link_t val,int index) {
    linkedlist *newmem=(linkedlist *)malloc(sizeof(linkedlist));//creat new member
    linkedlist *g=getat(head,index);//set member pointer at index to new member
    newmem->val=val;
    newmem->next=g->next;
    g->next=newmem;
}

