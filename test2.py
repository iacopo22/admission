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
if df.index.tz is None:
    # If the index is naive (no timezone info), first localize to UTC then convert
    df.index = df.index.tz_localize("UTC").tz_convert("America/New_York")
else:
    df.index = df.index.tz_convert("America/New_York")

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

print("Columns:", df.columns)
print(df.head())
# Now calculate Amihud
df['Amihud'] = np.abs(df['Return']) / df['DollarVolume']

# Drop NaNs
df.dropna(subset=['Amihud'], inplace=True)

# %%
# Plot
plt.figure(figsize=(18, 9))
plt.plot(df.index, df['Volume'], label='Volume', color='darkblue')
plt.gca().xaxis.set_major_formatter(mdates.DateFormatter('%H:%M'))  # European format
plt.gcf().autofmt_xdate()
plt.title(f'Volume - {ticker} (5-min Interval)\n25-03-2025')
plt.xlabel('Time')
plt.ylabel('Volume')
plt.grid(True)
plt.legend()
plt.tight_layout()
plt.show()

# %%
