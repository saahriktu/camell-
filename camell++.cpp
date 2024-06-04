/*
	Camell++ Lib	v 1.2.5
	X-Window routines Library
	Developed by saahriktu
	released under GNU GPLv3
*/
#include "camell++.hpp"

 camell::camell (int x_x, int x_y, int x_width, int x_height, int x_border_width)
  {
    camell_width=x_width;
    camell_height=x_height;
    if (camell_d = XOpenDisplay (NULL))
      {
	camell_screen = XDefaultScreen (camell_d);
	camell_visual = DefaultVisual (camell_d, camell_screen);
	camell_depth = DefaultDepth (camell_d, camell_screen);
	x_cmap = DefaultColormap (camell_d, camell_screen);
	camell_w =
	  XCreateWindow (camell_d, XRootWindow (camell_d, camell_screen), x_x,
			 x_y, x_width, x_height, x_border_width, camell_depth,
			 InputOutput, camell_visual, CWBackPixel, &camell_attr);
	XSelectInput (camell_d, camell_w, ExposureMask | KeyPressMask);
	xgc_values.background = 1;
    	x_gc = 0;
    	x_gc = XCreateGC (camell_d, camell_w, GCBackground+GCForeground, &xgc_values);
	XFlush (camell_d);
	XMapWindow (camell_d, camell_w);
	XFlush (camell_d);
	XSetTransientForHint(camell_d, XRootWindow (camell_d, camell_screen), camell_w);
	x_atom[0] = XInternAtom (camell_d, "WM_DELETE_WINDOW", true);
	XSetWMProtocols(camell_d, camell_w, x_atom, 1);
      }
  }

  camell::~camell ()
  {
    XCloseDisplay (0);
  }

  void camell::set_wattr (XSetWindowAttributes wattr_)
  {
    camell_attr = wattr_;
  }

  void camell::set_font (char *fontname)
  {
	XSetFont (camell_d, x_gc,
		  XLoadFont (camell_d, fontname));
  }

  void camell::puttext (int t_x, int t_y, char * text)
  {
    XDrawString (camell_d, camell_w, x_gc, t_x, t_y, text, strlen(text));
  }

  void camell::putpixel (int pixel_x, int pixel_y)
  {
    XDrawPoint (camell_d, camell_w, x_gc, pixel_x, pixel_y);
  }

  void camell::putline (int pixel_x1, int pixel_y1, int pixel_x2, int pixel_y2)
  {
    XDrawLine (camell_d, camell_w, x_gc, pixel_x1, pixel_y1, pixel_x2, pixel_y2);
  }

  void camell::putarc (int arc_x, int arc_y, unsigned int arc_width,
	       unsigned int arc_height, int arc_angle1, int arc_angle2)
  {
    XDrawArc (camell_d, camell_w, x_gc, arc_x, arc_y, arc_width, arc_height,
	      arc_angle1, arc_angle2);
  }

  void camell::fillarc (int arc_x, int arc_y, unsigned int arc_width,
	       unsigned int arc_height, int arc_angle1, int arc_angle2)
  {
    XFillArc (camell_d, camell_w, x_gc, arc_x, arc_y, arc_width, arc_height,
	      arc_angle1, arc_angle2);
  }

  void camell::putrectangle (int rect_x, int rect_y, unsigned int rect_width,
	       unsigned int rect_height)
  {
    XDrawRectangle (camell_d, camell_w, x_gc, rect_x, rect_y, rect_width, rect_height);
  }

  void camell::fillrectangle (int rect_x, int rect_y, unsigned int rect_width,
	       unsigned int rect_height)
  {
    XFillRectangle (camell_d, camell_w, x_gc, rect_x, rect_y, rect_width, rect_height);
  }

  void camell::set_foreground (int xfg_red, int xfg_green, int xfg_blue)
  {
    set_pixelcolor (xfg_red, xfg_green, xfg_blue);
    XSetForeground (camell_d, x_gc, x_color.pixel);
  }

  void camell::graphics_refresh ()
  {
    XFlushGC (camell_d, x_gc);
  }

  Display * camell::get_display ()
  {
    return camell_d;
  }

  Window camell::get_window ()
  {
    return camell_w;
  }

  int camell::get_screen ()
  {
    return camell_screen;
  }

  GC camell::get_gc ()
  {
    return x_gc;
  }

  int camell::get_width ()
  {
    return camell_width;
  }

  int camell::get_height ()
  {
    return camell_height;
  }

  void camell::set_pixelcolor (int pc_r, int pc_g, int pc_b)
  {
    x_color.red = pc_r * 257;
    x_color.green = pc_g * 257;
    x_color.blue = pc_b * 257;
    x_color.flags = DoRed | DoGreen | DoBlue;
    XAllocColor (camell_d, x_cmap, &x_color);
  }
