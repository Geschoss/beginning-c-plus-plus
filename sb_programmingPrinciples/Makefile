create_folder:
	mkdir $(NAME) \
	&& mkdir $(NAME)/build/ \
	&& touch $(NAME)/main.cpp
	
create_section:
	mkdir $(NAME) \
	&& mkdir $(NAME)/build/ \
	&& touch $(NAME)/main.cpp

run_section:
	g++ -std=c++2a -o $(NAME)/build/output $(NAME)/main.cpp \
	&& du -sh $(NAME)/build/output \
	&& $(NAME)/build/output \
	&& rm $(NAME)/build/output 
