NAME	=	libgame-engine.so
all:
	@if [ ! -d "build" ]; then \
		mkdir build && cd build && cmake .. && make && cp $(NAME) ../; \
	else \
		cd build && make && cp $(NAME) ../; \
	fi

clean:
	rm -rf build

fclean:	clean
	rm -rf ../$(NAME)

re:	fclean	all
