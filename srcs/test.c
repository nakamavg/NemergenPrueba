#include "nemergent.h"
#include "linked_list.h"
#include "test.h"
#include "numbers.h"
#include <stdlib.h>

void test_read_config_file_not_found() {
    Config config = read_config("no_existe.txt");
    assert(config.valid == 0);
}
void test_read_config_file_empty() {
    Config config = read_config("empty.txt");
    assert(config.valid == 0);
}
void test_read_config_file_invalid() {
    Config config = read_config("invalid.txt");
    assert(config.valid == 0);
}
void test_read_config_file_valid() {
    Config config = read_config("archivo.txt");
    assert(config.valid == 1);
    assert(config.numbers_per_thread == 6);
    assert(config.thread_num == 2);
}
void test_without_txt_extension() {
    Config config = read_config("archivo");
    assert(config.valid == 0);
}
void test_create_list() {
    Node *head = create_node(42);
    printf("test_crearte_list : %d\n",head->data);
    assert(head != NULL);
    assert(head->next == NULL);
    free_list(head);
}
void test_add_node(){
    Node *head = create_node(42);
    head = add_node(head, 43);
    assert(head != NULL);
    assert(head->next != NULL);
    assert(head->next->data == 43);
    free_list(head);
}

void test_print_list() {
    Node *head = create_node(42);
    head = add_node(head, 43);
    head = add_node(head, 44);
    print_list(head);
    free_list(head);
}
void test_generate_unique_numbers() {
    int count = 10;
    int *numbers = generate_unique_numbers(count);
    assert(numbers != NULL);
    for (int i = 0; i < count; i++) {
        assert(numbers[i] >= 0 && numbers[i] < 1000);
        printf("test_generate_unique_numbers : %d\n",numbers[i]);
        for (int j = i + 1; j < count; j++) {
            assert(numbers[i] != numbers[j]);
        }
    }
    free(numbers);
}


