import turtle
import math

def cesaro(t, length, angle):
    if length < 3:
        t.fd(length)
        return
    
    length = 1/2 * length / (1 + math.cos(angle*math.pi/180))
    cesaro(t, length, angle)
    t.lt(angle)
    cesaro(t, length, angle)
    t.rt(2*angle)
    cesaro(t, length, angle)
    t.lt(angle)
    cesaro(t, length, angle)

def cesaroFractal(t, length, angle):
    cesaro(t, length, angle)
    t.rt(90)
    cesaro(t, length, angle)
    t.rt(90)
    cesaro(t, length, angle)
    t.rt(90)
    cesaro(t, length, angle)
    t.rt(90)

turt = turtle.Turtle()
turt.hideturtle()
turtle.tracer(0,0)
turt.up()
turt.setpos(-150, 150)
turt.down()
cesaroFractal(turt, 300, 75)
turtle.mainloop()
