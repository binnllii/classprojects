# P8_1_unending.py

# Help - when I run this program it keeps going and going...


my_list = ['Jim', 'Ashley', 'Amanda', 'Zelda']

# Add more names

hint = "Type Q to quit or first name to add (such as Anne): "
name = input(hint).title()
while name != 'Q':
    my_list.append(name)
    print("Added", name)
    #to stop the function from going ang going, i pasted the "hint = "Type Q to quit or first name to add (such as Anne): "
#name = input(hint).title()" into the while loop so it will ask for a input again.
    hint = "Type Q to quit or first name to add (such as Anne): "
    name = input(hint).title()
#deleted print(my_list)
#to put the list in seperate lines, i added this.
for name in my_list:
    print(name)
