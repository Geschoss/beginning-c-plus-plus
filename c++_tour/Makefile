FILE_NAME = main
FOLDER_NAME = 1

create:
	mkdir -p $(FOLDER_NAME) \
	&& mkdir -p $(FOLDER_NAME)/build/ \
	&& cp ./templates/main.cpp ./$(FOLDER_NAME)/$(FILE_NAME).cpp

run:
	g++ -std=c++2a -o $(FOLDER_NAME)/build/output $(FOLDER_NAME)/$(FILE_NAME).cpp \
	&& du -sh $(FOLDER_NAME)/build/output \
	&& $(FOLDER_NAME)/build/output \
	&& rm $(FOLDER_NAME)/build/output 
