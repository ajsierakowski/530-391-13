#!/usr/bin/env python

import matplotlib.pyplot as plt

f = open("output", "r")

# read header
line = f.readline()

# create a place to put data
X = list()
Y = list()

# read data
for line in f:
  [x, y] = line.split()
  X.append(float(x))
  Y.append(float(y))

# do some data analysis

# do plotting
plt.plot(X,Y)
plt.show()
