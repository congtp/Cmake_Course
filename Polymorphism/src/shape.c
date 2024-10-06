#include "shape.h"

static uint32_t Shape_area(Shape_t const * const self);

void Shape_ctor(Shape_t * const self, int16_t x0, int16_t y0){
    /* We use static here to ensure the vtable is created only once,
    * This saves memory because the vtable is shared between all
    * instances of Shape, and it is stored in a fixed location,
    * const likely in read-only memory (such as FLASH in embedded systems).
    */
    static const struct ShapeVtable vtable = {
        &Shape_area
    };

    self->vPtr = &vtable;

    self->x = x0;
    self->y = y0;    
}


void Shape_moveBy(Shape_t *const self, int16_t dx, int16_t dy){
    self->x += dx;
    self->y += dy;
}

uint16_t Shape_distanceFrom(Shape_t const * const self,
                            Shape_t const * const other)
{
    int16_t dx = self->x - other->x;
    int16_t dy = self->y - other->y;
    if(dx < 0){
        dx = -dx;
    }
    if(dy < 0){
        dy = -dy;
    }
    return dx + dy;
}

static uint32_t Shape_area(Shape_t const * const self){
    (void)self; /* Parameter is not used */
    return 0U;
}