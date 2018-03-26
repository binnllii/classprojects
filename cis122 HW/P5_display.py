def nice_int(number, width):
    '''Return fixed width string showing number eg.'12,345'''
    f = str(width) + ',d'
    result = format(number,f)
    return result
#Test me
number = 100000
your_int = nice_int(number, 9)
print(your_int)



def nice_float(number, width, decimals):
    '''Return fixed width string showing number with decimals EG. 12,345.67'''
    f = format(number, str(width) + ',.' + str(decimals) + 'f')
    return f

number = 13400.45
your_int = nice_float(number, 10, 2)
print(your_int)


def nice_left_str(string, width):
    show_str = string.ljust(width)
    return show_str

    
    
your_int = nice_int(2475, 2)
sales = 45678.00
show_sales = nice_float(sales, 12, 2)
state = "Oregon"
show_state = nice_left_str(state, 17)
print("2", show_state, your_int, show_sales)

your_int = nice_int(3450, 2)
sales = 12956.00
show_sales = nice_float(sales, 12, 2)
state = "Utah"
show_state = nice_left_str(state, 16)
print("12", show_state, your_int, show_sales)

your_int = nice_int(178, 2)
sales = 4567.33
show_sales = nice_float(sales, 12, 2)
state = "North Carolina"
show_state = nice_left_str(state, 18)
print("48", show_state, your_int, show_sales)





