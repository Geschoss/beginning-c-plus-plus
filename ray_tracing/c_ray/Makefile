all:
	rm -f image.ppm \
	&& g++ -std=c++2a -o build/output main.cpp \
	&& du -sh build/output \
	&& build/output > image.ppm\
	&& rm -f build/* \
	&& open image.ppm

clean:
	rm -f image.ppm \
	&& rm -f build/*

dev:
	rm -f image.ppm \
	&& g++ -std=c++2a -o build/output main.cpp \
	&& du -sh build/output \
	&& build/output

# #Tell make to make one .out file for each .cpp file found in the current directory
# all: $(patsubst %.cpp, %.out, $(wildcard *.cpp))

# #Rule how to create arbitary .out files. 
# #First state what is needed for them e.g. additional headers, .cpp files in an include folder...
# #Then the command to create the .out file, probably you want to add further options to the g++ call.
# %.out: %.cpp Makefile
# 	g++ $< -o $@ -std=c++0x