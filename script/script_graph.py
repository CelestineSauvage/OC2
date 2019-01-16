import csv
import sys
from operator import itemgetter
import matplotlib.pyplot as plt


#def main(csv_name,repet, index, min_values, max_values, x_lab, y_lab):
def oneplot(filename1):
    x1 = []
    y1 = []

    with open(filename1) as file1:
        for line in file1:
            line = line.replace("\t", " ")
            coord = (line.split(' '))
            x1.append(int(coord[0]))
            y1.append(int(coord[-1]))
    plt.scatter(x1, y1)
    plt.show()

def twoplot(filename1, filename2):
    x1 = []
    y1 = []

    x2 = []
    y2 = []
    with open(filename1) as file1:
        for line in file1:
            line = line.replace("\t", " ")
            coord = (line.split(' '))
            x1.append(int(coord[0]))
            y1.append(int(coord[-1]))
    with open(filename2) as file2:
        for line in file2:
            line = line.replace("\t", " ")
            coord = (line.split(' '))
            x2.append(int(coord[0]))
            y2.append(int(coord[-1]))

    plt.scatter(x1, y1, s=3)
    plt.scatter(x2, y2, c="red", s=15)
    plt.show()


if __name__ == "__main__":
    # execute only if run as a script

    # argument 1 nom du ficher sans filtre
    # argument 2 nom du ficher avec filtre
    if (len(sys.argv) == 2):
        oneplot(sys.argv[1])
    else:
        twoplot(sys.argv[1], sys.argv[2])
