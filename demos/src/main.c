#include <lib.h>
#include <stdio.h>

#include <stdlib.h>

int main(int argc, i8 **argv) {
    u8 num_a = 10;
    u8 num_b = 20;
    u8 num_c = 30;
    u8 num_d = 40;

    dsc_array_list_t list = dsc_create_array_list(1);
    list.add(&list, &num_a); // Index 0
    list.add(&list, &num_b); // Index 1
    list.add(&list, &num_c); // Index 2
    list.add(&list, &num_d); // Index 3

    u8 *x_num_b = list.get(&list, 1);
    u8 *x_num_c = list.get(&list, 2);

    list.remove(&list, 1);

    for (u8 i = 0; i < list._length; i++) {
        printf("%d: %d\n", i, *((u8 *) list.get(&list, i)));
    }

    return 0;
}
