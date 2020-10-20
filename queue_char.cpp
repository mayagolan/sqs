/*
    First name     MAYA
    Last name      GOLAN
*/

#include <iostream>

typedef char queue_t;
// easier to keep the type more abstract
// (many operations would work also if
// a type other than char was used to define queue_t)

// do not alter the struct declaration
struct queuenode {
    queue_t data;
    queuenode *next;
};

// do not alter the typedef
typedef queuenode* queueptr;
// more abstract, avoids cumbersome notations
// such as having to write queuenode*& below

/////////////////////////////////////////
// Functions declarations (prototypes) //
/////////////////////////////////////////

// do not alter these functions declarations

void queue_push(queue_t item, queueptr& s);
// Adds an item to the back of a queue (we pass a pointer to the front of the queue)

///////////////////////////////////////////////////
// CHANGES IN THE SPECS
//    queue_t queue_pop(queueptr& s); // DEPRECATED. See queue_pop() and queue_front().
//    // Returns the first item (i.e. the front) of a queue (and removes it from the queue)

void queue_pop(queueptr& s);
// Removes the first item (i.e. at the front) of a queue

queue_t & queue_front(const queueptr& s);
// Returns the first item (i.e. at the front) of a queue (without removing it)

// END OF THE CHANGES.
///////////////////////////////////////////////////

queueptr queue_copy(const queueptr& original);
// Returns a copy of an existing queue
// (with appropriate memory allocation so that the original
// and the copy don't point to the same memory)

void queue_print(const queueptr& s);
// Prints the items of a queue

int queue_length(const queueptr& s);
// Returns the length (can also be called the height) of a queue

bool queue_is_empty(const queueptr& s);
// Returns true if a queue is empty. Returns false otherwise.

void queue_deallocate(queueptr& s);
// Deallocates the memory of a queue

// you can define and add use additional functions if you might need to

///////////////////
// main function //
///////////////////

//IMPORTANT (Reminder): before submitting your source code, please make sure to comment your main function (needed for automated testing)

/*
 int main(){
    queueptr Queue1 = NULL;
 
    int n1;
    char el;
 
    std::cout<<"how many elements for Queue 1?"<<std::endl;
    std::cin>>n1;
    for(int i=0; i<n1;i++) {
        std::cout << "enter element: " << i + 1 << std::endl;
        std::cin >> el;
        queue_push(el, Queue1);
    }
    std::cout<<"This is your list: ";
    queue_print(Queue1);
    std::cout<<"This is the first item: "<<queue_front(Queue1)<<std::endl;
    std::cout<<"Is queue empty? Result: "<<queue_is_empty(Queue1)<<std::endl;
    std::cout<<"This is the length: "<<queue_length(Queue1)<<std::endl;
    queueptr Queue2 = queue_copy(Queue1);
    std::cout<<"Copying the queue Removing something: ";
    queue_pop(Queue1);
    queue_print(Queue1);
    std::cout<<"Copied queue remains untouched: ";
    queue_print(Queue2);
    std::cout<<"Even when original is deallocated: ";
    queue_deallocate(Queue1);
    queue_print(Queue2);
    std::cout<<"Is deallocated queue empty now? Result: "<<queue_is_empty(Queue1)<<std::endl;
 
 
 
    return 0;
}
*/

/////////////////////////////////////////////
// Functions definitions (implementations) //
/////////////////////////////////////////////

// YOUR CODE HERE

void queue_push(queue_t item, queueptr& s){
    queueptr temp = new queuenode;
    temp->data = item;
    temp->next = NULL;

    if (queue_is_empty(s)){
        s = temp;
    } else{
        queueptr current_node = s;
        while(current_node->next!=NULL){
            current_node = current_node->next;
        }
        current_node->next = temp;
    }

}

void queue_pop(queueptr& s){
    s = s->next;
}

queue_t & queue_front(const queueptr& s){
    return s->data;
}

queueptr queue_copy(const queueptr& original){
    queueptr current_node = original;
    queueptr copied_queue = NULL;
    while(current_node!=NULL){
        queue_push(current_node->data, copied_queue);
        current_node=current_node->next;
    }
    return copied_queue;
}

void queue_print(const queueptr& s){
    queueptr temp=s;
    while(temp!=NULL){
        std::cout<<temp->data<<" ";
        temp=temp->next;
    }
    std::cout<<std::endl;
}

int queue_length(const queueptr& s){
    queueptr temp=s;
    int n=0;
    while (temp != NULL){
        temp = temp->next;
        n++;
    }
    return n;
}

bool queue_is_empty(const queueptr& s){
    return (s==NULL);
}

void queue_deallocate(queueptr& s){
    while (s != NULL){
        queueptr next_node = s->next;
        delete s;
        s=next_node;
    }
}

/*int main(){
    queueptr Queue1 = NULL;

    int n1;
    char el;

    std::cout<<"how many elements for Queue 1?"<<std::endl;
    std::cin>>n1;
    for(int i=0; i<n1;i++) {
        std::cout << "enter element: " << i + 1 << std::endl;
        std::cin >> el;
        queue_push(el, Queue1);
    }
    std::cout<<"This is your list: ";
    queue_print(Queue1);
    std::cout<<"This is the first item: "<<queue_front(Queue1)<<std::endl;
    std::cout<<"Is queue empty? Result: "<<queue_is_empty(Queue1)<<std::endl;
    std::cout<<"This is the length: "<<queue_length(Queue1)<<std::endl;
    queueptr Queue2 = queue_copy(Queue1);
    std::cout<<"Copying the queue Removing something: ";
    queue_pop(Queue1);
    queue_print(Queue1);
    std::cout<<"Copied queue remains untouched: ";
    queue_print(Queue2);
    std::cout<<"Even when original is deallocated: ";
    queue_deallocate(Queue1);
    queue_print(Queue2);
    std::cout<<"Is deallocated queue empty now? Result: "<<queue_is_empty(Queue1)<<std::endl;



    return 0;
}
*/
