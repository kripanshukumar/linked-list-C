#include "Linked_List.h"

int main(void)
{
    list *mylist;           //Creating List pointer
    mylist = createList(4); //Assigning the address of List Head with data
    appendList(mylist, 6);  //Appending List
    appendList(mylist, 9);  //Appending List
    appendList(mylist, 4);  //Appending List
    appendList(mylist, 1);  //Appending List

    insertElement(mylist, 2, 2); //Inserting Element in between

    printf("%d\n", search(mylist, 5)); //Searching Element in List

    printf("Transversed:%d, value found:%d\n", 5, listTransverse(mylist, 5)); // Transversing through list

    printlist(mylist); //Printing List Elements

    clearList(mylist); //Releasing the Resources when list no longer needed
    printlist(mylist); //Checking wether the deletion worked
}