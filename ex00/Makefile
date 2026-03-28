#-variables------------------------------------------------------------#

MAKEFLAGS += --no-print-directory
QUIET = 	

NAME =	ex00
INCLUDES =	./includes ./src/class
CC = $(QUIET) c++
FLAGS = -Wall -Wextra -Werror -std=c++98 -g3

FILES	=	main

CLASS		=	ScalarConverter

SRC_DIR		= 	src/
SRC_FILES	=	$(addsuffix .cpp, $(FILES)) \
				$(addprefix class/, $(addsuffix .cpp, $(CLASS)))
SRC 		=	$(addprefix $(SRC_DIR), $(SRC_FILES))

OBJ_DIR		= 	obj/
OBJ			=	$(patsubst $(SRC_DIR)%.cpp, $(OBJ_DIR)%.o, $(SRC))

#----------------------------------------------------------------------#

all : 			$(NAME)
				@ echo "\033[0;32m$(NAME)" "is ready !\033[0m" 

#-compil---------------------------------------------------------------#

$(NAME) :		$(OBJ_DIR) $(OBJ)
				$(CC) $(FLAGS) $(addprefix -I, $(INCLUDES)) $(OBJ) -o $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp
				$(CC) $(FLAGS) $(addprefix -I, $(INCLUDES)) -c $< -o $@

$(OBJ_DIR) :
				$(QUIET) mkdir -p $(OBJ_DIR)
				$(QUIET) mkdir -p $(OBJ_DIR)class

#-rules----------------------------------------------------------------#

clean :			
				$(QUIET) rm -rf $(OBJ_DIR)
				$(QUIET) -rm -f ./src/crop_shrubbery
				
fclean : 		clean
				$(QUIET) rm -f $(NAME)
				
re : 
				$(MAKE) fclean
				$(MAKE)

.PHONY : all clean fclean re