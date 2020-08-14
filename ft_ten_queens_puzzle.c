/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehattor <sehattor@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 11:56:02 by sehattor          #+#    #+#             */
/*   Updated: 2020/08/14 11:56:02 by sehattor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int sum;

void  print(int ans[10])
{
  int cnt;
  char c;

  cnt = 0;
  while (cnt < 10){
    c = ans[cnt] + '0';
    write(1, &c, 1);
    cnt++;
  }
  write(1, "\n", 1);
}

int check(int y, int x, int ma[10][10])
{
  int i;
  int j;
  int n;
  static int vec[8][2] = {{1, 1}, {0, 1},{1, 0},
                          {-1, -1},{0, -1},{-1, 0},{-1, 1},{1, -1}};

  n = 0;
  while (n < 8)
  {
    i = y;
    j = x;
     while (0 <= i + vec[n][0] && i + vec[n][0] <= 9 &&
            0 <= j + vec[n][1] && j + vec[n][1] <= 9)
     {
        i += vec[n][0];
        j += vec[n][1];
        if (ma[i][j] == 1)
          return (0);
     }
     n++;
  }
  return (1); 
}

int checkans(int ans[10], int x){
  int cnt;

  cnt = 0;
  while (cnt < 10)
  {
    if (ans[cnt] == x)
      return (0);
    cnt++;
  }
  return(1);
}

void dfs(int y, int ma[10][10], int cnt, int ans[10])
{
  int x;

  if (cnt > 1 && !check(y - 1, ans[cnt - 1], ma))
    return ;
  if (cnt == 10)
  {
    sum++;
    print(ans);
    return ;
  }
  x = 0;
  while (x <= 9)
  {
    if (cnt <= 0 || checkans && (ans[cnt - 1] - 1 > x || ans[cnt - 1] + 1 < x ))
    {
      ma[y][x] = 1;
  	  ans[cnt] = x;
  	  dfs(y + 1, ma, cnt + 1, ans);
      ma[y][x] = 0;
    }
    x++;
  }
}

int ft_ten_queens_puzzle(void)
{
  int ma[10][10];
  int i;
  int j;
  int ans[10];

  i = 0;
  while (i <= 9)
  {
    j = 0;
    while (j <= 9)
    {
      ma[i][j] = 0;
      j++;
    }
    i++;
  }
  dfs(0,ma,0,ans);
  return (sum);
}