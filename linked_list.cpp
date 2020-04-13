//
// Created by Milagros Yupanqui on 4/12/20.
//

#include <iostream>
#include "linked_list.h"
using namespace std;


utec::first::linked_list_t::linked_list_t(const utec::linked_list_t &other) {
    if (size_ == 0) head_ = tail_ = nullptr;
    else {
        size_=1;
        auto actual = other.head_;
        head_=new node_t{actual->value_,nullptr};
        while (actual->next_ != nullptr) {
            actual = actual->next_;
            push_back(actual->value_);
        }
        push_back(actual->value_);
    }
}

utec::linked_list_t &utec::first::linked_list_t::operator=(const utec::linked_list_t &other) //constructor copia
{
    if(other.size_ == 0){
        head_ = tail_ = nullptr;
        size_ = 0;
        return *this;
    }
    else if(this == &other){
        return *this;
    }
    while(--size_)
        this->pop_front();
    for(int i=0;i<other.size_;++i){
        this->push_back(other.item(i));}

    size_=other.size_;
    return *this;

}

utec::first::linked_list_t::linked_list_t(utec::linked_list_t &&other) noexcept {
    size_ = move(other.size_);
    head_ = move(other.head_);
    tail_ = move(other.head_);
    other.size_ = 0;
    other.head_ = nullptr;
    other.tail_ = nullptr;

}

utec::linked_list_t &utec::first::linked_list_t::operator=(utec::linked_list_t &&other) noexcept {

    while(size_--) this->pop_back();

    head_ = move(other.head_);
    tail_ = move(other.tail_);
    size_ = move(other.size());
    other.head_ = nullptr;
    other.tail_ = nullptr;
    other.size_ = 0;

    return *this;
}

utec::first::linked_list_t::~linked_list_t() {
    while (size_!=0){
        pop_front();
        size_--;}
    head_ = tail_ = nullptr;
    size_ = 0;

}

void utec::first::linked_list_t::push_front(int value) {

    /*
    auto node = new node_t{value, head_}
    head_ = node;
    */
    head_ = new node_t{value, head_};
    if (tail_ == nullptr) tail_ = head_;
    size_++;

}

void utec::first::linked_list_t::push_back(int value) {
    auto nlast = new node_t{value, nullptr}; //create a new node(new tail or last node)
    if (head_ == nullptr) //if list is empty
    {head_=nlast; size_++;}
    else // if list is not empty
        {
        node_t *aux=head_; //temporary pointer pointing at head_ to start the traversing of the list
        while(aux->next_!=nullptr){ //traversing the list until the end identified by: next_==nullptr
            aux=aux->next_;
        }
        aux->next_=nlast;
        size_++;
    }
}


void utec::first::linked_list_t::pop_front() {

    if (head_ == tail_) {
        delete head_;
        head_ = tail_ = nullptr;
        size_ = 0;
    }
    else {
        auto next = head_->next_;
        delete head_;
        head_ = next;
        size_--;
    }
}

void utec::first::linked_list_t::pop_back() {

    if (head_ == tail_) {
        delete tail_;
        head_ = tail_ = nullptr;
        size_ = 0;
    }
    else{
        node_t *aux=head_;
        node_t *aux2=nullptr;
        while(aux->next_!=nullptr){ //traversing the list until the end identified by: next_==nullptr
            aux2=aux;
            aux=aux->next_;
        }
        aux2->next_=nullptr;
        delete aux;
        size_--;
    }
}

void utec::first::linked_list_t::erase(size_t index) {
    //particular cases
    if (head_ == tail_) {
        delete head_;
        head_ = tail_ = nullptr;
        size_ = 0;}
    else if (index==0)pop_front();
    else if (index==size_-1)pop_back();
    //in general
    else{
        auto aux = get_node(index + 1);
        delete get_node(index);
        get_node(index-1)->next_ = aux;
        //the memory address that the node (index-1) stores is now that of the node (index + 1), since the node (index) is removed.
        size_--;
    }
}

void utec::first::linked_list_t::insert(size_t index, int value) {
    if (index == 0)
        push_front(value);
    else if (index == size_)
        push_back(value);
    else if (head_ == tail_){
        head_ = new node_t{value, tail_};
        if (tail_ == nullptr) tail_ = head_;
    }
    else {
        get_node(index - 1)->next_ = new node_t{value, get_node(index)};
        size_++;
    }
}

int &utec::first::linked_list_t::item(size_t index) {
    auto actual = head_;
    while (index--)
        actual = actual->next_;
    return actual->value_;
}

const int &utec::first::linked_list_t::item(size_t index) const {
    auto actual = head_;
    while (index--)
        actual = actual->next_;
    return actual->value_;
}

size_t utec::first::linked_list_t::size() const {
    return size_;
}

utec::node_t *utec::first::linked_list_t::get_node(size_t index) {
    auto temp = head_;
    size_t i=0;
    while(i<index){
        temp=temp->next_;
        i++;}
    return temp;
}
