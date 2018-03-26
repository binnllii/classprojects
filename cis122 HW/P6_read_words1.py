#shoes reading from text file

sow_pods = [ ]
filename = 'sowpods_short.txt'

#filename, 'r' ("read" not 'w' for "write")
with open(filename, 'r', encoding='utf-8') as my_file:
    for line in my_file:
        line = line.strip()
        if line[0] != '#':
            sow_pods.append(line)
#debug
    print("DEBUG\n")
    for word in sow_pods:
        print(word)
    print("There are", len(sow_pods), "in the word list")

hint = "Type a word to find in the word list, or $ to exit: "
word_to_find = input(hint)
word_to_find = word_to_find.lower()

while word_to_find != '$' :
    if word_to_find in sow_pods:
        print("Found", word_to_find)           
    else:
        print("Sorry", word_to_find, "is not in the word list")
    word_to_find = input(hint)
    word_to_find = word_to_find.lower()
 
