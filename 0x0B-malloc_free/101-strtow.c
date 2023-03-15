#include <stdlib.h>
#include <string.h>

char **strtow(char *str) {
    if (str == NULL || strlen(str) == 0) {
        return NULL;
    }

    // Count the number of words in the string
    int num_words = 0;
    char *token = strtok(str, " ");
    while (token != NULL) {
        num_words++;
        token = strtok(NULL, " ");
    }

    // Allocate memory for the array of words
    char **words = (char **)malloc((num_words + 1) * sizeof(char *));
    if (words == NULL) {
        return NULL;
    }

    // Copy each word into a separate string in the array
    int i = 0;
    token = strtok(str, " ");
    while (token != NULL) {
        words[i] = (char *)malloc((strlen(token) + 1) * sizeof(char));
        if (words[i] == NULL) {
            // Free memory for previously allocated strings
            for (int j = 0; j < i; j++) {
                free(words[j]);
            }
            free(words);
            return NULL;
        }
        strcpy(words[i], token);
        i++;
        token = strtok(NULL, " ");
    }

    words[num_words] = NULL; // Add NULL terminator to the end of the array
    return words;
}

