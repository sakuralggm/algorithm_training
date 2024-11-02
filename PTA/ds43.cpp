// 先求先序序列，然后根据层次排序一下，再输出排序后的结果就是层序遍历的结果
#include <stdio.h>

int post[40], in[40];
typedef struct
{
    int node;
    int c;
} tree;
tree re[40];
int idx;

void sort()
{
    for (int k = 0; k < idx - 1; k++)
    {
        for (int j = 0; j < idx - 1 - k; j++)
        {
            if (re[j].c > re[j + 1].c)
            {
                int t = re[j].node;
                re[j].node = re[j + 1].node;
                re[j + 1].node = t;
                int p = re[j].c;
                re[j].c = re[j + 1].c;
                re[j + 1].c = p;
            }
        }
    }
}

int find(int postL, int postR, int inL, int inR)
{
    for (int i = postR; i >= postL; i--)
        for (int j = inL; j <= inR; j++)
        {
            if (in[j] == post[i])
                return i;
        }
}

void fun(int postL, int postR, int inL, int inR, int c)
{
    if (inL > inR)
        return;

    int root = post[postR]; // 根节点
    re[idx].node = root; // 根节点
    re[idx++].c = c;

    int i = inL;
    for (; i <= inR; i++)
    {
        if (in[i] == root)
            break;
    }

    fun(postL, postL + i - inL - 1, inL, i - 1, c + 1); // 左子树的后序遍历区间和中序遍历区间
    fun(postL + i - inL, postR - 1, i + 1, inR, c + 1); // 右子树的后序遍历区间和中序遍历区间
}

int main()
{
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        scanf("%d", &post[i]);
    for (int i = 0; i < N; i++)
        scanf("%d", &in[i]);

    fun(0, N - 1, 0, N - 1, 0);

    sort();

    for (int i = 0; i < N - 1; i++)
        printf("%d ", re[i].node);
    printf("%d\n", re[N - 1].node);
    return 0;
}