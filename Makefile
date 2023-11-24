NAME	= volcano

all:
	make -C lib/game-engine
	@echo "Compilation of the game engine done"
	@if [ ! -d "build" ]; then \
		mkdir build && cd build && cmake .. && make && cp $(NAME) ../; \
	else \
		cd build && make && cp $(NAME) ../; \
	fi

clean:
	make -C lib/game-engine clean
	rm -rf build

fclean:	clean
	make -C lib/game-engine fclean
	rm -rf $(NAME)

re:	fclean all
