#include <stdio.h>
#include "helpers/vector.h"
#include "helpers/buffer.h"
#include "compiler.h"

void test_vector_create() {
    printf("Testing vector_create()...\n");
    vector *v = vector_create();
    if (!v) {
        printf("vector_create() failed!\n");
    } else {
        printf("vector_create() success.\n");
    }
}

void test_vector_push() {
    printf("Testing vector_push()...\n");
    vector *v = vector_create();
    vector_push(v, (void*)1);
    vector_push(v, (void*)2);
    vector_push(v, (void*)3);
    printf("Vector push success.\n");
}

void test_vector_pop() {
    printf("Testing vector_pop()...\n");
    vector *v = vector_create();
    vector_push(v, (void*)1);
    void *popped = vector_pop(v);
    printf("Popped value: %ld\n", (long)popped);
}

void test_vector_set_peek_pointer() {
    printf("Testing vector_set_peek_pointer()...\n");
    vector *v = vector_create();
    vector_push(v, (void*)1);
    vector_set_peek_pointer(v, 0);
    printf("Peek pointer set successfully.\n");
}

void test_vector_peek() {
    printf("Testing vector_peek()...\n");
    vector *v = vector_create();
    vector_push(v, (void*)1);
    vector_set_peek_pointer(v, 0);
    void *peeked = vector_peek(v);
    printf("Peeked value: %ld\n", (long)peeked);
}

void test_compile_file() {
    printf("Testing compile_file()...\n");
    int result = compile_file("test.c");
    if (result == 0) {
        printf("Compilation successful!\n");
    } else {
        printf("Compilation failed with code: %d\n", result);
    }
}

void run_tests() {
    test_vector_create();
    test_vector_push();
    test_vector_pop();
    test_vector_set_peek_pointer();
    test_vector_peek();
    test_compile_file();
}
