top_movies = ['Harry Potter', 'Wreck it Ralph', 'Spiderman', 'The Avengers']
print("Good Movies")
print(" ")
for movies in top_movies:
    print(movies)
print(" ")
print("Modified List")
numbers = [7, 11, 30, 19, 22, -3]
for index in range(len(numbers)):
    if numbers[index] % 2 != 0:
        numbers[index] = numbers[index] * 2
print(numbers)
