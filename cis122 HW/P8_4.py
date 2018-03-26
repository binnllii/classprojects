


# P8_4.py

# Display options, do the right thing, repeat
#changed my_codes, my_description to codes and descr so it can tye into the 2 defined strings.
def get_option(codes, descr):
    for count in range(len(codes)):
        print(codes[count], descr[count])

    answer = input("Type your choice: ")
    option = answer[0].lower()
    for code in codes:
        if code[0].lower() == option:
            return option
    print("Please try again")
    
    return get_option(codes, descr)

codes = ['Q', 'B', 'S', 'P']
descr = ['Quit', 'Buy', 'Sell', 'Panic']

while True:
    choices = get_option(codes, descr)
    if choices == 'q':
        break
    elif choices =='b':
        print("Buy more and save even more!")
    elif choices == 's':
        print('Sell and earn big money now!')
    elif choices == 'p':
        print('The yen is down, oil is down, abandon all hope - PANIC')

print("Done")
