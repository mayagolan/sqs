/*
    First name     MAYA
    Last name      GOLAN
    Student ID     01529163
    Username       mg2118
*/

#include <iostream>

typedef int set_t;
// easier to keep the type more abstract
// (many operations would work also if
// a type other than int was used to define set_t)

struct set_int {
    int capacity; // physical size of the set (i.e. the maximum number of elements it can contain)
    int size;     // logical size of the set (i.e. the actual number of elements it contains)
    set_t *data;  // dynamic array containing the elements of the set
};

typedef set_int* setptr;
// more abstract, avoids cumbersome notations
// such as having to write set_int*& below

void set_init(setptr& s, int initial_capacity);
// Initialises a set with the given initial capacity and dynamically allocates its internal array data.
// The set contains no elements yet, and its size should be set to 0.

void set_copy(const setptr& original, setptr& copy);
// Copies the original set elements into the given copy set.
// (with appropriate memory allocation so that the original
// and the copy dont share the same internal dynamic array).
// The size and capacity of the copy set should naturally be initialised
// using the size and the capacity of the original set.

bool set_is_empty(const setptr& original);
// Returns true if the set is empty. Returns false otherwise.

int set_size(const setptr& s);
// Returns the size of a set.

int set_capacity(const setptr& s);
// Returns the capacity of a set.

bool set_is_valid(const setptr& s);
// Returns true if a set is valid, i.e. it does not contain any duplicated values.
// Returns false otherwise.

void set_print(const setptr& s);
// Prints all the elements of a set.
// (since there is no particular order among the elements of the set,
// you can simply print them as they are stored in the dynamic array data.)

void set_insert(setptr& s, const set_t& element);
// Inserts element into the set, making its internal array grow, potentially.
//
// If the set size reaches its capacity (i.e. if the set is full), then:
// 1) the dynamic array data should be re-allocated by doubling (x2) its capacity,
// 2) all the existing elements should be copied in the new array,
// 3) the new element is added to the new array,
// 4) the memory allocated for the old array should be released.
// size and capacity should also be updated accordingly.

void set_remove(setptr& s, const set_t& element);
// Removes element from the set.

bool set_contains(const setptr& s, const set_t& element);
// Returns true if the set contains element. Returns false otherwise.

set_t set_min_value(const setptr& s);
// Returns the minimum value of the set.

set_t set_max_value(const setptr& s);
// Returns the maximun value of the set.

set_t set_average_value(const setptr& s);
// Returns the average value of the set.

setptr set_intersection(const setptr& s1, const setptr& s2);
// Returns a set representing the Intersection of two sets
// (i.e. all the elements in both sets).
// e.g. the intersection of {1, 2, 3} and {3, 4} should be {3})

setptr set_union(const setptr& s1, const setptr& s2);
// Returns a set representing the Union of two sets
// (i.e. all the elements of the two sets, without any duplicates).
// e.g. the union of {1, 2, 3} and {3, 4} should be the set {1, 2, 3, 4}.

setptr difference(const setptr& s1, const setptr& s2);
// Returns a set representing the Difference between two sets
// (i.e. all the elements in one (s1 here), and not in the other (s2 here)).
// e.g. the union of s1={1, 2, 3} and s2={3, 4} should be {1, 2})

void set_deallocate(setptr s);
// Deallocates the memory of a set.
// you can define and add use additional functions if you might need to



///////////////////
// main function //
///////////////////

//IMPORTANT (Reminder): before submitting your source code, please make sure to comment your main function (needed for automated testing)

/////////////////////////////////////////////
// Functions definitions (implementations) //
/////////////////////////////////////////////
/*
int main() {
    std::cout<<"Testing of set functions"<<std::endl;
    setptr setA = new set_int;
    //Test init
    set_init(setA,3);
    std::cout<<"size: "<<set_size(setA)<<" capacity: "<<set_capacity(setA)<<std::endl;
    std::cout<<"is set empty? "<<set_is_empty(setA)<<std::endl;
    set_insert(setA,2);
    set_insert(setA,4);
    set_insert(setA,2);
    set_insert(setA,5);

    std::cout<<"is set empty? "<<set_is_empty(setA)<<std::endl;
    set_print(setA);
    std::cout<<"set contains 1: "<<set_contains(setA,1)<<" set doesn't contain 6: "<<set_contains(setA,6)<<std::endl;
    std::cout<<"size: "<<set_size(setA)<<" capacity: "<<set_capacity(setA)<<std::endl;
    set_insert(setA,3);
    set_remove(setA,2);
    
    std::cout<<"hello"<<std::endl;
    
    set_insert(setA,12);
    set_insert(setA,334);
    set_insert(setA,7);
    std::cout<<"Maximum Value: "<<set_max_value(setA)<<std::endl;
    std::cout<<"Minimum Value: "<<set_min_value(setA)<<std::endl;
    std::cout<<"Average value: "<<set_average_value(setA)<<std::endl;
    set_print(setA);
    std::cout<<"size: "<<set_size(setA)<<" capacity: "<<set_capacity(setA)<<std::endl;

    setptr setB = new set_int;
    //Test init
    set_init(setB,5);
    set_insert(setB,334);
    set_insert(setB,60);
    set_insert(setB,3);
    set_insert(setB,9);
    set_insert(setB,1);
    set_print(setB);

    set_print(set_intersection(setA,setB));
    set_print(set_union(setA,setB));
    set_print(difference(setA,setB));
    set_print(difference(setB,setA));
    return 1;
}
*/



// YOUR CODE HERE

void set_deallocate(setptr s){
    delete s->data;
    delete s;
}

void set_init(setptr& s, int initial_capacity){
    s->size=0;
    s->capacity=initial_capacity;
    s->data = new int[initial_capacity];
}

void set_copy(const setptr& original, setptr& copy){
    set_init(copy, original->capacity);
    copy->size=original->size;
    for(int i =0; i<original->capacity;i++){
        copy->data[i] = original->data[i];
    }
}

bool set_is_empty(const setptr& original){
    return (original->size==0);
}

int set_size(const setptr& s){
    return s->size;
}

int set_capacity(const setptr& s){
    return s->capacity;
}

bool set_is_valid(const setptr& s){
    bool result = true;
    for (int i = 0; i<s->size-1; i++){
        for (int j =i+1; j<s->size; j++){
            if (s->data[i] == s->data[j]){
                result = false;
            }
        }
    }

    return result;
}

void set_print(const setptr& s){
    for (int i=0; i<s->size; i++){
        std::cout<<s->data[i]<<" ";
    }
    std::cout<<std::endl;
}
void set_insert(setptr& s, const set_t& element){
    if (set_contains(s,element)){
        return;
    } else if (s->size>=s->capacity){
        set_t* doubled_list = new int[s->capacity*2];
        for (int i = 0; i<s->capacity;i++){
            doubled_list[i] = s->data[i];
        }
        doubled_list[s->capacity] = element;
        set_t* old_array = s->data;
        s->data = doubled_list;
        delete old_array;
        s->capacity = s->capacity*2;
        s->size += 1;
    } else {
        s->data[s->size] = element;
        s->size += 1;
    }
}

bool set_contains(const setptr& s, const set_t& element){
    for (int i = 0; i<s->size; i++){
        if (s->data[i] == element){
            return true;
        }
    }
    return false;
}

void set_remove(setptr& s, const set_t& element){
    int size=set_size(s);
    if (set_contains(s,element)){
        for(int i = 0;i<size;i++){
            if (s->data[i] == element){
                for(int j = 0; j<size-1-i;j++){
                    s->data[i+j] = s->data[i+j+1];
                }
                s->size-=1;
             //   return;
            }
        }
    }
}

set_t set_min_value(const setptr& s){
    set_t minimum = INT32_MAX;
    for(int i =0; i<s->size;i++){
        if (s->data[i] < minimum){
            minimum = s->data[i];
        }
    }
    return minimum;

}

set_t set_max_value(const setptr& s){
    set_t maximum = INT32_MIN;
    for(int i =0; i<s->size;i++){
        if (s->data[i] > maximum){
            maximum = s->data[i];
        }
    }
    return maximum;
}

set_t set_average_value(const setptr& s){
    int sum = 0;
    for (int i = 0; i<s->size; i++){
        sum += s->data[i];
    }
    return sum/s->size;
}

setptr set_intersection(const setptr& s1, const setptr& s2){
    setptr intersection = new set_int;
    int size;
    if (s1->size>s2->size){
        size = s1->size;
    } else {
        size = s2->size;
    }
    set_init(intersection,size);
    for (int i = 0; i<s1->size; i++){
        if (set_contains(s2, s1->data[i])){
            set_insert(intersection,s1->data[i]);
        }
    }
    return intersection;
}

setptr set_union(const setptr& s1, const setptr& s2){
    setptr union_set = new set_int;
    set_init(union_set,s1->size+s2->size);
    for (int i = 0; i<s1->size;i++){
        set_insert(union_set,s1->data[i]);
    }
    for (int i = 0; i<s2->size;i++){
        if (!set_contains(union_set,s2->data[i])){
            set_insert(union_set,s2->data[i]);
        }
    }
    return union_set;
}

setptr difference(const setptr& s1, const setptr& s2){
    setptr difference = new set_int;
    set_init(difference,s1->size);

    for(int i = 0; i<s1->size; i++){
        if(!set_contains(s2,s1->data[i])){

            set_insert(difference,s1->data[i]);
        }
    }
    return difference;
}
