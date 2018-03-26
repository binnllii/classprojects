import time


def read_file(filename):

    yob_list_short = []

    with open(filename, 'r') as yob_short:
        for line in yob_short:
            line = line.strip( )
            if line[0] != '#':
                items = line.split(',')
                name = items[0]
                gender = items[1]
                year = int(items[2])
                amount = int(items[3])
                rank = int(items[4])

                details = [name, gender, year, amount, rank]

                yob_list_short.append(details)
                
    return yob_list_short

def binary_search(name, name_info):
    word = ''
    mid = 0
    left = 0
    right = len(name_info) - 1
    while left <= right:
        mid = (left + right) // 2
        word = name_info[mid][0]
        if word < name:
            left = mid + 1
        else:
            right = mid -1
    if left >= 0 and left < len(name_info) and name_info[left][0] == name:
        endtime = time.clock()
        return left
    else:
        return -1


def linear_search(name, name_info):
    start = time.clock()
    for i in range(len(name_info)):
        if name == name_info[i][0]:
            endtime = time.clock()
            return i
        elif name < name_info[i][0]:
            return -1
    return -1
        
    
        
        

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

name_width = 12
gender_width = 12
yob_width = 6
number_of_names_width = 8
popularity_width = 4
timo_width = 6
decimal = 2
        
filename = 'yob_1950_2010.txt'
name_info = read_file(filename)

menu = 'Choose your search method:\nQ quit\nM match name\nB binary search\nType the option you want: '

option = input(menu).lower()
while option != 'q':
    if option == 'm':
        hint_m = ('Name to look for: ')
        query_m = input(hint_m).title()
        start = time.clock()
        index = linear_search(query_m, name_info)
        end = time.clock()
        if index != -1:
            name, gender, year, count, rank = name_info[index]
            timo = (end - start) * 1000000
            print("Linear search took", nice_float(timo, timo_width, decimal), "microseconds")
            headline = '{0:12s} {1:1s} {2:4s} {3:>7s} {4:>7s}'
            print(headline.format("Name", "S", "Year", "Count", "Rank"))
            line = '{0:12s} {1:1s} {2:4d} {3:7,d} {4:7,d}'
            #while name in name list matches query_m
            #list append query_m
            found_names = [query_m]
 #           nom = [ ]
            while query_m == name_info[index][0]:
                name, gender, year, count, rank = name_info[index]
                line = '{0:12s} {1:1s} {2:4d} {3:7,d} {4:7,d}'
                print(line.format(name, gender, year, count, rank))
  #             nom.append(name_info[index])
                index = index + 1
                if index >= len(name_info):
                    break
            option = input(menu).lower()

    if option == 'b':
        hint_b = ('Name to look for: ')
        query_b = input(hint_b).title()
        start = time.clock()
        index = binary_search(query_b, name_info)
        end = time.clock()
        if index != -1:
            name, gender, year, count, rank = name_info[index]
            timo = (end - start) * 1000000
            print("Binary search took", nice_float(timo, timo_width, decimal), "microseconds")
            headline = '{0:12s} {1:1s} {2:4s} {3:>7s} {4:>7s}'
            print(headline.format("Name", "S", "Year", "Count", "Rank"))
            line = '{0:12s} {1:1s} {2:4d} {3:7,d} {4:7,d}'
            #while name in name list matches query_m
            #list append query_m
            found_names = [query_b]
 #           nom = [ ]
            while query_b == name_info[index][0]:
                name, gender, year, count, rank = name_info[index]
                line = '{0:12s} {1:1s} {2:4d} {3:7,d} {4:7,d}'
                print(line.format(name, gender, year, count, rank))
  #             nom.append(name_info[index])
                index = index + 1
                if index >= len(name_info):
                    break
                    print(line.format(name, gender, year, count, rank))
            option = input(menu).lower()     


print("Questions")
print("What kind of variation in timings do you find for linear searches")
print("for:")
print("aaron It takes very little time")
print("jane it takes a little more time than aaron")
print("max a little more time than jane")
print("paul a little more time than max")
print("zoe takes the most time out of the 5 names.")
print(" ")
print("Compared to searches on smaller files, how does linear search")
print("scale?")
print("Gets slower as files get bigger")
print(" ")
print("How can you characterize the change in speed of binary searches")
print("compared to changes in file sizes?")
print("the change in speed will only occur when the file size breaks a certain threshold.")
print("but if the change of file size is within a certain threshold, the search speed will stay the same.")
print("for example 1-2, 2-4, 4-8, 8-16, 16-32, 32-64, 64-128, ...... are possible thresholds")
print(" ")
print("For strictly personal use by one person at a time, is linear search")
print("fast enough?")
print("That depends on the file size if its a really big, it can ba  problem, but in most cases it isnt.")
print(" ")
print("If your file grew to 10 times its current size, would search time")
print("become an issue?")
print("it will become an issue in linear searches, but wont be much issue in binary searches.")
print(" ")
print("If you were using your program on a web server with 10 or more")
print("users per second, which kind of search would you need?")
print("a binary search.")



