# Made by PMBC
from cs50 import SQL
from sys import argv
import csv

db = SQL('sqlite:///students.db')
# verify correct usage
if len(argv) != 2:
    print('Usage: python import.py file.csv')
else:
    # opens the csv file to import for the db
    with open(argv[1], "r") as csvf:
        # reads the file
        sheet = csv.DictReader(csvf)
        # iterate each row to the db
        for row in sheet:
            name = row["name"].split()  # separate all the names individualy
            # verify if the character has a middle name
            if len(name) == 2:
                # insert in the database
                db.execute("INSERT INTO students (first, middle, last, house, birth) VALUES(?, ?, ?, ?, ?)",
                           name[0], None, name[1], row["house"], row["birth"])
            else:
                # insert in the database
                db.execute("INSERT INTO students (first, middle, last, house, birth) VALUES(?, ?, ?, ?, ?)",
                           name[0], name[1], name[2], row["house"], row["birth"])
