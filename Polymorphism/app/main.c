#include <stdio.h>

#include <stdlib.h>
#include <assert.h>
#include "shape.h"
#include "Rectangle.h"


int main(){
    Rectangle_t r1;
    Shape_t *curr_Shape = &r1;


    Rectangle_ctor((Rectangle_t*)&curr_Shape, 1, 2, 3, 4);
    printf("%d \n", Shape_area_vcall((Shape_t*)&curr_Shape));


    return 0;
}