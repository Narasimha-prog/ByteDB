#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/input_buffer.h"

int main() {
    InputBuffer* input_buffer = new_input_buffer();
    
    while (1) {
        printf("byteDb > ");
        read_input(input_buffer);

        // Simple exit command
        if (strcmp(input_buffer->buffer, ".exit") == 0) {
            printf("Closing byteDb. Goodbye!\n");
            close_input_buffer(input_buffer);
            exit(EXIT_SUCCESS);
        } else {
            // Test output to verify the buffer is reading
            printf("You entered: '%s' (Length: %zd)\n", 
                   input_buffer->buffer, input_buffer->input_length);
        }
    }
    return 0;
}
