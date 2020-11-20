# Made by PMBC
number = input("Number: ")

# AMEX
if len(number) == 15 and number[0] == '3' and (number[1] == '4' or number[1] == '7'):
    print('AMEX')
    
# VISA
elif len(number) == 13 and number[0] == '4':
    print('VISA')
    
# MASTERCARD
elif len(number) == 16:
    if number[0] == '5' and (int(number[1]) < 6 and int(number[1]) > 0):
        print('MASTERCARD')
    elif number[0] == '4':
        print('VISA')
    else:
        print('INVALID')
    
# INVALID
else:
    print("INVALID")
