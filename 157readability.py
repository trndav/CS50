
# Problem set 6.
# TODO
# Calculate Coleman-Liau formula on input text
# L = average number of letters per 100 words
# S = average number of sentences per 100 words
# grade = 0.0588 * L - 0.296 * S - 15.8

import string
text = input("Enter your input to calculate text score: ")

#Count letters
def count_letter(text):
    letter_count = 0
    for char in text:
        if char.isalpha():
            letter_count += 1
    return letter_count

# Count words
def count_words(text):
    translator = str.maketrans("", "", string.punctuation)
    text_without_punctuation = text.translate(translator)
    words = text_without_punctuation.split()
    return len(words)

# Count sentences
def count_sentences(text):
    sentence_endings = [".", "!", "?"]
    sentence_count = 0
    for sentence in text:
        if sentence in sentence_endings:
            sentence_count += 1
    return sentence_count

# Count letters
characters = count_letter(text)

# Count words
words = count_words(text)

# Count sentences
sentences = count_sentences(text)

# L = average number of letters per 100 words
l = float(characters) / float(words)*100

# S = average number of sentences per 100 words
s = float(sentences) / float(words)*100

# grade = 0.0588 * L - 0.296 * S - 15.8
grade = 0.0588 * l - 0.296 * s - 15.8
round_grade = round(grade)
print(f"Grade {round_grade}")

if round_grade > 16:
    print(f"Grade 16+")

if round_grade < 1:
    print(f"Before Grade 1")
