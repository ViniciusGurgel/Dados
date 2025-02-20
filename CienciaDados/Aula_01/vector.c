#include "vector.h"
#include <stdlib.h>
#include <stdio.h>

vector *vector_create() {
    vector *v = malloc(sizeof(vector));
    if (!v) return NULL;
    v->data = malloc(10 * sizeof(void *));
    if (!v->data) {
        free(v);
        return NULL;
    }
    v->size = 0;
    v->capacity = 10;
    v->peek_index = 0;
    return v;
}

void vector_push(vector *v, void *item) {
    if (v->size >= v->capacity) {
        v->capacity *= 2;
        v->data = realloc(v->data, v->capacity * sizeof(void *));
    }
    v->data[v->size++] = item;
}

void *vector_pop(vector *v) {
    if (v->size == 0) return NULL;
    return v->data[--v->size];
}

void vector_set_peek_pointer(vector *v, size_t index) {
    if (index < v->size) {
        v->peek_index = index;
    }
}

void *vector_peek(vector *v) {
    if (v->size == 0) return NULL;
    return v->data[v->peek_index];
}

void vector_free(vector *v) {
    if (v) {
        free(v->data);
        free(v);
    }
}

// ✅ Test functions for vector
void test_vector_create() {
    printf("Testing vector_create()...\n");
    vector *v = vector_create();
    if (!v) {
        printf("vector_create() failed!\n");
    } else {
        printf("vector_create() success.\n");
        vector_free(v);
    }
}

void test_vector_push() {
    printf("Testing vector_push()...\n");
    vector *v = vector_create();
    vector_push(v, (void*)1);
    vector_push(v, (void*)2);
    printf("Vector push success. Size: %lu\n", v->size);
    vector_free(v);
}

void test_vector_pop() {
    printf("Testing vector_pop()...\n");
    vector *v = vector_create();
    vector_push(v, (void*)1);
    void *popped = vector_pop(v);
    printf("Popped value: %ld\n", (long)popped);
    vector_free(v);
}

void test_vector_set_peek_pointer() {
    printf("Testing vector_set_peek_pointer()...\n");
    vector *v = vector_create();
    vector_push(v, (void*)1);
    vector_set_peek_pointer(v, 0);
    printf("Peek pointer set successfully.\n");
    vector_free(v);
}

void test_vector_peek() {
    printf("Testing vector_peek()...\n");
    vector *v = vector_create();
    vector_push(v, (void*)1);
    vector_set_peek_pointer(v, 0);
    void *peeked = vector_peek(v);
    printf("Peeked value: %ld\n", (long)peeked);
    vector_free(v);
}

void run_vector_tests() {
    test_vector_create();
    test_vector_push();
    test_vector_pop();
    test_vector_set_peek_pointer();
    test_vector_peek();
}
