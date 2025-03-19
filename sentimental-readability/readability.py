from cs50 import get_string


text = get_string("Text: ")

letters = 0
sentences = 0
words = 1

# I declare a list which contains the punctuation
# to count the number of sentences
punctuation = [".", "!", "?"]

# Check every position of the string to count
# letters, sentences and words
for _ in range(len(text)):
    if text[_].isalpha():
        letters += 1
    elif text[_] == " ":
        words += 1
    elif text[_] in punctuation:
        sentences += 1

L = letters / words * 100
S = sentences / words * 100

# Coleman-Liau index
index = round(0.0588 * L - 0.296 * S - 15.8)

# Print the grade
if index >= 16:
    print("Grade 16+")
elif index < 1:
    print("Before Grade 1")
else:
    print(f"Grade {index}")
