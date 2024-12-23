def solution(inputArray):
    inputArray.sort()  # list的比较大小方法就是从第一个元素开始比较，如果第一个元素相等，就比较第二个元素，以此类推
    ans = 0
    st, ed = inputArray[0]
    for begin, end in inputArray[1:]:
        if begin > ed:
            ans += ed - st + 1
            st, ed = begin, end
        else:
            ed = max(ed, end)
    ans += ed - st + 1
    return ans


if __name__ == "__main__":
    #  You can add more test cases here
    testArray1 = [[1, 4], [7, 10], [3, 5]]
    testArray2 = [[1, 2], [6, 10], [11, 15]]

    print(solution(testArray1) == 9)
    print(solution(testArray2) == 12)
