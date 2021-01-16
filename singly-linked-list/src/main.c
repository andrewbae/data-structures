#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

struct Node {
	struct Node *fd;
	uint8_t data[10];
};

static struct Node * node_init()
{
	struct Node *node = malloc(sizeof(struct Node));
	memset(node, (uint8_t)0x00, sizeof(struct Node));	
	return node;
}

static struct Node * node_push(struct Node *node_prev, uint8_t *data)
{
	// create new node then linking
	struct Node *node = node_init();
	memcpy(node->data, data, sizeof(node->data));
	node_prev->fd = node;
	return node;
}

static struct Node * node_pop(struct Node *node_head, uint16_t index) 
{
	struct Node *node = node_head->fd; 
	for(uint16_t i = 0; (index != i && i < 0xffff); ++i){
		node = node->fd;
	}
	return node;
}

static uint8_t node_delete(struct Node *node_head, uint16_t index) 
{
	struct Node *prev_node = node_head->fd; 
	struct Node *next_node;
	for(uint16_t i = 0; ((index - 1) != i && i < 0xffff); ++i){
		prev_node = prev_node->fd;
	}
	next_node = (prev_node->fd)->fd;	
	prev_node->fd = next_node;
	memset(prev_node->fd, (uint8_t)0x00, sizeof(struct Node));

	return EXIT_SUCCESS;
}

static uint8_t node_info(struct Node * node_head)
{
	struct Node *node = node_head->fd;
	for(uint8_t i = 0; node != (void*)0x00; ++i){
		printf("index: %d\n", i);
		printf("fd: %p\n", node->fd);
		printf("addr: %p\n", node);
		printf("data: %s\n\n", node->data);
		node = node->fd;
	}
	return EXIT_SUCCESS;
}

int main()
{
	struct Node *node_head = node_init();
	struct Node *node_prev = node_head;
	
	uint8_t data[10] = "fuck";
	for(uint8_t i = 0; i < 5; ++i) {
		struct Node *node = node_push(node_prev, data);
		node_prev = node;
	}
	node_info(node_head);
	printf("%p", node_pop(node_head, 0x2));
	node_delete(node_head, 0x3);
	node_info(node_head);
	return 0;
}
