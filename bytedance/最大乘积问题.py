# 题解：https://bytedance.larkoffice.com/docx/JNzgdNYITosd7oxvIqWcWcWnn8g
def solution(n, array):
    left, right = [0] * n, [0] * n
    stk = []
    for i in range(n):
        while stk and array[stk[-1]] <= array[i]:
            t = stk.pop()
            if (array[t] < array[i]):
                right[t] = i + 1 # 单调栈，如果当前元素比栈顶元素大，则栈顶元素的右边第一个比它大的元素就是当前元素（加1是题目需要），掌握这个技巧，就可以在一次遍历中同时找到左右两边第一个比当前元素大的元素，而不需要两次遍历。
        if stk:
            left[i] = stk[-1] + 1 # 单调栈，找到左边第一个比当前元素大的元素（加1是题目需要）
        stk.append(i)
    return max(left[i] * right[i] for i in range(n))


if __name__ == "__main__":
    # Add your test cases here

    print(solution(5, [5, 4, 3, 4, 5]) == 8)
    # left = [0, 1, 2, 1, 0] right = [0, 5, 4, 5, 0]
    print(solution(6, [2, 1, 4, 3, 6, 5]) == 15)
    print(solution(7, [1, 2, 3, 4, 5, 6, 7]) == 0)
