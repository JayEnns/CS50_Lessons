# Checks if entered credit card number is a valid VISA, AMEX, or MC via Luhn’s algorithm.

while True:

    # get input
    numstr = input('CC# ')

    # end prog loop if empty
    if numstr == '':
        break

    # count digits
    digits = len(numstr)
    print(f'digits: {digits}')

    # convert to int list
    numL = []
    for n in numstr:
        numL.append(int(n))

    # starting from end, add 1st digits to sum, 2nd digits *2, add digits, add to sum.
    numR = numstr[::-1] # reversed
    sum = 0
    iter = 0
    for i in range(digits):
        if iter % 2 == 0:
            sum += int(numR[i])
            iter += 1
        else:
            n = int(numR[i]) * 2
            if n >= 10:
                n -= 9
            sum += n
            iter += 1


    # If the total’s last digit is 0 (if the total modulo 10 is congruent to 0), the number is valid
    # VISA:             13, 16 digits, starts 4
    # AMERICAN EXPRESS: 15 digits, starts 34, 37
    # MASTERCARD:       16 digits, starts 51, 52, 53, 54, 55
    if sum % 10 == 0:
        if digits in [13, 16] and numL[0] == 4:
            print('VISA')
        elif digits == 15 and numL[0] == 3 and numL[1] in [4, 7]:
            print('AMERICAN EXPRESS')
        elif digits == 16 and numL[0] == 5 and numL[1] >= 1 and numL[1] <= 5:
            print('MASTERCARD')
        else:
            print('INVALID')
    else:
        print('INVALID')
    
    print()