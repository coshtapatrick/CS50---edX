# Made by PMBC
text = input('Text: ')

# 0.0588 * L - 0.296 * S - 15.8

# creates all the necessary variables
r = len(text)
words, letters, sentence = len(text.split()), 0, 0

# look into each character in the string
for i in range(r):
    if text[i].isalpha():
        letters += 1
    elif text[i] == '!' or text[i] == '?' or text[i] == '.':
        sentence += 1
        
# calculate de algorithm
L, S = (letters / words) * 100, (sentence / words) * 100

grade = 0.0588 * L - 0.296 * S - 15.8

# verifies teh conditions to print in the prompt
if grade < 1:
    print('Before Grade 1')
elif grade >= 16:
    print('Grade 16+')
else:
    print(f'Grade {round(grade)}')
