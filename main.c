#include "cub3d.h"
#include <unistd.h>
#include <stdlib.h> 

// int main()
// {
// 	void	(*plug_ptr)(void);
// 	void	*handle;
// 	printf("this is the library :\n");
// 	while(true){
// 		system("gcc -c plug.c -fPIC -o plug.o && gcc -shared -o libplug.so plug.o");
// 		handle = dlopen("libplug.so", RTLD_NOW);
// 		// plug_hello();
// 		plug_ptr = dlsym(handle, "plug_hello");
// 		plug_ptr();
// 		printf("\n%p ----- %p\n", handle, plug_ptr);
// 		dlclose(handle);
// 		sleep(1);
// 	}
	
// 	return (0);
// }
int main()
{
	t_map	utils;
	t_player	pl;
	int	fd;
	// 	void	(*plug_ptr)(t_map *utils);
	// void	*handle;
	utils.pl = &pl;
	utils_init(&utils);
	parsing_map(&utils, &fd);
	plug_hello(&utils);
	// printf("this is the library :\n");
	// while(true){
		// system("make");
		// handle = dlopen("libplug.so", RTLD_NOW);
		// plug_hello();
		// plug_ptr = dlsym(handle, "plug_hello");
		// plug_ptr(&utils);
		// printf("\n%p ----- %p\n", handle, plug_ptr);
		// dlclose(handle);
		// sleep(1);
	// }

	// return(0);
	// if(utils.map)
	// {
	// 	player_detection(utils.map, &pl);
	// 	// plug_hello(&utils);
	// }
}