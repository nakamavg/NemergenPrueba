#include "nemergent.h"
#include "linked_list.h"
#include "test.h"

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
    printf("%d",head->data);
    assert(head != NULL);
    assert(head->next == NULL);
    free_list(head);
}
void test_add_node(){
    Node *head = create_node(42);
    head = add_node(head, 43);
    assert(head != NULL);
    assert(head->next != NULL);
    assert(head->next->data == 1);
    free_list(head);
}



