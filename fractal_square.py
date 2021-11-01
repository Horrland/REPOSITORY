import turtle as tl
import math

def square_making(side):
    if side > 2:
        tl.pensize(math.sqrt(math.sqrt(side)))
        for i in range(4):    
            tl.forward(side)
            tl.right(90)
        tl.forward(side/2)
        tl.right(45)
        side *= 0.707107
        square_making(side)

side = 700
tl.color('orange')
tl.bgcolor('black')
tl.pensize(2.5)
tl.penup()
tl.goto(-side/2, side/2)
tl.pendown()

square_making(side)
tl.done()
