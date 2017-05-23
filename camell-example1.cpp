/*
	camell-example1
*/

#include <camell++/camell++.hpp>
#include <cmath>

int main(){
camell *xwindow;
int i,a_x[2], a_y[2];
float r;
xwindow = new camell(0, 20, 640, 480,0);
	//xwindow->set_rusfont(14);
	xwindow->set_foreground(255, 0, 0);
	xwindow->puttext(320, 240, "camell");
	xwindow->set_foreground(0, 255, 0);
	xwindow->putarc(240,140, 200, 200, 0, 23040);
while(1){
	for(r=0;r<6.28;r+=0.01){
	a_x[0]=(int)floor(cos(r)*90+335);
	a_y[0]=(int)floor(sin(r)*90+235);
	a_x[1]=(int)floor(cos(3.14-r)*70+335);
	a_y[1]=(int)floor(sin(3.14-r)*70+235);
	for(i=0;i<2;i++){
	if(i==0)xwindow->set_foreground(255, 255, 0);else  xwindow->set_foreground(0, 0, 0);
	xwindow->putarc(a_x[0],a_y[0], 10, 10, 0, 23040);
	xwindow->putarc(a_x[1],a_y[1], 10, 10, 0, 23040);
	}
	}
     }
return 0;
}
