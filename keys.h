/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikarishe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 12:17:31 by ikarishe          #+#    #+#             */
/*   Updated: 2018/08/08 15:30:46 by ikarishe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYS_H
# define KEYS_H

# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_F 3
# define KEY_H 4
# define KEY_G 5
# define KEY_Z 6
# define KEY_X 7
# define KEY_C 8
# define KEY_V 9
# define KEY_B 11
# define KEY_Q 12
# define KEY_W 13
# define KEY_E 14
# define KEY_R 15
# define KEY_Y 16
# define KEY_T 17
# define KEY_ONE 18
# define KEY_TWO 19
# define KEY_THREE 20
# define KEY_FOUR 21
# define KEY_SIX 22
# define KEY_FIVE 23
# define KEY_NINE 25
# define KEY_SEVEN 26
# define KEY_EIGHT 28
# define KEY_ZERO 29
# define KEY_BRACE_R 30
# define KEY_O 31
# define KEY_U 32
# define KEY_BRACE_L 33
# define KEY_I 34
# define KEY_P 35
# define KEY_L 37
# define KEY_J 38
# define KEY_K 40
# define KEY_SEMI 41
# define KEY_N 45
# define KEY_M 46
# define KEY_TAB 48
# define KEY_PLUS 69
# define KEY_MINUS 78
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_DOWN 125
# define KEY_UP 126

typedef struct	s_keys
{
	char		*index;
	char		*press;
/*
0
a

1  2  3  4  5  6  7  8  9  10
s  d  f  h  g  z  x  c  v   

11 12 13 14 15 16 17 18 19 20
 b  q  w  e  r  y  t  1  2  3

21 22 23 24 25 26 27 28 29 30
 4  6  5  =  9  7  -  8  0  ]

31 32 33 34 35 36 37 38 39 40
 o  u  [  i  p re  l  j  '  k    

41 42 43 44 45 46 47 48 49 50
 ;  \  ,  /  n  m  . tb sp  `

51 52 53 54 55 56 57 58 59 60
dl

61 62 63 64 65 66 67 68 69 70


71 72 73 74 75 76 77 78 79 80


81 82 83 84 85 86 87 88 89 90
      n1 n2 n3

91 92 93 94 95 96 97 98 99 100
               F5 F6           

101 102 103 104 105 106 107 108 109 110
				F13     F14

111 112 113 114 115 116 117 118 119 120
        F15

121 122 123 124

256 257	272
lct	lsh	cps*/

	int			a:1;
	int			s:1;
	int			d:1;
	int			f:1;
	int			h:1;
	int			g:1;
	int			z:1;
	int			x:1;
	int			c:1;
	int			v:1;
	int			b:1;
	int			q:1;
	int			w:1;
	int			e:1;
	int			r:1;
	int			y:1;
	int			t:1;
	int			one:1;
	int			two:1;
	int			three:1;
	int			four:1;
	int			six:1;
	int			five:1;
	int			nine:1;
	int			seven:1;
	int			eight:1;
	int			zero:1;
	int			brace_r:1;
	int			o:1;
	int			u:1;
	int			brace_l:1;
	int			i:1;
	int			p:1;
	int			l:1;
	int			j:1;
	int			k:1;
	int			semi:1;
	int			n:1;
	int			m:1;
	int			tab:1;
	int			plus:1;
	int			minus:1;
	int			left:1;
	int			right:1;
	int			down:1;
	int			up:1;
}				t_keys;

#endif
