hint = "Enter name of country or 'Quit':"
country_list = [ ]
nation = input(hint)
while nation != 'Quit':
    country_list.append(nation)
    nation = input(hint)   
print()
print('Countries')
for country in country_list:
    print(country)
print()
print('Finished')
