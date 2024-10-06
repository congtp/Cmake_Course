#include "Rectangle.h"
static uint32_t Rectangle_area(Rectangle_t const * const self);

void Rectangle_ctor(Rectangle_t * const self, 
                    int16_t x0, int16_t y0,
                    uint16_t w0, uint16_t h0)
{
    Shape_ctor(&self->super, x0, y0);   /* Call base class ctor */
    printf("The address of the vtable area: %p\n", &self->super.vPtr->area);

    static const struct ShapeVtable vtable = {
        (uint32_t (*)(Shape_t const * const self))&Rectangle_area
    };

    /* Overide the Shape vtable */
    self->super.vPtr = &vtable;
    printf("The address of the vtable area after change: %p\n", &self->super.vPtr->area);
    /* Init attributes of the Rectangle Class */
    self->width = w0;
    self->height = h0;
    
}

void Rectangle_draw(Rectangle_t const * const self){
    printf("Draw the Rectangle!\n");
}
uint32_t Rectangle_area(Rectangle_t const * const self){
    return (uint32_t)self->width * (uint32_t)self->height;
}