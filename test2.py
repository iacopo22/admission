# First, install yfinance if you haven't:
# pip install yfinance
import yfinance as yf
import pandas as pd
import numpy as np
import datetime
from zoneinfo import ZoneInfo


def est_time_formatter(x, pos):
    dt = mdates.num2date(x).astimezone(ZoneInfo("America/New_York"))
    return dt.strftime('%H:%M')
# Parameters
ticker = "AAPL"
# Define your new date range (March 3 to April 3, 2025)
start = datetime.date(2025, 4, 15)
end = datetime.date(2025, 4, 4)
interval = "1h"

# Download 10-minute interval data
df = yf.download(ticker, start=start, end=end, interval=interval)

# Flatten MultiIndex (handle multi-level columns)
df.columns = df.columns.get_level_values(0)

# Convert the DataFrame index to Eastern Time ("America/New_York")
df.index = df.index.tz_convert('America/New_York')

# Drop rows with missing data
df.dropna(inplace=True)

# Make sure volume isn't zero to avoid division errors
df = df[df['Volume'] > 0]


# Filter for the date range
df_range = df[(df.index.date >= start) & (df.index.date <= end)]

# Filter for the final hour (15:00 - 16:00)
final_hour_df = df_range.between_time("09:30", "10:30")

# Sum volume during the final hour for each trading day
daily_final_hour_volume = final_hour_df['Volume'].groupby(final_hour_df.index.date).sum()

# Count the number of trading days in the specified range (excluding days with no trading data)
num_days = len(daily_final_hour_volume)

# Calculate the average final hour volume
avg_final_hour_volume = daily_final_hour_volume.sum() / num_days if num_days > 0 else 0

# Print the results
print("Total final-hour volume for each day:")
print(daily_final_hour_volume)
print(f"\nAverage final-hour volume across {num_days} trading days: {avg_final_hour_volume:,.0f}")
