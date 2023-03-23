# Calculates reading level of input text via Coleman-Liau index.

while True: 
    # get input text
    text = input('Text: ')

    # end prog loop if empty
    if text == '':
        break

    letters = 0
    words = 1    # accounts for the last word that will not be followed by a space
    sentences = 0

    # count letters, words, sentences
    for i in text:
        if i.lower() in 'abcdefghijklmnopqrstuvwxyz':
            letters += 1
        elif i == ' ':
            words += 1
        elif i in '.!?':
            sentences += 1
        else:
            continue

    # calculate reading level
    grade = round(0.0588 * (letters / words * 100) - 0.296 * (sentences / words * 100) - 15.8)

    if grade < 1:
        grade = "<1"
    elif grade > 16:
        grade = "16+"


    print(f'''
Letters:   {letters}
Words:     {words}
Sentences: {sentences}
GRADE:     {grade}
_______________
    ''')