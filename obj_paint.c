
#include "so_long.h"

void	draw_floor(t_game *data, int x, int y)
{
	mlx_put_image_to_window(data->mlx, data->window, data->floor, x, y);
}

void	draw_wall(t_game *data, int x, int y)
{
	mlx_put_image_to_window(data->mlx, data->window, data->wall, x, y);
}

void	draw_item(t_game *data, int x, int y)
{
	mlx_put_image_to_window(data->mlx, data->window, data->items, x, y);
}

void	draw_exit(t_game *data, int x, int y)
{
	mlx_put_image_to_window(data->mlx, data->window, data->exit, x, y);
}

void	draw_player(t_game *data, int x, int y)
{
	mlx_put_image_to_window(data->mlx, data->window, data->player, x, y);
}

