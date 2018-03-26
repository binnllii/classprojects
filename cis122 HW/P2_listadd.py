name_list = [ ]
stop = 'Quit'
name_hint = "Type 'Quit' or a name to add such as Bruce Lee:"
name = input(name_hint)
while name != stop:
    name_list.append(name)

    name = input(name_hint)

print( )

name_list.sort( )

n_name =len(name_list)
print("Name list has", n_name, "names")
print( )

for my_name in name_list:
    print(my_name)

print( )
print("----------")
print("Finished")


