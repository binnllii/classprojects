import turtle as t

size = 20
angle = 360 / 4
nudge = 4.7
bump = 5


t.pencolor('red')
t.pensize(2)
t.speed('fastest')



for count in range(60):
    for sides in range(4):
       t.forward(size)
       t.left(angle)
       
    size = size + 4
    t.right(nudge)
    t.forward(bump)
