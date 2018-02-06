import matplotlib.pyplot as plt
from matplotlib.ticker import FuncFormatter, MaxNLocator

time = []
htm = []
lock = []
conflict = []

htm_time = []
htm_htm = []
htm_lock = []
htm_conflict = []

data = []
f = open('output')
for i in f:
    data.append(int(i))
f.close()

speed = []

count = 0
while count < len(data):
    tem = 0
    for i in range(20):
        htm_time.append(data[count])
        count += 1
        htm_htm.append(data[count])
        count += 1
        htm_lock.append(data[count])
        count += 1
        htm_conflict.append(data[count])
        count += 1

        time.append(data[count])
        count += 1
        htm.append(data[count])
        count += 1
        lock.append(data[count])
        count += 1
        conflict.append(data[count])
        count += 1

        tem += float(htm_time[-1]) / time[-1]

    speed.append(tem / 20)


fig = plt.figure()
ax = fig.add_subplot(111)
xs = [100, 500, 1000, 1500, 2000, 2500, 3000, 3500]
base = [1 for i in xs]

ax.plot(xs, speed)
ax.plot(xs, base, '--')

ax.set_ylabel('Speed Up', {'fontsize':13})
ax.set_xlabel('Workload for Each Trasaction', {'fontsize':13})

ax.tick_params(labelsize=13)

plt.show()
