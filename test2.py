# First, install yfinance if you haven't:
# pip install yfinance
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
start_date = "2025-04-03"
end_date = "2025-04-04"
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


# Drop NaNs
df.dropna(subset=['Amihud'], inplace=True)


# 2. Define final hour window
final_hour_start = datetime.time(15, 0)
final_hour_end = datetime.time(16, 0)

# 3. Filter for the last hour of trading
final_hour_df = df.between_time(final_hour_start, final_hour_end)

# 4. Group by date and calculate average volume in the final hour
daily_final_hour_avg = final_hour_df['Volume'].groupby(final_hour_df.index.date).mean()

# 5. Optional: calculate overall average volume across all days
overall_avg = daily_final_hour_avg.mean()

print("Daily final hour average volumes:")
print(final_hour_df['Volume'])
print(f"\nOverall average volume in final hour: {overall_avg:,.0f}")
