#include <stdio.h>
#include <list/array_list.h>

#include <stdlib.h>
#include <string.h>

#define INCREASE_SIZE 256

void _add(dsc_array_list_t *self, const ptr item);
ptr _get(const dsc_array_list_t *self, const u64 index);
void _remove(dsc_array_list_t *self, const u64 index);

dsc_array_list_t dsc_create_array_list(u64 initial_capacity) {
    dsc_array_list_t array_list;

    array_list._capacity = initial_capacity;
    array_list._length = 0;
    array_list._data = malloc(initial_capacity * sizeof(ptr));

    array_list.add = _add;
    array_list.get = _get;
    array_list.remove = _remove;

    return array_list;
}

void _add(dsc_array_list_t *self, const ptr item) {
    if (self->_length + 1 == self->_capacity) {
        const u64 new_capacity = self->_capacity + (INCREASE_SIZE * sizeof(ptr));

        ptr *new_data = malloc(new_capacity);
        memmove(new_data, self->_data, self->_capacity);

        free(self->_data);
        self->_data = new_data;
        self->_capacity = self->_capacity + INCREASE_SIZE;
    }

    self->_data[self->_length] = item;
    self->_length++;
}

ptr _get(const dsc_array_list_t *self, const u64 index) {
    if (index >= self->_length) return nullptr;

    return self->_data[index];
}

void _remove(dsc_array_list_t *self, const u64 index) {
    if (index >= self->_length) return;

    if (index < self->_length - 1) {
        // TODO: Do not use for loop
        const u64 remainder = self->_length - index;

        for (u64 i = index, j = 0; j < remainder; j++) {
            self->_data[i + j] = self->_data[i + j + 1];
        }

        self->_data[self->_length - 1] = nullptr;
        self->_length--;
        return;
    }

    self->_data[index] = nullptr;
    self->_length--;
}