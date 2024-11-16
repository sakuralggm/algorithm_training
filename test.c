#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int k1;
    int k2;
    int left;
    int right;
} TreeNode;

TreeNode tree[1010];
int state[1010];
int flg;

int max(int a, int b) // 求两个数的最大值
{
    return a > b ? a : b;
}
int min(int a,int b)//求两个数的最小值
{
    return a < b ? a : b;
}

// int MAX(int node) // 找node结点的子树里面k2的最大值
// {

//     // if (node < 0)
//     //     return -1000000;
//     int left = tree[node].left;
//     int right = tree[node].right;

//     if (left == -1 && right == -1)
//         return tree[node].k2;
//     if (left == -1)
//         return max(MAX(right), tree[node].k2);
//     if (right == -1)
//         return max(MAX(left), tree[node].k2);
//     else
//         return max(MAX(left), max(MAX(right), max(MAX(left), tree[node].k2)));
// }

int MAX2(int node) {
    if (node < 0)
        return -1000000000; 

    int leftMax = MAX2(tree[node].left);
    int rightMax = MAX2(tree[node].right);

    return max(tree[node].k2, max(leftMax, rightMax));
}
int MIN1(int node){
    if (node < 0)
        return 1000000000;
    
    int leftMin=MIN1(tree[node].left);
    int rightMin=MIN1(tree[node].right);

    return min(tree[node].k1,min(leftMin,rightMin));
}
int MAX1(int node)
{
    if (node < 0)
        return -1000000000; 

    int leftMax = MAX1(tree[node].left);
    int rightMax = MAX1(tree[node].right);

    return max(tree[node].k1, max(leftMax, rightMax));
}


void IsRight(int node)
{
    if (node < 0)
        return;
    if (flg == 1)
        return;

    int left = tree[node].left;
    int right = tree[node].right;

    if (left != -1 && tree[node].k2 >= MAX2(left))
        flg = 1;
    if (right != -1 && tree[node].k2 >= MAX2(right))
        flg = 1;

    IsRight(left);
    IsRight(right);

}

void IsLeft(int node)
{
    if (node < 0)
        return;
    if (flg == 1)
        return;
    // 退出

    // if (tree[node].k1 <= min || tree[node].k1 >= max)
    //     flg = 1;
    // IsLeft(tree[node].left, min, tree[node].k1); // 左子树应该满足k1值大于其左子树的k1,小于父母结点的k1
    // IsLeft(tree[node].right, tree[node].k1, max);
    // // 右子树应该满足k1值大于父母结点的k1,小于其右子树的k1

    int left = tree[node].left;
    int right = tree[node].right;

    if (left != -1 && tree[node].k1 <= MAX1(left))
        flg = 1;
    if (right != -1 && tree[node].k1 >= MIN1(right))
        flg = 1;

    IsLeft(left);
    IsLeft(right);

}

int main() 
{
    int n;

    // 建立二叉树
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d %d %d", &tree[i].k1, &tree[i].k2, &tree[i].left, &tree[i].right);
        if (tree[i].left != -1)
            state[tree[i].left] = 1;
        if (tree[i].right != -1)
            state[tree[i].right] = 1;
    }

    // 找出根节点
    int root;
    for (int i = 0; i < n; i++)
    {
        if (state[i] == 0)
            root = i;
    }

    // 判断并输出结果
    IsLeft(root);
    IsRight(root);

    if (flg)
        printf("NO\n");
    else
        printf("YES\n");

    return 0;
}