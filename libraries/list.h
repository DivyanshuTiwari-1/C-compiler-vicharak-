#include <stddef.h>
#ifndef _LIST_H
#define _LIST_H
class List{
    private:
    void **items;
    size_t size;
    size_t item_size;
    public:
    List(size_t);
    void list_push(void*);
    void *getItems(int i){ return this->items[i];}
    size_t getSize(){ return this->size;}
};
#endif
