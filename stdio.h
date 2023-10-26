#ifndef STDIO_H
#define STDIO_H

// File operations
typedef struct {
    // File structure (implementation-specific)
} FILE;

#define stdin  ((FILE *) 0)
#define stdout ((FILE *) 1)
#define stderr ((FILE *) 2)

// Standard input/output functions
int printf(const char *format, ...);
int scanf(const char *format, ...);

// File operations functions
FILE *fopen(const char *filename, const char *mode);
int fclose(FILE *stream);
int fprintf(FILE *stream, const char *format, ...);
int fscanf(FILE *stream, const char *format, ...);

#endif // STDIO_H