import numpy as np
import matplotlib.pyplot as plt

# Parameters
N = 100  # number of trades
v_H = 1.0   # high asset value
v_L = 0.0   # low asset value
p0 = 0.5    # initial belief that value is high
alpha = 0.3  # probability a trader is informed
shock_trade = 50  # simulate a shock at this trade

# true value equal to v_L since it's a bad news
true_value = v_L

# Initialize storage
beliefs = []
bid_prices = []
ask_prices = []
mid_prices = []
spreads = []
orders = []

p = p0  # initial belief

def update_belief(p, order, alpha):
    numerator = p * (alpha + 0.5 * (1 - alpha)) if order == 'buy' else (1 - p) * (alpha + 0.5 * (1 - alpha))
    denominator = (p * (alpha + 0.5 * (1 - alpha)) +
                   (1 - p) * (0.5 * (1 - alpha) if order == 'buy' else (1 - p)*(alpha + 0.5 * (1 - alpha)) + p * (0.5 * (1 - alpha))))
    return numerator / denominator

for t in range(N):
    if t == shock_trade:
        # Sudden info shock: change probability market thinks asset is H
        p = 0.8  # strong signal arrives
    # Decide trader type
    is_informed = np.random.rand() < alpha

    # Generate order
    if is_informed:
        order = 'buy'
    else:
        order = np.random.choice(['buy', 'sell'])

    # Update belief
    p = update_belief(p, order, alpha)

    # Compute bid and ask
    bid = (1 - p) * v_L + p * v_H - 0.02  # bid discount
    ask = (1 - p) * v_L + p * v_H + 0.02  # ask premium
    mid = (bid + ask) / 2
    spread = ask - bid

    # Store
    beliefs.append(p)
    bid_prices.append(bid)
    ask_prices.append(ask)
    mid_prices.append(mid)
    spreads.append(spread)
    orders.append(order)

# --- Plotting ---
plt.figure(figsize=(12, 6))
plt.plot(mid_prices, label='Mid Price')
plt.plot(bid_prices, linestyle='--', label='Bid Price')
plt.plot(ask_prices, linestyle='--', label='Ask Price')
plt.axvline(shock_trade, color='red', linestyle=':', label='Tariff Shock')
plt.title('Glosten-Milgrom Simulation of Market Reaction to News')
plt.xlabel('Trade Number')
plt.ylabel('Price')
plt.legend()
plt.grid(True)
plt.show()

plt.figure(figsize=(10, 4))
plt.plot(spreads, color='orange')
plt.axvline(shock_trade, color='red', linestyle=':', label='Tariff Shock')
plt.title('Bid-Ask Spread Evolution')
plt.xlabel('Trade Number')
plt.ylabel('Spread')
plt.grid(True)
plt.show()
