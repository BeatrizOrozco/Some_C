import matplotlib
matplotlib.use("Agg")

import matplotlib.pyplot as plt
import numpy as np
import pandas as pd

data1 = np.array(pd.read_csv('sample_1.dat'))
data2 = np.array(pd.read_csv('sample_2.dat'))
data3 = np.array(pd.read_csv('sample_3.dat'))
data4 = np.array(pd.read_csv('sample_4.dat'))
x1=data1[:,0]
y1=data1[:,1]
x2=data2[:,0]
y2=data2[:,1]
x3=data3[:,0]
y3=data3[:,1]
x4=data4[:,0]
y4=data4[:,1]

plt.plot(x1,y1)
plt.plot(x2,y2)
plt.plot(x3,y3)
plt.plot(x4,y4)
plt.savefig("sample.pdf")
