from ast import main
import turtle

SPEED = 0

def draw1(t: turtle, pencolors: list[str]) -> None:
    color_count: int = len(pencolors)
    
    t = turtle.Turtle()
    for num in range(400):
        color_idx: int = num%color_count
        t.pencolor(pencolors[color_idx])
        t.forward(num+1)
        t.right(89)

    turtle.done

def draw2(pencolors: list[str]):
    colorcount: int = len(pencolors)


if __name__ == '__main__':
    op = input("choose draw (1,2,3,4): ")
    colors = input("choose pen colors: ").split()
    bgcolor = input("choose background color: ")

    # check if colors and bgcolor are valids
    
    turtle.speed(SPEED)

    match op:
        case '1': draw1(colors)
        case '2': draw2(colors)
        case '3': draw3(colors)
        case '4': draw4(colors)