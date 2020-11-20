# Made by PMBC
from sys import argv
import csv

def main():
    if len(argv) != 3:
        print ('Usage: python dna.py data.csv sequence.txt')
    else:
        with open(argv[2], 'r') as dnafile:
            dna_sqnc = dnafile.read().strip('\n')
        with open(argv[1], 'r') as csv_db:
            fstline = csv_db.readline()
            fstline = fstline.strip('\n').split(sep=',')
        with open(argv[1], 'r') as csv_db:
            dbase = csv.DictReader(csv_db)
            for row in dbase:
                name = ''
                compatibility = False
                for i in fstline:
                    if i == 'name':
                        name = row[i]
                    elif int(row[i]) == sequence(i, dna_sqnc):
                        compatibility = True
                    elif int(row[i]) != sequence(i, dna_sqnc):
                        compatibility = False
                        break
                if compatibility:
                    print(name)
                    break
        if not compatibility:
            print('No match')
                    
def sequence(STR, dna):
    holder = 0
    for i  in range(len(dna)):
        if len(dna[i:]) < len(STR):
            break
        else:
            if dna[i : (i + len(STR))] == STR:
                counter = 1
                for j in range(i + len(STR), len(dna), len(STR)):
                    if dna[j : (j + len(STR))] == STR:
                        counter += 1
                    else:
                        break
                if holder < counter:
                    holder = counter
            else:
                continue
    return holder

main()
