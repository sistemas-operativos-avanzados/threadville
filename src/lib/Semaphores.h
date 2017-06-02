
#include "threadville_functions.h"
#include "threadville_globals.h"

static void draw_semaphore (cairo_t * cr, NODE * node) {   
   
    if(node->allowTravel)
        cairo_set_source_rgb (cr, 0.0, 1.0, 0.0);
    else
        cairo_set_source_rgb (cr, 1.0, 0.0, 0.0);
        

    cairo_rectangle(cr, node->x-10, node->y,TILESIZE,TILESIZE);
    cairo_fill (cr);
    
} // draw_semaphore
