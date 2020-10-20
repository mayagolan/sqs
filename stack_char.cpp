/*
    First name     MAYA
    Last name      GOLAN
*/

#include <iostream>

typedef char stack_t;
// easier to keep the type more abstract
// (many operations would work also if
// a type other than char was used to define stack_t)

struct stacknode {
    stack_t data;
    stacknode *next;
};

typedef stacknode* stackptr;
// more abstract, avoids cumbersome notations
// such as having to write stacknode*& below

void stack_push(stack_t item, stackptr& s);
// Adds an item to a stack (we pass a pointer to the top of the stack)

stack_t stack_pop(stackptr& s);
// Returns the top item of a stack (and removes it from the stack)

stackptr stack_copy(const stackptr& original);
// Returns a copy of an existing stack
// (with appropriate memory allocation so that the original
// and the copy don't point to the same memory)

void stack_print(const stackptr& s);
// Prints the items of a stack

int stack_length(const stackptr& s);
// Returns the length (can also be called the height) of a stack

bool stack_is_empty(const stackptr& s);
// Returns true if a stack is empty. Returns false otherwise.

void stack_deallocate(stackptr& s);
// Deallocates the memory of a stack


/*
int main(){
    stackptr la=NULL;
    stackptr lb=NULL;
    stackptr lc=NULL;

    int n1, n2, length, position;
    stack_t el, search;

    ///////////////// LIST 1 /////////
    std::cout<<"how many elements for LIST 1?"<<std::endl;
    std::cin>>n1;
    for(int i=0; i<n1;i++){
        std::cout<<"enter element: "<<i+1<<std::endl;
        std::cin>>el;
        stack_push(el, la);
        stack_push(el, lb);//pass in the current element, return the next
        // lb=consret(el, lb);               //print out lb which is
    }

    stack_print(la);
    lc = stack_copy(la);
    std::cout<<"LIST 2 length is: "<< stack_length(lc) <<std::endl;
    stack_print(lc);
    stack_pop(la);
    stack_print(la);
    stack_print(lb);
    return 0;
}
*/


void stack_push(stack_t item, stackptr& s){
    stackptr tmpp= new stacknode;
    tmpp->data=item;
    tmpp->next=s;
    s=tmpp;
}

stack_t stack_pop(stackptr& s){
    stackptr tmp = s;
    s=s->next;
    return tmp->data;
}

stackptr stack_copy(const stackptr& original){
    stackptr copy_node = new stacknode;
    stackptr current_node = original;
    const stackptr top_of_stack = copy_node;

    copy_node->data = current_node->data;
    current_node = current_node->next;

    while(current_node != NULL) {
        copy_node->next = new stacknode;
        copy_node = copy_node->next;
        copy_node->data = current_node->data;
        current_node = current_node->next;
        copy_node->next = NULL;

    }
    return top_of_stack;
}


void stack_print(const stackptr& s){
    stackptr tmp=s;
    while(tmp!=NULL){
        std::cout<<tmp->data<<" ";
        tmp=tmp->next;
    }
    std::cout<<std::endl;
}

void stack_deallocate(stackptr& s){
    while (s != NULL){
        stackptr nexts = s->next;
        delete s;
        s=nexts;
    }
}

int stack_length(const stackptr& s){
    stackptr tmp=s;
    int n=0;
    while (tmp != NULL){
        stackptr nexts = tmp->next;
        tmp=nexts;
        n++;
    }
    return n;
}

bool stack_is_empty(const stackptr& s){
    if( s == NULL){
        return 1;
    }
    else{
        return 0;
    }
}
