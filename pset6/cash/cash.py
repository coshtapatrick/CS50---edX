from cs50 import get_float

coins = 0 # .50 .25 .10 .05 .01
change = get_float("Change owed: ")

if change > .50:
    coins += int(change / .50)
    change = change % .50
if change > .25:
    coins += int(change / .25)
    change = change % .25
if change > .10:
    coins += int(change / .10)
    change = change % .10
if change > .05:
    coins += int(change / .05)
    change = change % .05
if change > .01:
    coins += int(change / .01)

print(str(coins))
