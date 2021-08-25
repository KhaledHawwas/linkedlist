//this file for examples
#include"linkedlist.h"
linkedlist *listhead;

//print static collection (head)
void printcol() {
    printf("list size:%i\n",getlen(listhead));
    printll(listhead);
    printf("\n");
}
int main(void) {
    //add member from 0 to 5
    for(int i=0; i<6; i++) {
        addnewmem(i,&listhead);
    }
    printf("list:");
    printll(listhead);
    //get member at index 4
    printf("\nmember at index 4:%i\n",getat(listhead,4)->val) ;
    //check out of index
    printf("member at index 6:");
    if(getat(listhead,6)==NULL) {
        printf("out of index\n");
    }
    //print list length
    printf("list length:%i\n",getlen(listhead));
    //move all member left 3 steps
    printf("list before move         :");
    printll(listhead);
    printf("\nlist after               :");
    moveall(&listhead,3);
    printll(listhead);
    //move all member left 3 steps
    printf("\nlist before move to left :");
    printll(listhead);
    printf("\nlist after               :");
    moveall(&listhead,-3);
    printll(listhead);
    //conver list to array
    int arr[6];
    listtoarray(listhead,arr,6);
    printf("\nto array :");
    for(int i=0; i<6; i++) {
        printf("%i ",arr[i]);
    }
    //array to list
    printf("\narray to list:");
    linkedlist *newhead=NULL;
    arraytolist(arr,6,&newhead);
    printll(newhead);
    //switch between 1,3
    movemem(listhead,2,4);
    printf("\nlist after switch:");
    printll(listhead);
    //delete member
    deletemem(listhead,3);
    printf("\ndelete 3:");
    printll(listhead);
    //add 3 to index 3
    printf("\nadd 3:");
    addat(listhead,3,3);
    printll(listhead);
    //clear list
    clearlist(&listhead);
    printf("\narray size after clear:%i",getlen(listhead));
    printf("\n");
    return 0;

}
 