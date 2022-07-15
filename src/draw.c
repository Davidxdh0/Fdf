/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: dyeboa <dyeboa@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/16 17:47:36 by dyeboa        #+#    #+#                 */
/*   Updated: 2022/07/15 18:07:01 by dyeboa        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// void DDA(int x, int y, int x1, int y1, t_data *data)
// {
//     //for (int i = 600; i <= 700; i++)
//        // my_mlx_pixel_put(&data, i, i, 0x00FF0000+i);
        
//     // calculate dx & dy
//     int dx = x1 - x;
//     int dy = y1 - x;
//     data.line_length++;
//     // calculate steps required for generating pixels
//     int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
//     //printf("steps = %d\n", steps);
//     // calculate increment in x & y for each steps
//     float Xinc = dx / (float) steps;
//     float Yinc = dy / (float) steps;
 
//     // Put pixel for each step
//     float X = x;
//     float Y = y;
//     for (int i = 0; i <= steps; i++)
//     {
//         if (Y < 0)
//             Y *= -1;
//         //printf("X = %.0f Y = %.0f\n", X, Y);
//         my_mlx_pixel_put(&data, X, Y, 0x00FF0000); //(round(X),round(Y),RED);   put pixel at (X,Y)
//         X += Xinc;           // increment in x at each step
//         Y += Yinc;           // increment in y at each step
//     }
// }

void    draw_dots(int colour, int x, int y, t_data *data)
{
    int i;
    int j;
    int ix;
    int iy;
    
    ix = x - y;
    iy = (x + y)/2;
    i = (y-500)/20;
    j = (x-1000)/20;
    //printf("%d en %d\n", ix, iy);
    if (colour == 0)
        my_mlx_pixel_put(data, ix, iy, 0x00FF0000);
    else
        my_mlx_pixel_put(data, ix, iy, 0x00FFFF00);
    if (i < 10 && j < 18)
		draw_ugly_line(ix, iy, data);
    //printf("x = %d, y = %d\n", x, y);
    
}

void draw_ugly_line(int ix, int iy, t_data *data)
{
    int slope;
    int ix2;
    int iy2;

    ix2 = ix - 20;
    iy2 = iy + 10;
   // printf("%d, %d, %d, %d\n", iy2,iy,ix2,ix);
    slope = (iy2 - iy)/(ix2 - ix);
    while (ix < ix2)
    {
        iy2 = slope*(ix2-ix) + iy;
        // printf("y = %d, y2 = %f\n", y, y2);
        // printf("x = %d, x2 = %f\n", x, x2);
        // if (x2 - x == 2)
        my_mlx_pixel_put(data, ix, iy2, 0x00FF0000);
        ix--;
    }
}

void breshelper(int x1, int y1, int x2, int y2, t_data *data)
{
    int dx;
    int dy;
    
    dx = abs(x2 - x1);
    dy = abs(y2 - y1);
    //If slope is less than one
    if (dx > dy)
    {
        //passing argument as 0 to plot(x,y)
        bresehamline(x1, y1, x2, y2, dx, dy, 0, data);
    }
    //if slope is greater than or equal to 1
    else
    {
        //passing argument as 1 to plot (y,x)
        bresehamline(y1, x1, y2, x2, dy, dx, 1, data);
    }
}
void bresehamline(int x1, int y1, int x2, int y2, int dx, int dy, int decide, t_data *data)
{
    int i;
    int pk;

    i = 0;
    pk = 2 * dy - dx;
    while (i <= dx)
    {
        //printf("x1+","+y1+"\n);
        //checking either to decrement or increment the value
        //if we have to plot from (0,100) to (100,0)
        if (x1 < x2)
            x1++;
        else
            x1--;
        if (pk < 0)
        {
            //decision value will decide to plot
            //either  x1 or y1 in x's position
            if (decide == 0)
            {
               // putpixel(x1, y1, RED);
               my_mlx_pixel_put(data, x1, y1, 0x00FF0000);
                pk = pk + 2 * dy;
            }
            else
            {
                //(y1,x1) is passed in xt
               // putpixel(y1, x1, YELLOW);
               my_mlx_pixel_put(data, y1, x1, 0x00FFFF00);
                pk = pk + 2 * dy;
            }
        }
        else
        {
            if (y1 < y2)
                y1++;
            else
                y1--;
            if (decide == 0)
                my_mlx_pixel_put(data, x1, y1, 0x00FF0000);
                //putpixel(x1, y1, RED);
            else
                my_mlx_pixel_put(data, y1, x1, 0x00FFFF00);
              //  putpixel(y1, x1, YELLOW);
            pk = pk + 2 * dy - 2 * dx;
        }
        i++;
    }
}

int draw(t_data *data)
{
	int i;
	int j;
	
	i = 0;
	while (i < 11)
	{
		j = 0;
		while (j < 19)
		{
			//printf("%.0f ", (matrix[i][j].z));
			//draw_dots(0, j*20+500, (matrix[i][j].z + i)+i*10 + 500, data);
			
			if ((data->matrix[i][j].z) > 5)
				draw_dots(0, j*20+1000, i*20 + 500, data);
			else
				draw_dots(1, j*20+1000, i*20 + 500, data);
			
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
