from pdf2image import convert_from_path
from PIL import Image

# Convert PDF pages to images
images = convert_from_path("your_file.pdf")

# Get dimensions of the first image
width, height = images[0].size

# Create a blank image large enough to hold all pages vertically
final_image = Image.new("RGB", (width, height * len(images)))

# Paste all images into one
for i, img in enumerate(images):
    final_image.paste(img, (0, i * height))

# Save as a single JPG
final_image.save("combined.jpg", "JPEG")
