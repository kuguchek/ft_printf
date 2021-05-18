NAME	= libftprintf.a

FLAGS	= -Wall -Wextra -Werror -I

SRC_DIR = src/

LFT_DIR = libft/

SRC		= ft_printf.c print_di.c check.c print_oux.c print_scp.c helper.c check_format.c print_f.c

LIBFT	= ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c\
		ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_memalloc.c\
		ft_memdel.c ft_strcat.c ft_strchr.c ft_strcmp.c ft_strcpy.c ft_strdup.c ft_strlen.c ft_strncat.c\
		ft_strncmp.c ft_strncpy.c ft_strnstr.c ft_strrchr.c ft_strstr.c ft_tolower.c ft_toupper.c\
		ft_tolower_str.c ft_strnew.c ft_strdel.c ft_strclr.c ft_strlcat.c ft_striter.c ft_striteri.c\
		ft_power.c ft_strmap.c ft_strmapi.c ft_strequ.c ft_strnequ.c ft_strsub.c ft_strjoin.c ft_strtrim.c\
		ft_strsplit.c ft_itoa.c ft_uitoa_base.c ft_putchar.c ft_putstr.c ft_putendl.c ft_putnbr.c\
		ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_isspace.c ft_swap.c ft_strrev.c\
		ft_strndup.c ft_wordcount.c ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c\
		ft_lstmap.c get_next_line.c

SSRC	= $(addprefix $(SRC_DIR), $(SRC))
LLIBFT	= $(addprefix $(LFT_DIR), $(LIBFT))

SRC_OBJ = $(SSRC:.c=.o)
LFT_OBJ = $(LLIBFT:.c=.o)

all: $(NAME)

$(SRC_OBJ): %.o: %.c
	@gcc -c $(FLAGS) src/ $< -o $@

$(LFT_OBJ): %.o: %.c
	@gcc -c $(FLAGS) libft/ $< -o $@

$(NAME): $(LFT_OBJ) $(SRC_OBJ)
	@ar rcs $(NAME) $(SRC_OBJ) $(LFT_OBJ)

clean:
	@rm -rf $(SRC_DIR)*.o
	@rm -rf $(LFT_DIR)*.o $(LFT_DIR)libft.a

fclean: clean
	@rm -rf $(NAME)

re: fclean all
