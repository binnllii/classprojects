def nice_int(number, width):
    fmt = str(width) + ',d'
    result = format(number, fmt)
    return result

def nice_float(number, width, decimal):
    fmt = str(width) + ',.' + str(decimal) + 'f'
    result = format(number, fmt)
    return result

def nice_str(string, width):
    result = string.ljust(width)
    return result

filename = 'state_data.txt'
states = [ ]
with open(filename, 'r', encoding='utf-8') as states_file:
    for line in states_file:
        line = line.strip( )
        if line [0] != '#':
            item_list = line.split(',')
            state = item_list[0].lower()
            capital = item_list[1].lower()
            area = int(item_list[2])
            pop = float(item_list[3])
            density = round(pop * 1000000 / area, 1)
            details_list = [state, capital, area, pop, density]
            states.append(details_list)
print("Debug")


state_width = 16
capital_width = 16
area_width = 10
pop_width = 8
decimal = 1

print("Options")
codes = ['Q', 'S', 'C', 'E']
descriptions = ['Quit', 'Starts with', 'Contains', 'Ends with']
hint = "Letters in state name to look for: "

for i in range(len(codes)):
    print(codes[i], descriptions[i])
my_option = input("Type the option you want: ").lower()

while my_option != 'q':
    find_me = input(hint).lower()
    if my_option == 's':
        n_found = 0
        for details_list in states:
            state = details_list[0]
            if state.startswith(find_me):
                state = details_list[0]
                capital = details_list[1]
                area = details_list[2]
                pop = details_list[3]
                density = details_list[4]
                show_density = nice_float(density, 9, 1)
                show_state = nice_str(state.title(), state_width)
                show_capital = nice_str(capital.title(), capital_width)
                show_area = nice_int(area, area_width)
                show_pop = nice_float(pop, pop_width, decimal)
                print(show_state, show_capital, show_area, "sq km", show_pop, "millions",
                      show_density, "people / sq km")
                n_found = n_found + 1
                
                


    elif my_option == 'e':
        n_found = 0
        for details_list in states:
            state = details_list[0]
            if state.endswith(find_me):
                    state = details_list[0]
                    capital = details_list[1]
                    area = details_list[2]
                    pop = details_list[3]
                    density = details_list[4]
                    show_density = nice_float(density, 9, 1)
                    show_state = nice_str(state.title(), state_width)
                    show_capital = nice_str(capital.title(), capital_width)
                    show_area = nice_int(area, area_width)
                    show_pop = nice_float(pop, pop_width,decimal)
                    print(show_state, show_capital, show_area, "sq km", show_pop, "millions",
                          show_density, "people / sq km")
                    n_found = n_found + 1

    elif my_option == 'c':
        n_found = 0
        for details_list in states:
            state = details_list[0]
            if find_me in state:
                    state = details_list[0]
                    capital = details_list[1]
                    area = details_list[2]
                    pop = details_list[3]
                    density = details_list[4]
                    show_density = nice_float(density, 9, 1)
                    show_state = nice_str(state.title(), state_width)
                    show_capital = nice_str(capital.title(), capital_width)
                    show_area = nice_int(area, area_width)
                    show_pop = nice_float(pop, pop_width, decimal)
                    print(show_state, show_capital, show_area, "sq km", show_pop, "millions",
                          show_density, "people / sq km")
                    n_found = n_found + 1


















##if n_found == 0:
##    print("No such state, please try again\n")
##print()
##
##for i in range(len(codes)):
##    print(codes[i], descriptions[i])
##my_option = input("Type the option you want: ").lower()
##print("\nFinished")

                






##def select_starts_with(find_me, states):
##    n_found = 0
##    for details_list in states:
##        state = details_list[0]
##        if state.startswith(find_me):
##           print_state(details_list)
##           n_found = n_found + 1
##        return n_found
##
##def select_contains(find_me, states):
##    n_found = 0
##    for details_list in states:
##        state = details_list[0]
##        if find_me in state:
##            print_state(details_list)
##            n_found = n_found + 1
##    return n_found
##
##def select_ends_with(find_me, states):
##    print()
##    n_found = 0
##    for details_list in states:
##        state = details_list[0]
##        if state.endswith(find_me):
##            print_state(details_list)
##            n_found = n_found + 1
##    return n_found
##
##def get_state_details(line):
##    item_list = line.split(',')
##    state = item_list[0].lower()
##    capital = item_list[1].lower()
##    area = int(item_list[2])
##    pop = float(item_list[3])
##    density = round(pop * 1000000 / area, 1)
##    details_list = [state, capital, area, pop, density]
##    return details_list
##
##def read_data(filename):
##    states_list = [ ]
##    with open(filename, 'r', encoding='utf-8') as states_file:
##        for line in states_file:
##            line = line.strip( )
##            if line[0] != '#':
##                details_list = get_state_details(line)
##                states_list.append(details_list)
##        return states_list
##
##def print_debug(states):
##    for detail_list in states:
##        print(detail_list)
##    print()
##    return None
##
##def get_option(option, descriptions):
##    for i in range(len(options)):
##        print(option[i], description[i])
##    my_code = input("type the option you want: ")
##    for a_code in code:
##        if a_code.lower() == my_code.lower():
##            return my_code.lower()
##    print("\nPlease enter a valid code")
##    return get_option(codes, descriptions)
##
##
##
##state_width = 16
##capital_width = 16
##area_width = 10
##pop_width = 8
##decimal = 1
##
##
##filename = 'state_data.txt'
##states = read_data(filename)
##
##with open(filename, 'r', encoding='utf-8') as states_file:
##    for line in states_file:
##        line = line.strip( )
##        if line[0] != '#':
##            item_list = line.split(',')
##            state = item_list[0] .lower()
##            capital = item_list[1] .lower()
##            area = int(item_list[2])
##            pop = float(item_list[3])
##            details = [state, capital, area, pop]
##            states.append(details)
##print()
##
##
##hint = "Type the option you want: "
##options = input(hint)
##options = options.lower()
##
##
##
##options = ['Q', 'S', 'C', 'E']
##descriptions = ['Quit', 'starts with', 'contains', 'Ends with']
##
##my_option = get_option(options, descriptions)
##while my_option != 'q':
##    find_me = input(hint).lower()
##
##    if my_option == "s":
##        n_found = select_starts_with(find_me, states)
##    elif my_option == "c":
##        n_found = select_contains(find_me, states)
##    elif my_option == 'e':
##        n_found = select_ends_with(find_me, states)
##    if n_found == 0:
##        print("No such state, please try again")
##    print()
##    my_option = get_option(options, descriptions)
##              
##
##    
##
