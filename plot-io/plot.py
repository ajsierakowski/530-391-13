import matplotlib.pyplot as mpl

def plot(x, y):
  mpl.xlabel('x')
  mpl.ylabel('y')
  mpl.title('y = ax^2 + bx + c')

  mpl.plot(x, y)


  mpl.savefig('plot.png')
  mpl.show()
