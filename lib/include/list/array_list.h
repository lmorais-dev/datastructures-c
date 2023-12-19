#pragma once

#include <types.h>

typedef struct dsc_array_list_s {
    u64 _capacity;
    u64 _length;

    ptr *_data;

    void (*add)(struct dsc_array_list_s *self, const ptr item);
    ptr (*get)(const struct dsc_array_list_s *self, const u64 index);
    void (*remove)(struct dsc_array_list_s *self, const u64 index);
} dsc_array_list_t;

dsc_array_list_t dsc_create_array_list(u64 initial_capacity);