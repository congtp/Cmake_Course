#ifndef __SHAPE_H__
#define __SHAPE_H__

#include <stdint.h>




/* Shape's Attributes... */
typedef struct{
    /* Virtual pointer */
    struct ShapeVtable const *vPtr;

    int16_t x;  /* x-cordinate of Shape's position */
    int16_t y;  /* x-cordinate of Shape's position */
}Shape_t;

struct ShapeVtable{
    /* Pointer to the area method */
    uint32_t (*area)(Shape_t const * const self);
};

/****************************************************************** 
 * @param[in]  self  Pointer to instance control block
 ******************************************************************/


/* Shape Methods */
void Shape_ctor(Shape_t * const self, int16_t x0, int16_t y0); /* Shape Constructor */
void Shape_moveBy(Shape_t *const self, int16_t dx, int16_t dy); /* move x by dx, and move y by dy */
uint16_t Shape_distanceFrom(Shape_t const * const self,
                            Shape_t const * const other); /* return the between two shape */

/* Virtual Call Late Binding */
static inline uint32_t Shape_area_vcall(Shape_t const * const self){
    printf("Inside Shape vcall \n");
    return self->vPtr->area(self);
}


#endif