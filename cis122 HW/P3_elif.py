grade_a = 57
grade_b = 43
grade_c = 33
grade_d = 25
name_list = [ ]
name = input("First name (or Quit to end):")
score = int(input("Points on test:" ))
while name != "Quit":
    if score >= grade_a:
        print(name, score, "A")
    elif score < grade_a and score >= grade_b:
        print(name, score, "B")
    elif score < grade_b and score >= grade_c:
        print(name, score, "C")
    elif score < grade_c and score >= grade_d:
        print(name, score, "D")
    elif score < grade_d:
        print(name, score, "F")
    name = input("First name (or Quit to end):")
    if name == "Quit":
        break
    score = int(input("Points on test:" ))
    
print(" ")
print("Finished")
    
