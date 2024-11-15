def solution(n, data):
    max_x, max_y = 1, 1
    max_product = -1
    current_product = 1
    curr_x, curr_y = 1, 1
    for i in range(n):
        if data[i] == 0:
            current_product = 1
            curr_x = i + 2
            curr_y = i + 2
        else:
            current_product *= data[i]
            curr_y = i + 1
            if current_product > max_product:
                max_product = current_product
                max_x = curr_x
                max_y = curr_y
    return [max_x, max_y]
            

if __name__ == "__main__":
    # Add your test cases here
    print(solution(5, [1, 2, 4, 0, 8]) == [1, 3])
    print(solution(7, [1, 2, 4, 8, 0, 256, 0]) == [6, 6])
