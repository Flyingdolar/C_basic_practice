#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node{
    int num;
    char name;
    struct node *next;
    struct node *pre;
    
}node;

node* create_node(int a, char b, node* root){
    node* n;
    n = (node*)malloc(sizeof(node));
    n->num = a;
    n->name = b;
    n->pre = root;
    n->next = NULL;
    return n;
}

int main(int argc, char const *argv[])
{
    node* root;
    root = create_node(1, 'a', NULL);
    root->next = create_node(2,'b', root);
    root->next->next = create_node(3,'c', root->next);
    
    node* change;
    change = root;

    while(change->next != NULL){
        printf("%c %d\n", change->name, change->num);
        change = change->next;
    }
    printf("%c %d\n", change->name, change->num);
    return 0;
}
