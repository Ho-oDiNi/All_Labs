import csv
with open('currencies22.csv', newline='') as csvfile:
    reader = csv.reader(csvfile, delimiter=';')
    s = list(reader)
for i in range(25):
    del s[i][3]

print('Name\t\tMarket_cap\tPrice')
for row in s:
    for elem in row:
        if len(elem) <= 7:
            print(elem, end = '\t\t')
        else:
            print(elem, end = '\t')
    print( )

def search():
    print('\nPress \"0\" to exit')
    key = input('Search >> ')
    while key != '0':
        for i in range(len(s)) :
            if key in s[i] :
                print('\nName\t\tMarket_cap\t\tPrice')
                print('\t\t'.join(s[i]))
                break
            elif i == len(s)-1 :
                print('Not found')
                break
        print('\nPress \"0\" to exit')
        key = input("Search >> ")
    return 0;

search()