#pragma once
#ifndef MUTI_DIM_LINK_H
#define MUTI_DIM_LINK_H

#define Elemtype int
#define Dim 3
typedef struct Multi_dim_Node {
    float data[Dim];
    struct Multi_dim_Node* next;
} Multi_dim_Node;

//unsigned int ListLength_1(LinkNode* L);
#endif // MUTI_DIM_LINK_H

