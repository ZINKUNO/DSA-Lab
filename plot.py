import pandas as pd
import matplotlib.pyplot as plt

# Load the timing data
data = pd.read_csv("timing_data.csv")

# Plot
plt.plot(data['n'], data['BruteTime(ns)'], label='Brute Force', marker='o')
plt.plot(data['n'], data['OptimizedTime(ns)'], label='Optimized', marker='x')
plt.xlabel('n (Input Size)')
plt.ylabel('Time (nanoseconds)')
plt.title('Time Complexity Comparison')



plt.legend()
plt.grid(True)
plt.tight_layout()
plt.savefig("plot.png")  # saves the plot as a PNG
# plt.show()  # optional: comment this out

