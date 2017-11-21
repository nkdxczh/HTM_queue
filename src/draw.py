import numpy as np
import matplotlib.pyplot as plt
import math

x = []
y = []
x1 = []
y1 = []

f = open("result.txt",'r')
line = f.readline()
while line != "":
    x.append(int(line))
    y.append(float(f.readline()))
    line = f.readline()

f.close()

f = open("result1.txt",'r')
line = f.readline()
while line != "":
    x1.append(int(line))
    y1.append(float(f.readline()))
    line = f.readline()

fit = np.polyfit(x, y, 2)
fit_fn = np.poly1d(fit)

fit1 = np.polyfit(x1, y1, 2)
fit_fn1 = np.poly1d(fit1)

plt.plot(x,y, 'yo', x, fit_fn(x), '--k')
plt.plot(x1,y1, 'bo', x1, fit_fn1(x), '--k')
plt.show()
