# First, install yfinance if you haven't:
# pip install yfinance
# %%
import yfinance as yf
import pandas as pd
import numpy as np
import matplotlib.pyplot as plt

# Parameters
ticker = "AAPL"
start_date = "2025-04-01"
end_date = "2025-04-04"
interval = "10m"

# Download 10-minute interval data
df = yf.download(ticker, start=start_date, end=end_date, interval=interval)

# Drop rows with missing data
df.dropna(inplace=True)

# Calculate return (percentage change in adjusted close)
df['Return'] = df['Adj Close'].pct_change()

# Calculate dollar volume
df['DollarVolume'] = df['Adj Close'] * df['Volume']

# Calculate Amihud Illiquidity
df['Amihud'] = np.abs(df['Return']) / df['DollarVolume']

# Drop NaNs created by pct_change
df.dropna(subset=['Amihud'], inplace=True)

# %%
# Plot Amihud ratio
plt.figure(figsize=(12, 6))
plt.plot(df.index, df['Amihud'], label='Amihud Illiquidity', color='darkblue')
plt.title(f'Amihud Illiquidity Ratio - {ticker} (10-min Interval)\n{start_date} to {end_date}')
plt.xlabel('Time')
plt.ylabel('Amihud Ratio')
plt.grid(True)
plt.legend()
plt.tight_layout()
plt.show()
