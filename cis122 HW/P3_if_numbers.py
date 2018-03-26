count = 5
limit = 3
if count < limit:
    print("Count", count, "is less than limit", limit)
else:
    print("Count", count, "is NOT less than limit", limit)

print(" ")

print("Inventory")
amounts = [5, 16, 44, 31, 107, 48, 22, 999, 8]
low_limit = 10
high_limit = 99
missint = 999
for numbers in amounts:
    note = "OK"
    if numbers < low_limit:
        note = "Too few items"
    if numbers > high_limit:
        note = "Too many items"
    if numbers == missint:
        note = "Unknown number of items - recheck inventory"
    print(numbers, note)

print(" ")
print(" ")

print("Cohnah market's prices")
prices_list = [4.95, 9.90, 12.44, 1.99, 27.95, 5.00, 11.05, 144.23, 20.00]
bargain = 5.00
quality = 20.00
for numbers in prices_list:
    note = " "
    if numbers <= bargain:
        note = "Sale price!"
    if numbers >= quality:
        note = "Exclusive offering"
    print(numbers, note)

