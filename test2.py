# First, install yfinance if you haven't:
# pip install yfinance
# %%
import yfinance as yf
import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
import datetime
from zoneinfo import ZoneInfo
import matplotlib.dates as mdates
from matplotlib.ticker import FuncFormatter

def est_time_formatter(x, pos):
    dt = mdates.num2date(x).astimezone(ZoneInfo("America/New_York"))
    return dt.strftime('%H:%M')
# Parameters
ticker = "AAPL"
start_date = "2025-03-25"
end_date = "2025-03-26"
interval = "5m"

# Download 10-minute interval data
df = yf.download(ticker, start=start_date, end=end_date, interval=interval)

# Flatten MultiIndex (handle multi-level columns)
df.columns = df.columns.get_level_values(0)

# Convert the DataFrame index to Eastern Time ("America/New_York")
df.index = df.index.tz_convert('America/New_York')

trading_start = datetime.time(9, 30)
trading_end = datetime.time(16, 0)
df = df.between_time(trading_start, trading_end)


# Drop rows with missing data
df.dropna(inplace=True)

# Make sure volume isn't zero to avoid division errors
df = df[df['Volume'] > 0]

# Calculate returns
df['Return'] = df['Close'].pct_change()

# Calculate dollar volume
df['DollarVolume'] = (df['Close'] * df['Volume']) / 100000000

# Now calculate Amihud
df['Amihud'] = np.abs(df['Return']) / df['DollarVolume']

# Drop NaNs
df.dropna(subset=['Amihud'], inplace=True)
print(df['Amihud'])

# %%
# Plot
plt.figure(figsize=(18, 9))
color1 = 'tab:blue'
ax1.set_xlabel('Time')
ax1.set_ylabel('Amihud Illiquidity', color=color1)
ax1.plot(df.index, df['Amihud'], color=color1, label='Amihud Illiquidity')
ax1.tick_params(axis='y', labelcolor=color1)

# Second axis for Volume
ax2 = ax1.twinx()
color2 = 'tab:red'
ax2.set_ylabel('Volume', color=color2)
ax2.plot(df.index, df['Volume'], color=color2, label='Volume')
ax2.tick_params(axis='y', labelcolor=color2)

# Optional: format x-axis
fig.autofmt_xdate()

# Title and layout
plt.title('Amihud Illiquidity vs Volume')
fig.tight_layout()
plt.grid(True)
plt.show()

# %%
