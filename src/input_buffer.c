#include <stdio.h>
#include <stdlib.h>
#include "input_buffer.h"

/**
 * Creates a new InputBuffer and initializes its values.
 */
InputBuffer* new_input_buffer() {
    InputBuffer* input_buffer = (InputBuffer*)malloc(sizeof(InputBuffer));
    input_buffer->buffer = NULL;
    input_buffer->buffer_length = 0;
    input_buffer->input_length = 0;

    return input_buffer;
}

/**
 * Reads a line of input from the user (stdin).
 */
void read_input(InputBuffer* input_buffer) {
    // getline handles memory allocation if buffer is NULL
    ssize_t bytes_read = getline(&(input_buffer->buffer), &(input_buffer->buffer_length), stdin);

    if (bytes_read <= 0) {
        printf("Error reading input\n");
        exit(EXIT_FAILURE);
    }

    // Ignore trailing newline by setting it to 0 (null terminator)
    input_buffer->input_length = bytes_read - 1;
    input_buffer->buffer[bytes_read - 1] = 0;
}

/**
 * Frees the memory used by the InputBuffer to prevent leaks.
 */
void close_input_buffer(InputBuffer* input_buffer) {
    free(input_buffer->buffer);
    free(input_buffer);
}
