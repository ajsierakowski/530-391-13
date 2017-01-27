#!/usr/bin/env python

import random

low = -100
high = 100

n = 1000

f = open("points.csv", "w")

f.write("x_coord,y_coord,z_coord,energy\n")

for i in range(n):
  for j in range(3):
    f.write(str(random.randrange(low, high)) + ",")
  f.write(str(random.randrange(low, high)) + "\n")

f.close()
