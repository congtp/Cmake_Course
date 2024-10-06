#ifndef _RECTANGLE_H_
#define _RECTANGLE_H_

#include "shape.h"

/* Rectangle Attributes */
typedef struct{
    Shape_t super;    /* Inherited Shape */

    /* Attributes specific to the Rectangle */
    uint16_t width;
    uint16_t height;
    
}Rectangle_t;

/* Rectangle 's Methods */
void Rectangle_ctor(Rectangle_t * const self, 
                    int16_t x0, int16_t y0,
                    uint16_t w0, uint16_t h0);
/* Rectangle 's specific methods */
void Rectangle_draw(Rectangle_t const * const self);


#endif 