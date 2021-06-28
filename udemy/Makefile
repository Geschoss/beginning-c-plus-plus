create_ch:
	mkdir $(CH) \
	mkdir $(CH)/$(NAME) \
	&& mkdir $(CH)/$(NAME)/build/ \
	&& touch $(CH)/$(NAME)/main.cpp
	
create_section:
	mkdir $(CH)/$(NAME) \
	&& mkdir $(CH)/$(NAME)/build/ \
	&& touch $(CH)/$(NAME)/main.cpp

run_section:
	g++ -std=c++2a -o $(CH)/$(NAME)/build/output $(CH)/$(NAME)/main.cpp \
	&& du -sh $(CH)/$(NAME)/build/output \
	&& $(CH)/$(NAME)/build/output \
	&& rm $(CH)/$(NAME)/build/output 
