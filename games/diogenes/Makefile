FILE_NAME = main

run:
	clang++ -std=c++2a -stdlib=libc++ -lncurses -g $(FILE_NAME).cpp -o /build/output \
	&& du -sh /build/output \
	&& /build/output \
	&& rm /build/output 
