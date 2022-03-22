/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masamoil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 15:44:20 by masamoil          #+#    #+#             */
/*   Updated: 2022/03/04 15:44:22 by masamoil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_events(t_data *data, t_img *img)
{
	//mlx_loop_hook(data->mlx_ptr, &loop_handler, image);
	mlx_hook(data->win_ptr, DestroyNotify, StructureNotifyMask,
		&red_cross_handler, image);
	//mlx_hook(data->win_ptr, KeyPress, KeyPressMask, &handle_keyrelease, &data);
	//mlx_hook(data->win_ptr, ButtonPress, ButtonPressMask,
		&button_handler, image);
	//mlx_hook(data->win_ptr, MotionNotify, PointerMotionMask,
		&pointer_handler, image);
}