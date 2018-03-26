# P8_3_fixme.py

# Help - when I run this program it does work right.
# It does not find names like ashley in the names list
# 

def linear_search(who, names):
    ''' Return index of name or None if not found'''
    index = 0
    #Trying to find a number position in a list.
    #replaced person with i
    #instead of return index i did return i
    for i in range(len(names)):
        if names[i] == who:
            return i
        

#deleted the elif statement and, return none statement

# i decided to make b equal the list of names then assign names variable as the sorted b's list,
#in order to sort the names list.
b = ['jim', 'tom', 'ashley', 'amanda', 'brittany', 'megan']
names = sorted(b)

hint = "Type Q or type a name to search for (such as jim): "
find_name = input(hint).lower()
#change the q to lower case q because of the imput(hint).lower()
while find_name != 'q':
    index = linear_search(find_name, names)
    print()
    if index == None:
        print(find_name.title(), 'NOT found in names list')
        print()
    else:
        print(find_name.title(), 'found at offset', index, 'in names list')
        print()

    
    find_name = input(hint).lower()
