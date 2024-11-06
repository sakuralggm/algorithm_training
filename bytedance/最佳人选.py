def solution(m, n, target, array):
    min_diff = float("inf")
    min_person = 'None'
    for i in range(0, len(array)):
        diff = 0
        for j in range(m):
            # 如果一个是A，一个是E，则diff为无穷大，BD\CE\BE也是一样的，只有这些情况是无穷大
            comb = array[i][j] + target[j]
            if comb == 'AE' or comb == 'BD' or comb == 'CE' or comb == 'BE' or comb == 'EC' or comb == 'DB' or comb == 'EA' or comb == 'EB':
                diff = float("inf")
                break
            else:
                diff += abs(ord(array[i][j]) - ord(target[j]))
        if diff < min_diff:
            min_diff = diff
            min_person = "".join(array[i])
        elif diff == min_diff:
            min_person = min_person + " " + "".join(array[i])
    if min_diff < float("inf"):
        return min_person
    else:
        return "None"
