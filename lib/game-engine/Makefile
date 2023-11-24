NAME	=	libgame-engine.so
all:
	rm -rf build && mkdir build && cd build && cmake .. && make

clean:
	rm -rf build

fclean:	clean
	rm -rf ../$(NAME)

re:	fclean	all
