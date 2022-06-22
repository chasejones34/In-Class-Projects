import turtle

def koch(t, length):
    if length < 3:
        t.fd(length)
        return
    koch(t, length/3)
    t.lt(60)
    koch(t, length/3)
    t.rt(120)
    koch(t, length/3)
    t.lt(60)
    koch(t, length/3)

def snowflake(t, length):
    koch(t, length)
    t.rt(120)
    koch(t, length)
    t.rt(120)
    koch(t, length)
    t.rt(120)


turt = turtle.Turtle()
turt.hideturtle()
turtle.tracer(0,0)
turt.up()
turt.setpos(-150, 150)
turt.down()
snowflake(turt, 300)
turtle.mainloop()