/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: dyeboa <dyeboa@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/16 17:47:36 by dyeboa        #+#    #+#                 */
/*   Updated: 2022/06/17 20:25:48 by dyeboa        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void DDA(int x, int y, int x1, int y1, t_data img)
{
    //for (int i = 600; i <= 700; i++)
       // my_mlx_pixel_put(&img, i, i, 0x00FF0000+i);
        
    // calculate dx & dy
    int dx = x1 - x;
    int dy = y1 - x;
    img.line_length++;
    // calculate steps required for generating pixels
    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
 
    // calculate increment in x & y for each steps
    float Xinc = dx / (float) steps;
    float Yinc = dy / (float) steps;
 
    // Put pixel for each step
    float X = x;
    float Y = y;
    for (int i = 0; i <= steps; i++)
    {
        if (Y < 0)
            Y *= -1;
        printf("X = %.0f Y = %.0f\n", X, Y);
        my_mlx_pixel_put(&img, X+100, Y+100, 0x00FF0000); //(round(X),round(Y),RED);   put pixel at (X,Y)
        X += Xinc;           // increment in x at each step
        Y += Yinc;           // increment in y at each step
    }
}