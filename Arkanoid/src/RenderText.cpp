#include "RenderText.hpp"
void stb_print_string(float x, float y, char *text, float r, float g, float b)
{
  static char buffer[99999]; // ~500 chars
  int num_quads;

  num_quads = stb_easy_font_print(x, y, text, NULL, buffer, sizeof(buffer));

  glColor3f(r,g,b);
  glEnableClientState(GL_VERTEX_ARRAY);
  glVertexPointer(2, GL_FLOAT, 16, buffer);
  glDrawArrays(GL_QUADS, 0, num_quads*4);
  glDisableClientState(GL_VERTEX_ARRAY);
}

void print_string(float dx, float x, float y, char *text, float r, float g, float b){
    glScalef(dx, -dx, 1);
    stb_print_string(x/dx, y/dx, text, r,g,b);
    glScalef(1 / dx, 1 / -dx, 1);
}