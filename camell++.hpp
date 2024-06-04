/*
         Camell++ Lib    v 1.2.5
	 X-Window routines Library
	 Developed by saahriktu
	 released under GNU GPLv3
 */
#include <stdio.h>
#include <X11/Xlib.h>
#include <unistd.h>
#include <cstring>
#include <iostream>

class camell
{
public:
   camell (int x_x, int x_y, int x_width, int x_height, int x_border_width);
   ~camell ();
  void set_wattr (XSetWindowAttributes wattr_);
  void set_font (char *fontname);
  void puttext (int t_x, int t_y, char *text);
  void putpixel (int pixel_x, int pixel_y);
  void putline (int pixel_x1, int pixel_y1, int pixel_x2, int pixel_y2);
  void putarc (int arc_x, int arc_y, unsigned int arc_width,
	       unsigned int arc_height, int arc_angle1, int arc_angle2);
  void fillarc (int arc_x, int arc_y, unsigned int arc_width,
	       unsigned int arc_height, int arc_angle1, int arc_angle2);
  void putrectangle (int rect_x, int rect_y, unsigned int rect_width,
	       unsigned int rect_height);
  void fillrectangle (int rect_x, int rect_y, unsigned int rect_width,
	       unsigned int rect_height);
  void set_foreground (int xfg_red, int xfg_green, int xfg_blue);
  void graphics_refresh ();
  Display *get_display ();
  Window get_window ();
  int get_screen ();
  GC get_gc ();
 int get_width();
 int get_height();
private:
  Display *camell_d;
  Window camell_w;
  Visual *camell_visual;
  int camell_depth;
  int camell_screen;
  XSetWindowAttributes camell_attr;
  GC x_gc;
  XColor x_color, x_color_back;
  Colormap x_cmap;
  XGCValues xgc_values;
  int camell_width, camell_height;
  Atom x_atom[0];
  void set_pixelcolor (int pc_r, int pc_g, int pc_b);
};
