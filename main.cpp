#include <iostream>
#include <conio.h>
#include <windows.h>
#include <time.h>
using namespace std;
COORD c, o, f, clear; //current 座標  old 座標 food 座標
int tmp = 0;
char key = 'd';  //蛇一開始變會往右走
int speed = 250;//蛇走路速度
int total_speed;
int judge = 3; //速度差
int score_judge = 2;//分數差
int score = 0;
int restart_food_time=30;
char old_key = 0, new_key = 0; //新舊按鍵
#include "snake_body.h"
#include "game.h"
#include "major.h"
#include "Difficulty.h"
int main()
{
	system("mode con cols=85 lines=30");
	system("title 貪吃蛇v1.1        created by Majitoo");
	system("color 2");
	int menu, input_dif = 2;
	while (1)
	{
		system("cls");
		game_start_UI();
		goxy(30, 18);
		cout << "請輸入你想要執行的功能:";
		goxy(42, 20);
		cin >> menu;
		system("cls");
		switch (menu)
		{
		case 1:
			show_UI(input_dif);
			reload_difficult(input_dif);
			score = 0;
			major(menu);
			goxy(20, 12);
			cout<<"遊戲結束!";
			goxy(20, 14);
			system("pause");
			goxy(20, 12);
			cout << "                         ";
			goxy(20, 14);
			system("                          ");
			goxy(20, 12);
			cout << "您的分數為:" << score << endl;
			goxy(20, 14);
			system("pause");
			system("cls");
			break;
		case 2:
			difficulty(input_dif, speed);
			break;
		case 3:
			exit(0);
		default:
			game_start_UI();
			goxy(20, 18);
			cout << "輸入錯誤! 請重新輸入!";
			system("pause");
		}
	}
}
