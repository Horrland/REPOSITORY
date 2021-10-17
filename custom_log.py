import math, matplotlib_inline

iterations = 50

def custom_ln(x):    
    sum = 0
    x -= 1
    for n in range (0, iterations):
      sum += ((-1)**n) * (x**(n + 1)) / (n + 1)
    return sum

print ("Введите аргумент логарифма 0 < x < 1: ")
arg = input()
print ("Наш уникальный логарифм: ", custom_ln(float (arg)))
print ("Их заурядный логарифм:   ", math.log (float (arg)))

from IPython.display import set_matplotlib_formats
set_matplotlib_formats('pdf', 'svg')

import matplotlib.pyplot as plt
import numpy as np

vs = np.vectorize(custom_ln)
print(custom_ln, vs)

angles = np.r_[-0.1:2.14:0.01]
plt.plot(angles, np.log(angles), linewidth=6, color = 'orange', alpha=0.6)
plt.plot(angles, vs(angles), color='black', linewidth=1.5, linestyle='dashed')
plt.show()