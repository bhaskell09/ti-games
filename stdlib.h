#ifndef STDLIB_H
#define STDLIB_H

// Numeric conversion functions
int atoi(const char *str);
double atof(const char *str);
long int atol(const char *str);

// Memory allocation functions
void *malloc(size_t size);
void free(void *ptr);

// Exit function
void exit(int status);

#endif // STDLIB_H