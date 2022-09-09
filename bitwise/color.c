/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeguedm <mmeguedm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 18:24:33 by mmeguedm          #+#    #+#             */
/*   Updated: 2022/09/09 15:37:45 by mmeguedm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void print_byte_as_bits(int val) {
  for (int i = 7; 0 <= i; i--) {
    printf("%c", (val & (1 << i)) ? '1' : '0');
  }
}

int	create_trgb(unsigned char t, unsigned char r, unsigned char  g, unsigned char b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	create_test(int t)
{
	return (t << 1);
}

int	get_t(int trgb)
{
	return ((trgb >> 24) & 0xFF);
}

int	get_r(int trgb)
{
	return ((trgb >> 16) & 0xFF);
}

int	get_g(int trgb)
{
	return ((trgb >> 8) & 0xFF);
}

int	get_b(int trgb)
{
	return (trgb & 0xFF);
}










int	my_get_r(int trgb)
{
	return (trgb >> 16);
}


int	main(void)
{
	int	trgb;
	unsigned int	a;

	a = 0;
	a = ~a;
	a = 2147483647;
	//printf("create test : %d\n", create_test(a));
	trgb = create_trgb(0, 8, 0, 0);
	printf("create trgb : %d\n", trgb);
	printf("get r : %d\n", get_r(trgb));
	printf("my_get_r : %d\n", my_get_r(trgb));
	printf("%d\n", 0xB >> 3);
}

// 0000 1110 0000 0000
//    FF 00
//    255


// 1111 1111 0000 0000 0000 0000 0000 0000
// 1111 1111 0000 0000 0000 0000 0000 0000 00
//	 0111 = 2
// | 1000 = 5
//			7
