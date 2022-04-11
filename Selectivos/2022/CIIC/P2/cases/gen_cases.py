import sys
import random
import time

def rand_case(n):
    return [random.randint(-100, 100) for _ in range(n)]


def solve(case):
    start = 0
    case = sorted(case)

    for m in case:
        if start >= m:
            start += 1
        else:
            break
    return start


def main():
    numcases = 5
    for i in range(numcases):
        n = random.randint(500, 1000)
        case = rand_case(n)
        start = time.time()
        solution = solve(case)
        end = time.time()
        print('N = {}, time = {}'.format(n, end - start))
        with open( 'case{}.in'.format(i), 'w') as f:
            print(len(case), file=f)
            for x in case:
                print(x, file=f)
        with open('case{}.out'.format(i), 'w') as f:
            print(solution, file=f)

    for i in range(numcases, 2*numcases):
        n = random.randint(1000000, 2000000)
        case = rand_case(n)
        start = time.time()
        solution = solve(case)
        end = time.time()
        print('N = {}, time = {}'.format(n, end - start))
        with open( 'case{}.in'.format(i), 'w') as f:
            print(len(case), file=f)
            for x in case:
                print(x, file=f)
        with open('case{}.out'.format(i), 'w') as f:
            print(solution, file=f)


if __name__ == '__main__':
    main()



