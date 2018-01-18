#include <iostream>
#include <conio.h>
#include <windows.h>
#include <time.h>
using namespace std;
void snake_next();
void show_UI();
void display_snake(snake_body &b);
bool check_key();
void add_score(snake_body &b);
void update_data();
void check_food();
void key_way();
void SetColor(int ForgC);

void hide_snake(snake_body& b)
{
	snake_body *p = &b,*tmper;
	while (1)      //把舊座標掃一變 並屏蔽
	{
		clear = p->get_old_body();
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), clear);
		cout << " ";
		tmper = p->get_pnext();
		if (tmper == NULL)
			break;
		else
		{
			p = p->get_pnext();
		}
	}

}
void SetColor(int ForgC)
{
	WORD wColor;
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	if (GetConsoleScreenBufferInfo(hStdOut, &csbi))
	{
		wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
		SetConsoleTextAttribute(hStdOut, wColor);
	}
	return;
}
void display_snake(snake_body &b)
{
	snake_body *p=&b,*tmper;
	int count=0;
	while (1)
	{
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), p->get_body());
		if (count == 0)
			SetColor(15);
		else
			SetColor(7);
		cout << "▉";
		tmper = p->get_pnext();
		if (tmper == NULL)
			break;
		else
		{
			p = p->get_pnext();
		}
		count++;
	}
}
void generate_body(snake_body &b,COORD &o)
{
	snake_body *p=&b,*tmper;
	static snake_body body[1000] = {snake_body(0,0)}; //陣列控制最大身體數
	while (1)
	{
		tmper = p->get_pnext();
		if (tmper == NULL)
			break;
		else
		{
			p = p->get_pnext();
		}
	}
	p->set_next(&body[score]);
}
void clear_body(snake_body& b) //切斷所有節點並初始化為0
{
	int count=1;
	while (count<=score)
	{
		snake_body *p = &b, *tmper;
		for (int i = 0; i < score - count;i++)
		{
			tmper = p->get_pnext();
			if (tmper == NULL)
				break;
			else
			{
				p = p->get_pnext();
			}
		}
		p->set_xy(0,0);
		count++;
	} 
}
bool Collision(snake_body& b)//array[25][50]
{
	snake_body *p = &b, *tmper;
	while (1)
	{
		tmper = p->get_pnext();
		if (tmper == NULL)
			break;
		else
		{
			p = p->get_pnext();
			if (p->get_x() == c.X && p->get_y() == c.Y)
				return true;
		}
	}
	o.X = c.X;
	o.Y = c.Y;
	if (c.X>46 || c.X<1)
		return true;
	if (c.Y > 23 || c.Y<1)
		return true;
	else
		return false;
}

void new_pos(snake_body &b)
{
	snake_body *p=&b,*tmper;
	COORD new_pos = c, tmp;
	while (1)
	{
		tmp = p->get_body();
		p->set_old_body(tmp);
		p->set_body(new_pos);
		new_pos = tmp;
		tmper = p->get_pnext();
		if (tmper == NULL)
			break;
		else
		{
			p=p->get_pnext();
		}
	}

}
void goxy(int x, int y)
{
	COORD xy;
	xy.X = x - 1;
	xy.Y = y - 1;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), xy);
}

void difficuly_UI()
{
	int i, j;
	printf("                    ╔＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝╗\n");
	for (i = 1; i <= 19; i++)
	{
		for (j = 0; j <= 20; j++)
		{
			if (j == 0)
			{
				printf("                    ∥");
			}
			else if (j == 20)
			{
				printf("∥");
			}
			else
			{
				printf("  ");
			}
		}
		printf("\n");
	}
	printf("                    ╚＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝╝\n");
}
void show_UI(int &input_dif)
{
	SetColor(2);
	goxy(1, 1);
	int i, j;
	for (i = 0; i<25; i++)
	{
		for (j = 0; j<50; j++)
		{
			if (i == 0 || j == 0 || i == 24 || j == 49)
				cout << "*";
			else
				cout << " ";
		}
		cout << endl;
	}
	if (input_dif == 1)
	{
		SetColor(12);
		goxy(55, 3);
		cout << "您現在玩得是簡單模式!";
	}
	if (input_dif == 2)
	{
		SetColor(12);
		goxy(55, 3);
		cout << "您現在玩得是普通模式!";
	}
	if (input_dif == 3)
	{
		SetColor(12);
		goxy(55, 3);
		cout << "您現在玩得是困難模式!";
	}
}

bool check_key()  //判斷新鍵是否和舊鍵反方向 如果確定反方向返回true
{
	if (old_key == 'd' && new_key == 'a')
		return true;
	else if (old_key == 'a' && new_key == 'd')
		return true;
	else if (old_key == 'w' && new_key == 's')
		return true;
	else if (old_key == 's' && new_key == 'w')
		return true;
	else if (key != 'w' && key != 'W' && key != 's' && key != 'S' && key != 'a' && key != 'A' && key != 'd' && key != 'D' && key!=32)
		return true;
	else
		return false;
}

void key_way(snake_body& b)
{
	switch (key)
	{
	case 'a':
	case 'A':
		c.X -= 2;
		break;
	case 'd':
	case 'D':
		c.X += 2;
		break;
	case 'w':
	case 'W':
		c.Y--;
		break;
	case 's':
	case 'S':
		c.Y++;
		break;
	}
}
void game_over()
{

	goxy(20, 10);
	cout << "撞到了!";
}
void update_data()
{
	int output = total_speed % speed;
	if (speed >= 50)
	{
		SetColor(14);
		goxy(55, 10);
		printf("速度:%3d", output);
	}
	else
	{
		SetColor(14);
		goxy(55, 10);
		printf("速度:∞");
	}
	SetColor(14);
	goxy(55, 20);
	printf("分數:%3d", score);
}
bool add_score()
{
	if (c.X == f.X && c.Y == f.Y)
	{
		score+=score_judge;
		tmp = 0;
		if (speed>50)
			speed -= judge;
		return true;
	}
	return false;
}
void check_food(snake_body& b)
{
	restart:
	if (tmp % restart_food_time == 0)
	{
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), f);
		printf(" ");
		f.X = (rand() % 46) + 1; //2~50
		if (f.X % 2 != 0)
			f.X++;
		f.Y = (rand() % 23) + 1; //2~25
	}
	snake_body *p = &b, *tmper;
	while (1)
	{
		tmper = p->get_pnext();
		if (tmper == NULL)
			break;
		else
		{
			p = p->get_pnext();
			if (p->get_x() == f.X && p->get_y() == f.Y)
				goto restart;
		}
	}
	SetColor(12);
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), f);
	printf("●");
	//goxy(55, 13);    //debug mod
	//printf("%2d,%2d", c.X, c.Y);
	//goxy(55, 15);
	//printf("%2d,%2d", f.X, f.Y);
	tmp++;
}

