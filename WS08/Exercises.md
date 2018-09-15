# Workshop 8 Exercises

## Discuss:

People have titles, a given name, a middle name, and a family name, all of up to 50 characters each. People also have dates of birth (dd/mm/yyyy), dates of marriage and divorce (as many as 10 of each), and dates of death (with a flag to indicate whether or not they are dead yet). Each date of marriage is accompanied by the name of a person. Assuming that people work for less than 100 years each, people also have, for each year they worked, a year (yyyy), a net income and a tax liability (both rounded to whole dollars), and a date when that tax liability was paid. Countries are collections of people. Australia is expected to contain as many as 30,000,000 people; New Zealand as many as 6,000,000 people. 

### Exercise 1 

Give declarations that reflect the data scenario that is described. 

### Exercise 2 

Write a function that calculates, for a specified country indicated by a pointer argument (argument 1) with a number of persons in it (argument 2), the average age of death. Do not include people that are not yet dead.

### Exercise 3 

Write a function that calculates, for the country indicated by a pointer argument (argument 1) with a number of persons in it (argument 2) the total taxation revenue in a specified year (argument 3) 


## Implement:
### Exercise 4 

Write a function `char *string_dupe(char *s)` that creates a copy of the string s and returns a pointer to it. 

### Exercise 5 

Write a function `char **string_set_dupe(char **S)` that creates a copy of the set of string pointers `S`, assumed to have the structure of the set of strings in `argv` (including a sentinel pointer of `NULL`), and returns a pointer to the copy. 

### Exercise 6 

Write a function `void_string_set_free(char **S)` that returns all of the memory associated with the duplicated string set `S`. 

### Exercise 7 

Test all three of your functions by writing scaffolding that duplicates the argument argv, then prints the duplicate out, then frees the space. (What happens if you call string set free(argv)? Why?) 