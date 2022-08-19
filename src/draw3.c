/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw3.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: dyeboa <dyeboa@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/16 17:47:36 by dyeboa        #+#    #+#                 */
/*   Updated: 2022/08/19 11:25:15 by dyeboa        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void    draw_dots(int x, int y, t_data *data)
{
    float ix;
    float iy;
    int windowx;
    int windowy;
    float temp;
    float tempy;
    
    ix = x;
    iy = y;
    windowy = WINDOW_Y / ((data->max_x + data->max_y) / 2);
    windowx = WINDOW_X / ((data->max_x) * 2);
    data->matrix[y][x].x = (ix + data->max_y) * windowx;
    data->matrix[y][x].y = iy * windowy;
    temp = data->matrix[y][x].x;
    tempy = data->matrix[y][x].y;
    data->matrix[y][x].x = (temp * cos(45)) - (tempy * sin(45));
    data->matrix[y][x].y = (tempy * cos(45)) + ((temp * sin(45))) - data->matrix[y][x].z * 3;
    // if (data->width > data->matrix[y][x].x)
    //     data->width = data->matrix[y][x].x;
    // // if (data->width2 < data->matrix[y][x].x)
    // //     data->width2 = data->matrix[y][x].x;
    // if (data->matrix[y][x].y < data->height)
    //             data->height = data->matrix[y][x].y;
    // if (data->matrix[y][x].y > data->low)
    // {
    //     printf("draw = %1.f en %1.f\n", data->low, data->matrix[y][x].y);
    //     data->low = data->matrix[y][x].y; 
    // }   
    printf("%1.f en %1.f\n", data->low, data->matrix[y][x].y);      
    //printf("%1.f", data->matrix[y][x].x);
    /*
    data->matrix[y][x].x = (temp * cos(45)) - (tempy * sin(45)+1000);
    data->matrix[y][x].y = (tempy * cos(45)) + ((temp * sin(45))/3) - data->matrix[y][x].z;
    */
}

// void center_dots(t_data *data)
// {
//     int i;
//     int j;

//     i = 0;
//     while (i < data->max_y)
//     {
//         j = 0;
//         while(j < data->max_x)
//         {
//             if (data->width < 0)
//                 data->matrix[i][j].x += -1*data->width + 10;
//             if (data->widtht > 1920)
//                 data->widtht /= data->widtht/1920;
//             if (data->height < 0 && data->low + -1* data->height <= 1919)
//                 data->matrix[i][j].y += data->height *-1;
            
//             if (data->low > 1000 )//&& data->height + (data->low -1919) > 0)
//                 data->matrix[i][j].y /= (data->low/1000);
//             j++;
//         }
//         i++;
//     }
//     printf("low = %1.f", data->low);
// }


void connect_dots(t_data *data)
{
    int x;
    int y;
    float m;
    float newx;
    float newy;
    float temp;
    m = 1;
    x = 0;
    y = 0;
    newx = 0;
    newy = 0;

    while (y < data->max_y)
    {
        x = 0;
        while (x + 1 < data->max_x)
        {
            newx = data->matrix[y][x].x;
            temp = data->matrix[y][x+1].x - newx;
            temp = 65535 / temp;
            m = (data->matrix[y][x + 1].y - data->matrix[y][x].y) / (data->matrix[y][x + 1].x - data->matrix[y][x].x);
            while (newx <= data->matrix[y][x + 1].x)
            {
                newy = (m * (newx - data->matrix[y][x].x) + data->matrix[y][x].y);
                if (data->matrix[y][x].z > data->max_z/2 && data->matrix[y][x+1].z > data->max_z/2)
                    my_mlx_pixel_put(data, newx, newy, 0xFF0000);
                else if (data->matrix[y][x+1].z > data->max_z/2 ) //|| data->matrix[y][x-1].z > data->max_z/2 )
                    my_mlx_pixel_put(data, newx, newy, (0xffffff - (newx - data->matrix[y][x].x) *temp ));
                else if (data->matrix[y][x+1].z < data->max_z/2 && data->matrix[y][x].z > data->max_z/2 ) //|| data->matrix[y][x-1].z > data->max_z/2 )
                    my_mlx_pixel_put(data, newx, newy, (0xff0000) + (newx - data->matrix[y][x].x) *temp);
                else
                    my_mlx_pixel_put(data, newx, newy, 0xFFFFFF);
                newx = newx + 0.1;
            }
            x++;
        }
        y++;
    }
}

void connect_vert(t_data *data)
{
    int x;
    int y;
    float m;
    float newx;
    float newy;
    float temp;
    m = 1;
    x = 0;
    y = 0;
    newx = 0;
    newy = 0;

    while (y + 1 < data->max_y)
    {
        x = 0;
        while (x < data->max_x)
        {
            newx = data->matrix[y][x].x;
            temp = data->matrix[y+1][x].x - newx;
            temp = 65535 / temp;
            m = (data->matrix[y+1][x].y - data->matrix[y][x].y) / (data->matrix[y+1][x].x - data->matrix[y][x].x);
            while (newx >= data->matrix[y+1][x].x)
            {
                newy = (m * (newx - data->matrix[y][x].x) + data->matrix[y][x].y);  
                if (data->matrix[y][x].z > data->max_z/2 && data->matrix[y+1][x].z > data->max_z/2)
                    my_mlx_pixel_put(data, newx, newy, 0xFF0000);
                else if (data->matrix[y + 1][x].z > data->max_z/2 )
                    my_mlx_pixel_put(data, newx, newy, (0xffffff - (newx - data->matrix[y][x].x) *temp ));
                else if (data->matrix[y+1][x].z < data->max_z/2 && data->matrix[y][x].z > data->max_z/2 ) //|| data->matrix[y][x-1].z > data->max_z/2 )
                    my_mlx_pixel_put(data, newx, newy, (0xff0000) + (newx - data->matrix[y][x].x) *temp);
                else
                    my_mlx_pixel_put(data, newx, newy, 0xFFFFFF);
                newx = newx - 0.1;
            }
            x++;
        }
        y++;
    }
}

/* 
Bereken vanaf waar ie getekend moet worden om lekker groot in beeld te komen
Teken lijnen tussen punten met kleursverschil in 5 stappen (z waarde high en low)
*/
int draws(t_data *data)
{
	int i;
	int j;

	i = 0;
    data->width = 1;
    data->widtht = 1920;
    data->height = 1;
    data->low = 1000;   
	while (i < data->max_y)
	{
		j = 0;
		while (j < data->max_x)
		{
			//printf("%.0f ", (matrix[i][j].z));
			//draw_dots(0, j*20+500, (matrix[i][j].z + i)+i*10 + 500, data);
			
			if ((data->matrix[i][j].z) > 5)
				draw_dots(j, i, data);
			else
				draw_dots(j, i, data);
			// if (i + 1 < 11)
			// 	breshelper(j*30+400, (matrix[i][j].z+i)+i*20+400, j*30+401, (matrix[i+1][j].z+i)+i*20+400, data);
			// else
			// 	breshelper(j*30+400, (matrix[i][j].z+i)+i*20+400, j*30+401, (matrix[i][j].z+i)+i*20+400, data);
			
			//printf("reader x = %d, y = %d\n", frame->max_x, frame->max_y);
			j++;
		}
		//printf("\n");
		i++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	return (1);
}

int draw(t_data *data)
{
    draws(data); //fill data
    //center_dots(data);
    //draw_ugly_line(data);
    connect_dots(data);
    connect_vert(data);
    //breshelper(data); //-> bresenhamline
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	return (1);
}