import turtle as t


size = 20
angle = 360 / 4
nudge = 4.7
bump = 5

t.pencolor('red')
t.pensize(3)
t.speed('fastest')



color_list = [
    'color1 = input("Please input first color")'
    'color2 = input("Please input second color")'
    'color3 = input("Please input third color")']
#               0        1          2


for count in range(60):
    t.fillcolor(color_list[count%3])
    t.begin_fill()
    for sides in range(4):
       t.forward(size)
       t.left(angle)
    t.end_fill()
    size = size + 4
    t.right(nudge)
    t.forward(bump)
