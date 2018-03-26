import turtle as t
import random

def ask_for_int(hint):
    temp = input(hint+' ')
    value = int(temp)
    return value

def ask_for_float(hint):
    temp = input(hint+' ')
    value = float(temp)
    return value

def ask_for_str(hint):
    temp = input(hint+' ')
    value = str(temp)
    return value

def make_money(amount):
    amount = float(amount)
    amount = round(amount,2)
    return amount

def jump(distance):
    ''' moce to (x,y) without making a mark on screen'''
    t.penup()
    t.forward(distance)
    t.pendown()

def jump_to(x,y):
    t.penup()
    t.goto(x,y)
    t.pendown()

hint= "Input a number:"
your_int = ask_for_int(hint)
your_int = your_int + 1
print("You entered", your_int, "next number is", your_int + 1)

hint= "Enter a decimal number with 3 decimals"
your_amount = ask_for_float(hint)
money = make_money(your_amount)

hint = "Type your first name: "
your_name = ask_for_str(hint)


print(your_name, "-- money value of", your_amount, "is", money)
