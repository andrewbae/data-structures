#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <unistd.h>

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
	return 0;
}
