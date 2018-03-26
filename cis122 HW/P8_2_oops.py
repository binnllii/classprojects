# P8_2_oops.py

# Help - when I run this program it does not work right.
# I cannot find names like amanda that are in the list
# 

def search(who, names):
    ''' Return index of name or None if not found'''
    index = 0
    #changed names to range(len(names)) to turn the list into the number position of the names
    #changed persons to i
    #changed return index to return i
    for i in range(len(names)):
        if names[i] == who:
            return i
   #deleted else: return none

my_list = ['jim', 'ashley', 'amanda', 'zelda', 'brittany']
my_gpa =  [3.05, 4.01,      2.87,      4.20,    1.95]


hint = "Type Q or type a name to search for (such as Jim): "
find_me = input(hint).lower()

while find_me != 'Q':
    index = search(find_me, my_list)
    if index == None:
        #replaced print statement with a break. 
        break
#added a blank line print(" ")
        print(" ")
    else:
        #added a .title to captialize the first letter
        print(find_me.title(), 'found at offset', index, 'in names list')
        print(find_me.title(), 'has a', my_gpa[index], 'grade point average')
        #added a blank line print(" ")
        print(" ")
    find_me = input(hint).lower()
        
