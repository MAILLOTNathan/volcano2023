NAME	= volcano

all:
	make -C lib/game-engine
	@echo "Compilation of the game engine done"
	rm -rf build && mkdir build && cd build && cmake .. && make && cp $(NAME) ../

clean:
	make -C lib/game-engine clean
	rm -rf build

fclean:	clean
	make -C lib/game-engine fclean
	rm -rf $(NAME)

re:	fclean all
