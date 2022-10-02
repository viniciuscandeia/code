
static int max(int a, int b)
{
    return a > b ? a : b;
}

AVLTree *avl_tree_create(void)
{
    AVLTree *tree = malloc(sizeof *tree);
    if (tree == NULL)
        return NULL;
    tree->root = NULL;
    return tree;
}

static int node_height(AVLNode *node)
{
    if (node == NULL)
        return -1;
    return node->height;
}

static void update_node_height(AVLNode *node)
{
    if (node == NULL)
        return;
    node->height = 1 + max(node_height(node->left), node_height(node->right));
}

AVLNode *avl_tree_create_node(char info, AVLNode *left, AVLNode *right)
{
    AVLNode *node = malloc(sizeof *node);
    if (node == NULL)
        return NULL;
    node->info = info;
    node->left = left;
    node->right = right;
    update_node_height(node);
    return node;
}

static AVLNode *node_search(AVLNode *node, char info)
{
    if (node == NULL)
        return NULL;
    if (node->info > info)
        return node_search(node->left, info);
    else if (node->info < info)
        return node_search(node->right, info);
    else
        return node;
}

AVLNode *search(AVLTree *tree, char info)
{
    if (tree == NULL)
        return NULL;
    return node_search(tree->root, info);
}

static AVLNode *rotate_right(AVLNode *p)
{
    AVLNode *u = p->left;
    AVLNode *T2 = u->right;
    u->right = p;
    p->left = T2;
    update_node_height(p);
    update_node_height(u);
    return u;
}

static AVLNode *rotate_left(AVLNode *p)
{
    AVLNode *z = p->right;
    AVLNode *T2 = z->left;
    z->left = p;
    p->right = T2;
    update_node_height(p);
    update_node_height(z);
    return z;
}

static int node_balance(AVLNode *node)
{
    if (node == NULL)
        return 0;
    return node_height(node->left) - node_height(node->right);
}

static void balance_node(AVLNode *p)
{
    int balance = node_balance(p);
    if (balance > 1)
    {
        int u_balance = node_balance(p->left);
        if (u_balance > 0)
            return rotate_right(p);
        else if (u_balance < 0)
            p->left = rotate_left(p->left);
        return rotate_right(p);
    }
    else if (balance < -1)
    {
        int z_balance = node_balance(p->right);
        if (z_balance > 0)
        {
            p->right = rotate_right(p->right);
            return rotate_left(p);
        }
        else if (z_balance < 0)
            return rotate_left(p);
    }
    return p;
}

static AVLNode *node_insert(AVLNode *node, char info)
{
    if (node == NULL)
        node = avl_tree_create_node(info, NULL, NULL);
    else if (node->info > info)
    {
        AVLNode *left = node_insert(node->left, info);
        if (left == NULL)
            return NULL;
        node->left = left;
    }
    else if (node->info < info)
    {
        AVLNode *right = node_insert(node->right, info);
        if (right == NULL)
            return NULL;
        node->right = right;
    }
    update_node_height(node);
    balance_node(node);
    return node;
}

int avl_tree_insert(AVLTree *tree, char info)
{
    AVLNode *node = node_insert(tree->root, info);
    if (node == NULL)
        return FAILURE;
    tree->root = node;
    return SUCCESS;
}

static AVLNode *node_remove(AVLNode *node, char info, int *res)
{
    if (node == NULL)
    {
        *res = FAILURE;
        return NULL;
    }
    if (node->info > info)
    {
        AVLNode *left = node_remove(node->left, info, res);
        if (*res == FAILURE)
            return NULL;
        node->left = left;
    }
    else if (node->info < info)
    {
        AVLNode *right = node_remove(node->right, info, res);
        if (*res == FAILURE)
            return NULL;
        node->right = right;
    }
    else
    {
        if (node->left == NULL && node->right == NULL)
        {
            free(node);
            node = NULL;
        }
        else if (node->left == NULL)
        {
            AVLNode *aux = node;
            node = node->right;
            free(aux);
        }
        else if (node->right == NULL)
        {
            AVLNode *aux = node;
            node = node->left;
            free(aux);
        }
        else
        {
            AVLNode *successor = node->left;
            while (successor->right != NULL)
                successor = successor->right;
            node->info = successor->info;
            successor->info = info;
            node->left = node_remove(node->left, info, res);
        }
    }
    *res = SUCCESS;
    update_node_height(node);
    balance_node(node);
    return node;
}

int avl_tree_remove(AVLTree *tree, char info)
{
    int res = SUCCESS;
    AVLNode *node = node_remove(tree->root, info, res);
    if (res == FAILURE)
        return FAILURE;
    tree->root = node;
    return SUCCESS;
}

typedef struct avlNode AVLNode;

struct avlNode
{
    int height;
    char info;
    AVLNode *right;
    AVLNode *left;
};

typedef struct avlTree AVLTree;

struct avlTree
{
    AVLNode *root;
};

AVLTree *avl_tree_create(void);

AVLNode *avl_tree_create_node(char info, AVLNode *left, AVLNode *right);
AVLNode *tree_search(AVLTree *tree, char info);

int avl_tree_insert(AVLTree *tree, char info);
int avl_tree_remove(AVLTree *tree, char info);