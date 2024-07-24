int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    int N, M, K; // 精灵球数量，初始体力值，小精灵数量
    cin >> N >> M >> K;
    memset(f, 0x3f, sizeof f); // 求最小值，初始化为最大

    f[0][0] = 0; // 边界
    for (int i = 1; i <= K; i++) // 从前i个小精灵中选
    {
        int num, injure; // 收服小精灵耗费的精灵球数量和体力值
        cin >> num >> injure;
        for (int j = M; j >= injure; j--) // 体力（代价1）
        {
            for (int k = K; k >= 1; k--) // 收服的数量（代价2），因为转移方程中有k-1，因此循环到1
            {
                f[j][k] = min(f[j][k], f[j - injure][k - 1] + num);
            }
        }
    }

    for (int i = K; i >= 0; i--)
    {
        dbg("f[%d][%d] = %d\n", M, i, f[M][i]);
    }

    int n = 0, m = 2e9; // 最多的数量和最小的体力值
    for (int i = K; i >= 0; i--)
    {
        if (f[M - 1][i] <= N)
        {
            n = i;
            for (int j = 0; j < M; j++)
            {
                if (f[j][i] == f[M - 1][i])
                {
                    m = min(m, j);
                }
            }
            break;
        }
    }
    cout << n << ' ' << m;
    return 0;
}