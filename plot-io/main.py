#!/usr/bin/env python

import readwrite
import function
import plot

[a, b, c] = readwrite.read()

[x, y] = function.quadratic(a, b, c)

plot.plot(x, y)
