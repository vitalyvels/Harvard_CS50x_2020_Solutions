# Main Solution for readability.c

## Lessons learned
### - how to group global variables in code 
e.g. 
    int i, j, k, l, m, p, letters, words, sentences, nonsentence, found, text_length;
### - how to count letters in text through (in [countletters.c](https://github.com/vitalyvels/Harvard_CS50x_2020_Solutions/blob/master/02_Week_Arrays_In_C_Language/02.1.%20Readability.c/prerequisite_solutions/countletters.c))
    (1) low/highcase alphabet char array creation
    (2) imersed in loop for checking presence of letters in given text string char by char and count every letter
### - how to count words through (in [countwords.c](https://github.com/vitalyvels/Harvard_CS50x_2020_Solutions/blob/master/02_Week_Arrays_In_C_Language/02.1.%20Readability.c/prerequisite_solutions/countwords.c))
    (3) finding and counting spaces between words in given string of text
### - how to count sentences through (in []())
    (4) finding .!? in text string using loop and count 
    (5) and excluding specific words usually ended with '.' (e.g. Mr., Mrs. etc.)
### - how to find specific words to exclude from sentence count (e.g. Mr., Mrs. etc.) through (in [findwordintext.c](https://github.com/vitalyvels/Harvard_CS50x_2020_Solutions/blob/master/02_Week_Arrays_In_C_Language/02.1.%20Readability.c/prerequisite_solutions/findwordintext.c) and [words2array.c](https://github.com/vitalyvels/Harvard_CS50x_2020_Solutions/blob/master/02_Week_Arrays_In_C_Language/02.1.%20Readability.c/prerequisite_solutions/words2array.c))
    (6) putting exception words in char 2D array 
    (7) and using 3-level loop check presence the words in given text string
### - how to put functions out the main code through (in []())
    (8) right function declaration (e.g. int grade(void);)
    (9) right function definition (e.g. using return grade;)
    (10) right function call (e.g. grade();)
### - how to execute calculatios in C (in []())
    (11) some formulas got worked only after changing variables order 
    e.g.   
    didn't  worked: index = letters / words / 100 * 0.0588 - sentences / words * 0.296 - 15.8;
    but     worked: index = 5.88 * letters / words - 29.6 * sentences / words - 15.8;
### - how to make autotest out of code (in []())
    (12) using existing funtion calls 
    (13) using text char 2D arrays of tes text examples tied to resulting grade
    (14) comparing test and benchmark result grades
    (15) evaluating the difference of test results and digging into the details and cause
    (16) correct main code for minor unseen previousely algorithm mistakes (e.g. missing =0 for some loops)
### - how to debug code, find mistakes, functions, new code/algorithm solutions
### - how to use github, Jira and Confluence applying to the software project
### - how to comment, style the code, make code clear, effective and beautiful:)
