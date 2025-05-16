# simple game about guessing a number between 0 and 100
# try binary searching!

from random import randint
import os



def clear() -> None:
    os.system('cls' if os.name=='nt' else 'clear')

class Game:
    def __init__(self, n):
        self.secret_number: int = n
        self.tries: int = 0
        self.current_guess: int = -1
    
    def guess(self) -> None:
        while True:
            try:
                self.current_guess = int(input('enter your guess:\n'))
                break
            except ValueError:
                print('input a number, please.\n')
                continue
        return(self.current_guess)
    
    def round(self) -> int:
        while self.current_guess != self.secret_number:
            self.current_guess = self.guess()
            self.tries += 1
            clear()
            print('Secret number is', 
                  'below' if self.current_guess > self.secret_number else 'above', 
                  f'{self.current_guess}!')
        print(f'You win! Secret number was {self.secret_number}')
        return self.tries

def play() -> None:
    secret_number: int = randint(0,100)
    current_game: Game = Game(secret_number)
    score: int = current_game.round()
    return score

def main() -> None:
    max_score = 0
    print('enter to play')
    while not input():
        clear()
        score = play()
        max_score = max(score, max_score)
        print(f'max score: {max_score} tries.')
        print('enter to play again')


if __name__ == '__main__':
    clear()
    main()
