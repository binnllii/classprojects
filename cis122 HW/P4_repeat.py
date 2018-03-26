hint = "Enter a number between 10 and 20: "
n = int(input(hint))
x = 7
print('Repeat', n, 'times')
print('Powers of', x)
print()
for count in range(n):
    print(x, '**', count, 'is', 7 ** count)
