#include <stdio.h>

from selenium import webdriver
from selenium.webdriver.chrome.service import Service
from selenium.webdriver.common.by import By
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC
from webdriver_manager.chrome import ChromeDriverManager
import pandas as pd

# Setup the Service object to get ChromeDriver automatically
service = Service(ChromeDriverManager().install())
driver = webdriver.Chrome(service=service)

# Open the main page with the categories
main_url = 'http://www.elettrofor.it/?plg_cat_view=v&cata_id=1'  # Replace with the URL of the page containing product categories
driver.get(main_url)

# Wait for the page to load and category links to appear
WebDriverWait(driver, 10).until(EC.presence_of_element_located((By.TAG_NAME, 'tr')))  # Wait until a category table row is present

# Initialize an empty list to store product data
products = []

# Find all the category links/buttons
category_links = driver.find_elements(By.XPATH, <td onClick="location.href='?plg_cat_view=v&cata_id=844')  # Find all category links

# Function to scrape products from a category or sub-category
def scrape_category_page(category_url, category_name):
    # Navigate to the category page
    driver.get(category_url)
    WebDriverWait(driver, 10).until(EC.presence_of_element_located((By.TAG_NAME, 'table')))  # Wait for the table to load

    # Scrape the products on this page
    product_containers = driver.find_elements(By.CLASS_NAME, 'PRODUCT_CONTAINER_CLASS')  # Update with the actual product container class
    for container in product_containers:
        try:
            # Scrape the product code, title, and description
            code = container.find_element(By.CLASS_NAME, 'titolo_catalogo').text  # Update with actual class
            title = container.find_element(By.CLASS_NAME, 'MsoNormal').text  # Update with actual class
            description = container.find_element(By.CLASS_NAME, 'MsoNormal').text  # Update with actual class

            # Store the data in a dictionary
            product = {
                'Code': code,
                'Title': title,
                'Description': description,
                'Category': category_name  # Add the category or sub-category name to the product
            }

            # Add to the list of products
            products.append(product)
        except Exception as e:
            print(f"Error extracting product data: {e}")

    # Check for sub-categories (if any)
    sub_category_links = driver.find_elements(By.XPATH, <td onClick="location.href='?plg_cat_view=v&cata_id=12')  # Replace with the actual sub-category link class
    for sub_link in sub_category_links:
        sub_category_name = sub_link.text  # Get the sub-category name
        sub_category_url = sub_link.find_element(By.TAG_NAME, 'a').get_attribute('href')  # Get the URL of the sub-category
        scrape_category_page(sub_category_url, sub_category_name)  # Recursively scrape the sub-category

# Loop through each category
for link in category_links:
    try:
        # Get the category name and URL
        category_name = link.text
        category_url = link.find_element(By.TAG_NAME, 'a').get_attribute('href')

        # Check if this category has sub-categories (if so, navigate to the sub-categories)
        scrape_category_page(category_url, category_name)

    except Exception as e:
        print(f"Error navigating to category: {e}")

# Convert the list of products to a pandas DataFrame
df = pd.DataFrame(products)

# Save the DataFrame to an Excel file
df.to_excel('products_by_category_and_subcategory.xlsx', index=False)

# Close the browser
driver.quit()


How can I convert the td path to xPath? And which path should I insert? since every categories have a different "id=x" x number

