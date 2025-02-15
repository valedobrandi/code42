#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

// Structure to store dictionary entries
typedef struct s_dict_entry {
    char *key;   // The number as a string
    char *value; // The corresponding text
} t_dict_entry;

// Function to parse the dictionary file and store entries in an array
// - Open the file
// - Read line by line
// - Extract key (number) and value (text)
// - Remove extra spaces
// - Store in a dynamically allocated array
// - Return pointer to the array of entries
// - If an error occurs, print "Dict Error" and exit
// - Ensure memory is properly allocated and freed
 t_dict_entry *parse_dictionary(char *filename);

// Function to find a value in the dictionary based on a given number
// - Search the dictionary array for the matching key
// - If found, return the corresponding text
// - If not found, return NULL
char *find_in_dict(t_dict_entry *dict, char *number);

// Function to decompose a number and construct its text representation
// - If number is directly in dictionary, return it
// - Otherwise, break down the number (e.g., "54" -> "50" + "4")
// - Recursively build the text from known values
// - Handle special cases like "1000", "1000000"
char *convert_number(t_dict_entry *dict, char *number);

// Function to check if a string is a valid positive number
// - Ensure all characters are digits
// - Return 1 if valid, 0 otherwise
int is_valid_number(char *str);

// Function to free allocated memory for dictionary entries
// - Loop through dictionary array
// - Free key and value
// - Free the dictionary array itself
void free_dictionary(t_dict_entry *dict);

// Main function
// - Parse the dictionary (default or custom if provided)
// - Validate the input number
// - Convert the number to text
// - Print the result
// - Free allocated memory
int main(int argc, char **argv);
