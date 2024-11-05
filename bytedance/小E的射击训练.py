from math import ceil, sqrt
def solution(x: int, y: int) -> int:
    # 计算与(0,0)的欧式距离
    distance =  sqrt(x * x + y * y)
    # 距离上取整， ceil
    distance = ceil(distance)
    if distance > 11:
        return 0
    else:
        return 11 - distance
    
    

if __name__ == '__main__':
    print(solution(1, 0) == 10)
    print(solution(1, 1) == 9)
    print(solution(0, 5) == 6)
    print(solution(3, 4) == 6)