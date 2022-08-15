#include <stdio.h>
#include <stdlib.h>

// Вариант 1: Является ли двоичное дерево AVL-деревом

void print_menu()
{
    printf("1) +   Добавить элемент\n");
    printf("2) p   Распечатать дерево\n");
    printf("3) -   Удалить элемент из дерева\n");
    printf("4) ?   Является ли дерево AVL-деревом\n");
    printf("0) 0   Для выхода из программы\n");
}

struct Node
{
    int item;
    struct Node *left;
    struct Node *right;
};

struct Node *createNode(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->item = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node *insertNode(struct Node *root, int value)
{
    if (root == NULL)
    {
        printf("\n");
        return createNode(value);
    }
    if (root->item > value)
    {
        root->left = insertNode(root->left, value);
    }
    else if (root->item < value)
    {
        root->right = insertNode(root->right, value);
    }
    return root;
}

struct Node *removeNode(struct Node *root, int value)
{
    if (root == NULL)
    {
        printf("Этого элемента нет в дереве!\n");
        return NULL;
    }
    if (value < root->item)
    {
        root->left = removeNode(root->left, value);
        return root;
    }
    if (value > root->item)
    {
        root->right = removeNode(root->right, value);
        return root;
    }
    struct Node *left = root->left;
    struct Node *right = root->right;

    if (left == NULL && right == NULL)
    {
        return NULL;
    }
    if (left != NULL && right != NULL)
    {
        struct Node *minNode = right;
        while (minNode->left != NULL)
        {
            minNode = minNode->left;
        }
        minNode->left = left;
        return right;
    }
    if (left != NULL)
    {
        return left;
    }
    if (right != NULL)
    {
        return right;
    }
}

void print(struct Node *root)
{
    if (root == NULL)
        return;

    print(root->left);
    printf("%d ", root->item);
    print(root->right);
}

void print2(struct Node *root, int n)
{
    if (root != NULL)
    {
        print2(root->left, n + 1);
        for (int i = 0; i < n; i++)
            printf("   ");
        printf("%d\n", root->item);
        print2(root->right, n + 1);
    }
}

int max_way(struct Node *tree, int len)
{
    len++;
    if (tree->right == NULL)
    {
        return len;
    }
    return max_way(tree->right, len);
}

int min_way(struct Node *tree, int len)
{
    len++;
    if (tree->left == NULL)
    {
        return len;
    }
    return min_way(tree->left, len);
}

int is_AVL(struct Node *tree)
{
    if (abs(min_way(tree, 0) - max_way(tree, 0)) > 1)
        return 0;
    if (tree->left != NULL)
        is_AVL(tree->left);
    if (tree->right != NULL)
        is_AVL(tree->right);
    return 1;
}

struct Node *parseCommand(char command, struct Node *root)
{
    int data;
    struct Node *leaf;

    switch (command)
    {
    case '+':
        scanf("%d", &data);
        root = insertNode(root, data);
        break;

    case '-':
        scanf("%d", &data);
        root = removeNode(root, data);
        break;

    case 'p':
        print2(root, 1);
        printf("\n\n");
        print(root);
        printf("\n\n");
        break;

    case '?':
        if (is_AVL(root))
        {
            printf("\nДА, это AVL-дерево\n");
        }
        else
        {
            printf("\nНЕТ, это не AVL-дерево\n");
        }
        break;
    }

    return root;
}

void DestroyTree(struct Node *tree)
{
    if (!tree)
    {
        return;
    }
    if (tree->left)
    {
        DestroyTree(tree->left);
    }
    if (tree->right)
    {
        DestroyTree(tree->right);
    }
    free(tree);
    tree = NULL;
}

int main()
{
    system("chcp 1251 > nul");

    print_menu();

    int fisrtNode;
    scanf("%d", &fisrtNode);
    struct Node *root = createNode(fisrtNode);
    char command;

    while (1)
    {
        scanf("%c", &command);

        if (command == '0')
        {
            break;
        }
        root = parseCommand(command, root);
    }
    DestroyTree(root);
}