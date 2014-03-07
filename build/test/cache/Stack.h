





typedef struct Stack_t{

 void *head;

 void *tail;

}Stack;



void Stack_push(Stack *stack, void *element);

void *Stack_pop(Stack *stack);
