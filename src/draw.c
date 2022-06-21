/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: dyeboa <dyeboa@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/16 17:47:36 by dyeboa        #+#    #+#                 */
/*   Updated: 2022/06/21 16:53:31 by dyeboa        ########   odam.nl         */
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

// void draw_dots(int colour, int x, int y, t_data *data)
// {
//     int i;

//     i = 0;
//     if (colour == 0)
//         my_mlx_pixel_put(&data, x, y, 0x00FF0000);
//     else
//         my_mlx_pixel_put(&data, x, y, 0x00FFFF00);
// }

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
