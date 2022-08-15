#include <stdio.h>
#include <ctype.h>
#include "tree.h"

// создание дерева
tnode *tree_create(Item a)
{
    tnode *newNode = (tnode *)malloc(sizeof(tnode));
    newNode->data = a;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// удаление дерева
void tree_destroy(tnode *tree)
{
    if (!tree)
    {
        return;
    }
    if (tree->left)
    {
        tree_destroy(tree->left);
    }
    if (tree->right)
    {
        tree_destroy(tree->right);
    }
    free(tree);
    tree = NULL;
}

// добавление элементов к дереву
void tree_add(tnode *a, Item b)
{
    if (b == NULL)
        return;
    if (a->left)
    {
        tnode *new1 = tree_create(b);
        new1->right = a->left;
        a->left = new1;
    }
    else
        a->left = tree_create(b);
}

void tree_add_node(tnode *a, tnode *b)
{
    if (b == NULL)
        return;
    if (a->left)
    {
        b->right = a->left;
        a->left = b;
    }
    else
        a->left = b;
}

// поиск по значению в дереве
tnode *tree_find(tnode *a, Item b)
{
    if (a == NULL)
        return NULL;
    if (a->data == b)
        return a;
    tnode *chld1 = tree_find(a->left, b);
    if (chld1)
        return chld1;
    tnode *nxt1 = tree_find(a->right, b);
    if (nxt1)
        return nxt1;
    return NULL;
}

// поиск родителя дерева
tnode *tree_parent_find(tnode *a, tnode *b)
{
    if (a == NULL)
        return NULL;
    if (a->left == b || a->right == b)
        return a;
    tnode *chld1 = tree_parent_find(a->left, b);
    if (chld1 != NULL)
        return chld1;
    tnode *nxt1 = tree_parent_find(a->right, b);
    if (nxt1 != NULL)
        return nxt1;
    return NULL;
}

// удаление ячейки из дерева
void tree_delete(tnode *a, tnode *b)
{
    tnode *par1 = tree_parent_find(a, b);
    if (par1->left == b)
        par1->left = b->right;
    else
        par1->right = b->right;
    tree_destroy(b->left);
    free(b);
}

// подсчет количества слагаемых или сомножителей на уровне level
int element_count_on_level = 0;

// вспомогательная рекурсивная функция распечатки
void tree_print_int(tnode *a, int b, int k)
{
    int i;
    if (a == NULL)
        return;

    for (i = 0; i < b; i++)
        printf("\t");

    printf("%s\n", a->data);

    if (i == k)
    {
        if (isdigit(a->data[0]) || isalpha(a->data[0]))
        {
            element_count_on_level++; //!
        }
    }
    printf("                                       %s i=%d\n", a->data, i); //!

    tree_print_int(a->left, b + 1, k);
    tree_print_int(a->right, b, k);
}

// ((2+x)-(x*3))-((x-2)*(3+y))

// распечатка дерева
void tree_print(tnode *a, int k)
{
    tree_print_int(a, 0, k);

    printf("\nThe number of factors and summands at the k-th level of the tree: %d\n", element_count_on_level); //!
}

int is_operator(char c)
{
    if (c == '*' || c == '+' || c == '-')
        return 1;
    else
        return 0;
}
