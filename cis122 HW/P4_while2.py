import random

roll_list = [ ]

n = 0

while True:
    roll_1 = random.randint(1, 6)
    roll_2 = random.randint(1, 6)
    roll_list.append(roll_1)
    roll_list.append(roll_2)
    n = n + 1
                         
    if roll_1 == 6 and roll_2 == 6:

        print('Rolled ', n * 2, 'dice as', n, 'pairs of dice.')
        print(roll_list)
        break



