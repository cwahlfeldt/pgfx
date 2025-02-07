#ifndef PGFX_RENDERER_OBJECTS_PRIMITIVES_H
#define PGFX_RENDERER_OBJECTS_PRIMITIVES_H

#include <GL/gl3w.h>

typedef struct {
    GLuint vao;        // Vertex Array Object
    GLuint vbo;        // Vertex Buffer Object
    GLuint ebo;        // Element Buffer Object
    unsigned int index_count;
} Primitive;

// Creation functions
Primitive create_cube_primitive(void);
Primitive create_plane_primitive(void);
Primitive create_sphere_primitive(void);
Primitive create_cylinder_primitive(void);

// Cleanup
void destroy_primitive(Primitive* primitive);

// Drawing
void draw_primitive(const Primitive* primitive);

#endif // PGFX_RENDERER_OBJECTS_PRIMITIVES_H