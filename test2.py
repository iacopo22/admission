# First, install yfinance if you haven't:
# pip install yfinance
# %%
import yfinance as yf
import pandas as pd
import numpy as np
import matplotlib.pyplot as plt

# Parameters
ticker = "AAPL"
start_date = "2025-04-02"
end_date = "2025-04-04"
interval = "5m"

# Download 10-minute interval data
df = yf.download(ticker, start=start_date, end=end_date, interval=interval)

# Flatten MultiIndex (handle multi-level columns)
df.columns = df.columns.get_level_values(0)

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
plt.plot(df.index, df['Amihud'], label='Amihud Illiquidity', color='darkblue')
plt.title(f'Amihud Illiquidity Ratio - {ticker} (10-min Interval)\n{start_date} to {end_date}')
plt.xlabel('Time')
plt.ylabel('Amihud Ratio')
plt.grid(True)
plt.legend()
plt.tight_layout()
plt.show()

# %%
