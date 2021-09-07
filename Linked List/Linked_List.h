#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

typedef struct list
{
    int size;
    int data;
    struct node *next;
} list;

list *createList(int value)
{
    list *obj = (list *)malloc(sizeof(list));
    obj->size = 1;
    obj->data = value;
    obj->next = 0;
    return obj;
}

void appendList(list *obj, int value)
{
    if (obj->size > 0)
    {
        if (obj->size == 1)
        {
            node *temp = (node *)malloc(sizeof(node));
            temp->data = value;
            temp->next = 0;
            obj->next = temp;
        }
        else
        {
            node *temp = obj->next;
            //int i = 0;
            while (temp->next != 0)
            {
                //printf("The index is:%d\n", i);
                temp = temp->next;
                //i++;
            }
            node *new = (node *)malloc(sizeof(node));
            new->data = value;
            new->next = 0;
            temp->next = new;
        }
        obj->size += 1;
    }
}

bool search(list *obj, int value)
{
    if (obj->size > 0)
    {
        if (value == obj->data)
        {
            return true;
        }
        else
        {
            node *temp = obj->next;
            while (temp != 0)
            {
                if (temp->data == value)
                {
                    return true;
                }
                else
                {
                    temp = temp->next;
                }
            }
        }
    }
    return false;
}

void printlist(list *obj)
{
    if (obj->size > 0)
    {
        //printf("The contents of the list are: \n[%d,", obj->data);
        printf("[%d,", obj->data);
        node *temp = obj->next;
        while (temp != 0)
        {
            printf("%d, ", temp->data);
            temp = temp->next;
        }
        printf("]\n");
    }
    else
    {
        printf("The list is empty\n");
    }
}

void clearList(list *obj)
{
    if (obj->size > 0)
    {
        node *new = obj->next;

        if (obj->size == 1)
        {
            free(obj);
            obj->size = 0;
            return;
        }
        else
        {
            while (new->next != 0)
            {
                node *temp;
                temp = new;
                new = new->next;
                free(temp);
            }
            free(new);
            free(obj);
            obj->size = 0;
        }
    }
}

int listTransverse(list *obj, int index)
{
    if (index < 0)
    {
        index = obj->size + index;
        //printf("The new index is %d\n", index);
    }
    if (index >= obj->size || index < 0)
    {
        printf("Index out of range of list\n");
        return NULL;
    }
    else
    {
        if (index == 0)
        {
            return obj->data;
        }
        else
        {
            node *temp = obj->next;
            int i = 1;
            while (i < index)
            {
                temp = temp->next;
                i++;
            }
            return temp->data;
        }
    }
}

bool insertElement(list *obj, int value, int index)
{
    if (obj->size > index & index >= 0)
    {
        node *new = (node *)malloc(sizeof(node));
        if (index == 0)
        {
            new->data = obj->data;
            new->next = obj->next;
            obj->next = new;
            obj->data = value;
        }
        else
        {
            node *temp = obj->next;
            for (int i = 1; i < index; i++)
            {
                temp = temp->next;
                if (new == 0)
                {
                    break;
                }
            }
            new->data = temp->data;
            temp->data = value;
            new->next = temp->next;
            temp->next = new;
        }
        obj->size++;
        return true;
    }
    else
    {
        printf("Can't perform insert. Index %d out of bound. List size is: %d\n", index, obj->size);
        return false;
    }
}