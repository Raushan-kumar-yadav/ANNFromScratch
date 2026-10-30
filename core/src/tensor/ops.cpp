#pragma once 
#include "../include/neurolens/tensor/ops.hpp"
#include "neurolens/tensor/tensor.hpp"
#include <stdexcept>



// addition of two tensor 
neurolens::Tensor neurolens::add( const Tensor &a, const Tensor &b){
    if(!a.sameShape(b)){
        throw std::invalid_argument("Tensor must be same size");
    }

    Tensor c(a.shape());
    for (std::size_t i = 0;  i < a.size() ; ++i) {

        c[i] = a[i] + b[i];
    }
    return c;
}

// adding bias to a tensor with bias  tensor 
neurolens::Tensor neurolens::addBias( const Tensor &a, const Tensor &b){
    if(!a.sameShape(b)){
         
    };

    Tensor c(a.shape());
    for (std::size_t i = 0;  i < a.size() ; ++i) {

        
    }
    return c;
}

// multiplication of two tensor 
neurolens::Tensor neurolens::mul( const Tensor &a, const Tensor &b){
    if(!a.sameShape(b)){
        throw std::invalid_argument("Tensor must be same size");
    };

    Tensor c(a.shape());
    for (std::size_t i = 0;  i < a.size() ; ++i) {

        c[i] = a[i] * b[i];
    }
    return c;
}
