#include <stdio.h>
#include "glk.h"
#include "cheapglk.h"

#include <emscripten.h>

void glk_stylehint_set(glui32 wintype, glui32 styl, glui32 hint,
    glsi32 val)
{
#if defined (__EMSCRIPTEN__)
    // only set hints that apply to the main window
 //   if( wintype == wintype_AllTypes || wintype == wintype_TextBuffer ) {
        EM_ASM_({
            vorple.haven.setStyleHint( $0, $1, $2 );
        }, styl, hint, val );
//    }
#endif
}

void glk_stylehint_clear(glui32 wintype, glui32 styl, glui32 hint)
{
}

glui32 glk_style_distinguish(winid_t win, glui32 styl1, glui32 styl2)
{
    /* Styles are never distinguishable. */
    return FALSE;
}

glui32 glk_style_measure(winid_t win, glui32 styl, glui32 hint, 
    glui32 *result)
{
    /* We can't measure any style attributes. */
    return FALSE;
}


