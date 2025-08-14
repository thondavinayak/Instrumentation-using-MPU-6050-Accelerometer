import serial
import time
import matplotlib.pyplot as plt
from collections import deque

ser = serial.Serial('COM8', 9600)
time.sleep(2)  

plt.ion()

max_samples = 100
frequencies = deque([0]*max_samples, maxlen=max_samples)
durations = deque([0]*max_samples, maxlen=max_samples)
timestamps = deque([i for i in range(-max_samples+1, 1)], maxlen=max_samples)

fig, (ax1, ax2) = plt.subplots(2, 1, figsize=(10, 6))

line1, = ax1.plot(timestamps, frequencies, label='Frequency (Hz)')
ax1.set_ylabel('Frequency (Hz)')
ax1.grid(True)

line2, = ax2.plot(timestamps, durations, label='Duration (µs)', color='orange')
ax2.set_ylabel('Duration (µs)')
ax2.set_xlabel('Samples')
ax2.grid(True)

plt.tight_layout()

# === Main Loop ===
try:
    while True:
        if ser.in_waiting:
            line = ser.readline().decode('utf-8').strip()
            try:
                duration = int(line)
                if duration > 0:
                    frequency = 1000000.0 / (2 * duration)

                    durations.append(duration)
                    frequencies.append(frequency)

                    line1.set_ydata(frequencies)
                    line2.set_ydata(durations)

                    ax1.relim()
                    ax1.autoscale_view()
                    ax2.relim()
                    ax2.autoscale_view()

                    plt.pause(0.01)
            except ValueError:
                print(f"Skipping bad data: {line}")
                continue

except KeyboardInterrupt:
    print("Plotting stopped by user.")
    ser.close()
