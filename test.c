#include<stdio.h>
#include<stdlib.h>

struct node{

    int data;
    struct node *link;
};

struct node *head=malloc(sizeof(struct node));
int main()
{
    head->data=20;
    printf("Data is %d",head->data);
}