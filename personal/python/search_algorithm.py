# exploring an algorithm to find a random numer n between 0 and m

from random import randint as ri

from numpy import average

def algorithm(n: int, m: int) -> None:
    '''
    Args:
        n (int): The number to search.
        m (int): The max range to search, between 1 and m.
    
    This algorithm checks a middle point, then exclude a segument 
    at the side of this point, releative to n, then check the 
    middle point of the opposite segment, until n is found.
    '''

    if n>m: 
        print("n can't be bigger than m. Try again.")
        return 0
    if n<=0:
        print("n must be bigger than 0. Try again.")
        return 0

    current: int = 0
    i: int = 0;
    visited: list[int] = []

    while current != n:

        i += 1
        upd = max(1, m//2 ** i)

        if current > n: current -= upd
        if current < n: current += upd
        if current in visited: current -= upd//2

        visited.append(current)

    return i
    

def manual() -> None:
    '''
    In manual mode, m and n are provided manually.
    Output is the number of iterations taken to find n between 1 and m.
    '''
    m = int(input('Maximum m value: '))
    n = int(input('Number n to search: '))
    
    i = algorithm(n,m)
    if i:
        print(f"Number {n} was found after {i} iterations.")

def auto() -> None:
    '''
    In auto mode, m and t are provided manually, and n is choosen randomly.
    Output is the average number of iterations to find t random n values between 1 and m. 
    '''
    m = int(input('Maximum m value: '))
    t = int(input('Number of tries: '))
    i_list = []
    for _ in range(t):
        n = ri(0, m)
        i = algorithm(n, m)
        if i:
            i_list.append(i)
    print(f'The average of iterations for {m=} and {t=} is {average(i_list)}')

def main() -> None:
    while True:
        print('1. manual')
        print('2. auto')
        op = input()
        if op=='1': manual()
        if op=='2': auto()

if __name__ == "__main__":
    main()




