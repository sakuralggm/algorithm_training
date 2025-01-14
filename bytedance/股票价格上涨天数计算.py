# 题解：https://bytedance.larkoffice.com/docx/ZjixdJfDkoTT68xSVSScxf3tnP7
def solution(N, stockPrices):
    ans = [0] * N
    st = []
    for i, v in enumerate(stockPrices):
        while st and stockPrices[st[-1]] < v:
            idx = st.pop() # 对于此时栈顶的元素arr[st[-1]]，如果arr[st[-1]] < arr[i]，则说明arr[i]是其第一个在arr[st[-1]]右边且比arr[st[-1]]大的元素
            ans[idx] = i - idx
        st.append(i)
    return ans

if __name__ == '__main__':
    print(solution(5, [33, 34, 14, 12, 16]) == [1, 0, 2, 1, 0])
    print(solution(6, [45, 44, 46, 43, 42, 48]) == [2, 1, 3, 2, 1, 0])
    print(solution(3, [10, 9, 8]) == [0, 0, 0])