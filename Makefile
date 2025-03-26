all: 
	cc -Wall -Wextra -Werror client.c ft_putstr_fd.c ft_putnbr_fd.c ft_atoi.c -o client
	cc -Wall -Wextra -Werror server.c ft_putnbr_fd.c ft_putstr_fd.c -o server

bonus:
	cc -Wall -Wextra -Werror ./bonus/client.c ./bonus/ft_putstr_fd.c ./bonus/ft_putnbr_fd.c ./bonus/ft_atoi.c -o client_bonus
	cc -Wall -Wextra -Werror ./bonus/server.c ./bonus/ft_putnbr_fd.c ./bonus/ft_putstr_fd.c -o server_bonus
fclean:
	rm -fr client server