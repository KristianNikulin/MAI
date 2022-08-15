#ifndef TREE_H
#define TREE_H

#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef char *Item;

typedef struct tnode tnode;

struct tnode
{
    Item data;
    tnode *left;
    tnode *right;
};

tnode *tree_create(Item);
void tree_destroy(tnode *);
void tree_add_node(tnode *a, tnode *b);
void tree_add(tnode *, Item);
tnode *tree_find(tnode *, Item);
void tree_delete(tnode *, tnode *);
void tree_print(tnode *, int k);
int elements_count(tnode *cur, tnode *parent, int level, int i);

#endif