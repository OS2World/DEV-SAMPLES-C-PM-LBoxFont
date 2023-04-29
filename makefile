# nmake makefile
#
# Tools used:
#  Compile::Resource Compiler
#  Compile::GNU C
#  Make: nmake or GNU make
all : app.exe

app.exe : app.obj wndproc.obj appcmd.obj apppaint.obj app.res app.def
	gcc -Zomf app.obj wndproc.obj appcmd.obj apppaint.obj app.res \
		app.def -o app.exe	
	wrc app.res       

app.obj : app.c app.h
	gcc -Wall -Zomf -c -O2 app.c -o app.obj

wndproc.obj : wndproc.c app.h
	gcc -Wall -Zomf -c -O2 wndproc.c -o wndproc.obj

appcmd.obj : appcmd.c app.h
	gcc -Wall -Zomf -c -O2 appcmd.c -o appcmd.obj

apppaint.obj : apppaint.c app.h
	gcc -Wall -Zomf -c -O2 apppaint.c -o apppaint.obj

app.res : app.rc app.ico 
	wrc -r app.rc

clean :
	rm -rf *exe *RES *obj