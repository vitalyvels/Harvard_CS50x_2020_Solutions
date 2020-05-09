# Main Solution for caesar.c

## Lessons learned
### - how to convert char variables into integer ones using atoi() from stlib.h library
e.g. 
    atoi(args[1]) <= 0;
    k = atoi(args[1]) % 26;
### - how to simply check if is(not) alphabet in string using isalpha() from ctype.h library
e.g. 
    if (!isalpha(text[i]))
### - how to check UPPERcased letters in string using isupper() from ctype.h library
e.g. 
    int ascii_offset = isupper(text[i]) ? 65 : 97;

