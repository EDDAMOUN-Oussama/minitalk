all: 
	cc client.c ft_putstr_fd.c ft_atoi.c -o client
	cc server.c ft_putnbr_fd.c ft_putstr_fd.c -o server

fclean:
	rm -fr client server