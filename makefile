all: averagepx averageNoThread 

averagepx: averagepx.c
	gcc -fopenmp averagepx.c -o averagepx || gcc-13 -fopenmp averagepx.c -o averagepx

averageNoThread: averageNoThread.c
	gcc averageNoThread.c -o averageNoThread || gcc-13 averageNoThread.c -o averageNoThread

clean:
	rm -f averagepx averageNoThread input.txt averageoptimize
