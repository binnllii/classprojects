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

state_width = 16
capital_width = 16
area_width = 10
pop_width = 8
decimal = 1

states = [ ]
filename = 'state_data.txt'

with open(filename, 'r', encoding='utf-8') as states_file:
    for line in states_file:
        line = line.strip( )
        if line[0] != '#':
            item_list = line.split(',')
            state = item_list[0] .lower()
            capital = item_list[1] .lower()
            area = int(item_list[2])
            pop = float(item_list[3])
            details = [state, capital, area, pop]
            states.append(details)
print()
print("state_capitals_area_pop_v4")
hint = "Type a state or start of state name or QUIT to end: "
state_to_find = input(hint)
state_to_find = state_to_find.lower()

while state_to_find != 'quit' :
    print()
    s_found = 0
    for details_list in states:
        state = details_list[0]
        if state.startswith(state_to_find):
            capital = details_list[1]
            area = details_list[2]
            pop = details_list[3]
            s_found += 1
            show_state = nice_str(state.title(), state_width)
            show_capital = nice_str(capital.title(), capital_width)
            show_area = nice_int(area, area_width)
            show_pop = nice_float(pop, pop_width, decimal)
            density = ((pop * 10 **6)/area)
            density = round(density, 1)
            show_density = nice_float(density, 6, 1)

            print(show_state, show_capital, show_area, "sq km", show_pop, "millions", show_density, "people/sq km")

    if s_found == 0:
         print("No such state, please try again \n")
    print()
    state_to_find = input(hint)
    state_to_find = state_to_find.lower()
print("\nFinished")

    
   
        
  
    
    
        
