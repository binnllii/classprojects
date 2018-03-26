def euros_to_dollars(euros):
    '''convert euro dollars to us dollars'''
    dollars = euros * 1.09
    return dollars

def dollars_to_euros(dollars):
    '''converts dollars to euros'''
    euros = dollars / 1.09
    amount = round(euros,2)
    return amount



print("Roughly, 10 euros gets a little more than", euros_to_dollars(10), "dollars.")
print("Roughly, 13 dollars gets a little more than", dollars_to_euros(13), "dollars.")


def fahr_to_celcius(f_temp):
    '''returns celcius from fahrenheit value'''
    temp = f_temp - 32
    celcius = temp * (180/100)
    degree = int(celcius)
    return degree
def celcius_to_fah(c_temp):
    '''return fah from celcius'''
    temp = c_temp * (180/100)
    fahr = temp + 32
    degree = int(fahr)
    return degree

print("0 C should give", celcius_to_fah(0), "F")
print("32 F should give", fahr_to_celcius(32), "C")
print("100 C should give", celcius_to_fah(100), "F")
print("212 F should give", fahr_to_celcius(212), "C")
    
