FILE_NAME = main

create:
	mkdir -p $(NAME) \
	&& mkdir -p $(NAME)/build/ \
	&& cp ./templates/main.cpp ./$(NAME)/$(FILE_NAME).cpp

run:
	g++ -std=c++2a -o $(NAME)/build/output $(NAME)/$(FILE_NAME).cpp \
	&& du -sh $(NAME)/build/output \
	&& $(NAME)/build/output \
	&& rm $(NAME)/build/output 
