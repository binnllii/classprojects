def ask_for_int(hint):
 """ Return int value of calling input"""
 temp = input(hint)
 value = int(temp)
 return value
# test ask_for_int
height_hint = "Type your height in inches "
height = ask_for_int(height_hint)
print("Height", height, "inches")
#print(value)
print("Trying to print value gets an error") #caused an error

temp = 27
print("temp", temp)
hint2 = "Lucky number (1-10): "
lucky = ask_for_int(hint2)
print("temp", temp) #it doesnt change
