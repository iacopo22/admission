# CS50x — Introduction to Computer Science (Harvard)

My solutions to the problem sets of Harvard's **CS50x: Introduction to Computer Science**, completed as self-study. The course builds up from low-level programming in C to higher-level work in Python, SQL, and web development, and doubles as a hands-on introduction to data structures and algorithms.

## What's here

The projects are written in **C, Python, SQL, and HTML/CSS**, covering the full CS50x curriculum:

### C — memory, algorithms, and data structures
- **`speller`** — a spell-checker that loads a dictionary into a **hash table with linked-list chaining**, using manual memory management (`malloc`/`free`). The core data-structures project of the course.
- **`filter-less` / `filter-more`** — image filters (grayscale, sepia, reflection, blur, and edge detection) that recompute each pixel from its neighbours in a bitmap.
- **`recover`** — recovers deleted JPEGs from a raw memory-card image by parsing the file 512-byte block at a time.
- **`cash` / `credit`** — greedy algorithms and card-number validation (Luhn's algorithm).
- **`sort`** — empirical comparison of sorting algorithms on different input orderings.
- **`runoff` / `plurality`** — voting systems implementing different tabulation rules.
- **`substitution` / `caesar`** — classic substitution and Caesar ciphers.
- **`inheritance`** — recursion and dynamic memory to simulate genetic inheritance.
- Plus smaller exercises: `mario`, `readability`, `scrabble`, `volume`, `world`.

### Python
- **`dna`** — identifies individuals by matching Short Tandem Repeat (STR) counts against a DNA database.
- **`sentimental-*`** — Python re-implementations of earlier C problems (`hello`, `cash`, `credit`, `readability`, `mario`), illustrating the transition from C to a higher-level language.

### SQL
- **`songs` / `movies`** — querying relational databases with joins, aggregation, and nested queries.
- **`fiftyville`** — a mystery solved entirely through a sequence of SQL queries over a crime database.

### Web (HTML / CSS / Flask)
- **`birthdays`** — a small **Flask** web app backed by SQLite, storing and displaying records through templates.
- **`homepage` / `trivia`** — front-end pages built with HTML and CSS.

## Skills demonstrated
- Low-level programming in C: pointers, dynamic memory allocation, file I/O, and structs.
- Core data structures and algorithms: hash tables, linked lists, sorting, and recursion.
- Relational databases and SQL querying.
- Basic web development with Flask, HTML, and CSS.

## Note
These are my own solutions, shared as a portfolio of completed work. If you are currently taking CS50x, please follow the course's [academic honesty policy](https://cs50.harvard.edu/x/honesty/) and write your own.
