#include <iostream>
#include <conio.h>
#include <windows.h>
#include <time.h>
void game_start_UI()
{
	SetColor(15);
	cout << "*********************************";SetColor(13); cout << "使用前注意事項"; SetColor(15); cout << "************************************" << endl;
	printf("\n");
	printf("*  1.  W A S D 可操控蛇 上 下 左 右                                               *\n");
	printf("*  2.  輸入space 空格鍵即可暫停遊戲                                               *\n");
	printf("*  3.  簡單模式吃一個食物加一分                                                   *\n");
	printf("*  4.  普通模式吃一個食物加兩分                                                   *\n");
	printf("*  5.  困難模式吃一個食物加三分                                                   *\n");
	printf("*  6.  遊戲預設難度為普通難度,若要調整難度，輸入2!                                *\n");
	printf("*  7.                                                                             *\n");
	printf("*  8.                                                                             *\n");
	printf("*                                                                                 *\n");
	printf("*                                輸入 1 開始遊戲                                  *\n");
	printf("*                                輸入 2 難度設定                                  *\n");
	printf("*                                輸入 3 結束程式                                  *\n");
	printf("*                                                                                 *\n\n");
	printf("***********************************************************************************\n");
}
void major(int& menu)
{
	srand((unsigned int)time(NULL)); //打亂食物生成的座標
	c.X = 24, c.Y = 12;
	o.X = 22, o.Y = 12;
	snake_body b(c.X, c.Y); //頭點 /20 
	b.set_body(c);
	f.X = (rand() % 47) + 1, f.Y = (rand() % 23) + 1;
	tmp = 0;
	score = 0;
	key = 'd';
	old_key = 0, new_key = 0;
	while (1)
	{
		display_snake(b);
		Sleep(speed);
		if (_kbhit()) //判斷使否有新的按鍵輸入
		{
			old_key = new_key;
			key = _getch();
			new_key = key;
		}
		if (check_key() == false)  //新鍵和舊鍵並無衝突 移動蛇
		{
			if (key == 32)
			{
				key = old_key;
				new_key = key;
				goxy(55, 13);
				cout << "遊戲以暫停!";
				goxy(52, 15);
				system("pause");
				goxy(52, 15);
				cout << "                                ";
				goxy(52, 13);
				cout << "                                ";
			}
			key_way(b);
		}
		else                                       //新鍵是舊鍵的反方向 把舊鍵重設為新鍵 並照常移動座標
		{
			key = old_key;
			new_key = key;
			key_way(b);
		}
		if (add_score() == true)
		{
			generate_body(b, o);
		}
		new_pos(b);
		update_data();
		check_food(b);
		if (Collision(b) == true)
		{
			menu = 2;
			break;
		}
		hide_snake(b);
	}
	clear_body(b);
}
