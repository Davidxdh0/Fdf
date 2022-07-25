/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: dyeboa <dyeboa@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/16 17:47:36 by dyeboa        #+#    #+#                 */
/*   Updated: 2022/07/25 14:33:12 by dyeboa        ########   odam.nl         */
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
    float ix;
    float iy;
    int windowx;
    int windowy;
    int offset;

    windowy = WINDOW_Y / ((data->max_x + data->max_y) / 2);
    windowx = WINDOW_X / ((data->max_x) * 1.6);
    // windowx = 2;
    // windowy = 2;
    offset = -1 * data->max_y * windowx;
    //printf("%d en %d ", windowx, windowy);
    
    ix = x - y;
    iy = (x + y)/2;
    // matrix[x_i][y_i].x = (ix + data->max_y) * windowx;
	// matrix[x_i][y_i].y = iy * windowy + 30;
    // data->matrix[1][y].x = (ix + data->max_y) * windowx;
    // data->matrix[1][y].y = iy * windowy + 30;
    data->matrix[y][x].x = (ix + data->max_y) * windowx;
    data->matrix[y][x].y = iy * windowy + 30;
    // printf("%d %d x: %f en y: %f\n",x,y,data->matrix[y][x].x, data->matrix[y][x].y );
    if (colour == 0)
        my_mlx_pixel_put(data, data->matrix[y][x].x, data->matrix[y][x].y, 0x00FF0000);
    else
        my_mlx_pixel_put(data, data->matrix[y][x].x , data->matrix[y][x].y, 0x00FFFF00);
    //printf("%.0f en %.0f\n",(ix + data->max_y)* windowx, (iy) * windowy + 30);
	//draw_ugly_line(x, y, data);
    //printf("x = %d, y = %d\n", x, y);
}

void connect_dots(t_data *data)
{
    int x;
    int y;
    int m;
    int newx;
    int newy;
    
    m = 1;
    x = 0;
    y = 0;
    newx = 0;
    newy = 0;
    while (y < 2)
    {
        //xdiff = (data->matrix[y][x + 1].x - data->matrix[y][x].x) / 
        while (x < 4)
        {
            newx = data->matrix[y][x].x;
            while (newx <= data->matrix[y][x + 1].x)
            {
                m = (data->matrix[y + 1][x].y - data->matrix[y][x].y) / (data->matrix[y][x + 1].x - data->matrix[y][x].x);
                printf("%d", m);
                newy = (m * newx + data->matrix[y][x].y);  
                my_mlx_pixel_put(data, newx, newy, 0x00FFAAAAA);
                newx++;
            }
            x++;
        }
        y++;
    }
}

void draw_ugly_line(t_data *data)
{
    float slope;
    int x;
    int y;
    int xsteps;
    int newx;
    int newy;
  
    x = 0;
    y = 0;
    newx = 0;
    newy = 0;
    while (y < data->max_y)
    {
        x = 0;
        while (x < data->max_x)
        {
            xsteps = (data->matrix[y][x + 1].x - data->matrix[y][x].x) + data->matrix[y + 1][x].y - data->matrix[y][x].y;
            while (x + 1 < data->max_x && xsteps > 0)
            {
                slope = (data->matrix[y][x + 1].y - data->matrix[y][x].y)/(data->matrix[y][x+1].x - data->matrix[y][x].x);
                newy = data->matrix[y][x].y + slope * xsteps;
                printf("slope = %f y=%d x=%d %f en %f en xs:%d nwy:%d\n", slope, y, x, data->matrix[y][x + 1].y - data->matrix[y][x].y, data->matrix[y][x+1].x - data->matrix[y][x].x, xsteps, newy);
                // printf("y = %d, y2 = %f\n", y, y2);
                // printf("x = %d, x2 = %f\n", x, x2);
                // if (x2 - x == 2)
                //printf("xsteps:%d newy:%d", xsteps, newy);
                my_mlx_pixel_put(data, xsteps+data->matrix[y][x].x, newy, 0x00FFAAAAA);
                xsteps--;
            }
            x++;
        }
        y++;
    }
}

void breshelper(int x, int y, t_data *data)
{
    int dx;
    int dy;
    int x1;
    int x2;
    int y1;
    int y2;

    // x++;
    // y++;
    // x1 = 100;
    // x2 = 125;
    // y1 = 110;
    // y2 = 120;
    if (x + 1 >= data->max_x || y + 1 >= data->max_y)
        return ;
    printf("y= %d x = %d\n", y, x);
    x1 = data->matrix[y][x].x;
    x2 = data->matrix[y][x+1].x;
    y1 = data->matrix[y][x].y;
    y2 = data->matrix[y][x+1].y;
    dx = abs(x2 - x1);
    dy = abs(y2 - y1);
    //If slope is less than one
    if (dx > dy && x+1 < data->max_x)
    {
        //passing argument as 0 to plot(x,y)
        bresehamline(x1,x2,y1,y2,dx, dy, 0, data);
    }
    //if slope is greater than or equal to 1
    else if ( y+1 < data->max_y)
    {
        //passing argument as 1 to plot (y,x)
        bresehamline(y1,y2,x1,x2,dy, dx, 1, data);
    }
}
void bresehamline(int x1, int x2, int y1, int y2, int dx, int dy, int decide, t_data *data)
{
    int i;
    int pk;

    i = 0;
    pk = 2 * dy - dx;
    while (i <= dx)
    {
        //printf("%d, %d\n", x1, y1);
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

/* 
Bereken vanaf waar ie getekend moet worden om lekker groot in beeld te komen
Teken lijnen tussen punten met kleursverschil in 5 stappen (z waarde high en low)
*/
int draw(t_data *data)
{
	int i;
	int j;

	i = 0;
	while (i < data->max_y-2)
	{
		j = 0;
		while (j < data->max_x-2)
		{
			//printf("%.0f ", (matrix[i][j].z));
			//draw_dots(0, j*20+500, (matrix[i][j].z + i)+i*10 + 500, data);
			
			if ((data->matrix[i][j].z) > 5)
				draw_dots(0, j, i, data);
			else
				draw_dots(1, j, i, data);
			breshelper(j, i, data);
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
    //draw_ugly_line(data);
    
   // connect_dots(data);
    
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	return (1);
}
