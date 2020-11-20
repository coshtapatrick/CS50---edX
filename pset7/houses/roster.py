from cs50 import SQL
from sys import argv
import csv

db = SQL('sqlite:///students.db')

# verify correct usage
if len(argv) != 2:
    print('Usage: python roster.py house_name')
else:
    # create a sheet with all the rows in the database selected
    sheet = db.execute("SELECT * FROM students WHERE house = ? ORDER BY last ASC, first ASC;", argv[1])
    # iterate each row of sheet
    for row in sheet:
        # verify if the character has a middle name
        if row['middle'] == None:
            print(row["first"], row["last"]+", born", row["birth"])
            continue
        else:
            print(row["first"], row["middle"], row["last"]+", born", row["birth"])
            continue
