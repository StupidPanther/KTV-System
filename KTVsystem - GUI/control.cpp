#include"stdafx.h"
#include"control.h"
#include<iostream>
#include<vector>
#include<conio.h>

user::user(int inputID)
{
	userID = inputID;
}

void user::PlayASong(int num)
{
	user_song::PlayASong(num);
}

void user::SearchASong(string Keyword)
{
	user_song::SearchASong(Keyword);
}

void user::StickTop(int num)
{
	user_song::StickTop(num);
}

void user::DelASong(int num)
{
	user_song::DelASong(num);
}

void user::NextSong()
{
	DelASong(0);
}

void user::RateASong(int num,int Rating)
{
	user_song::RateASong(num, Rating);
}

void user::PrintList()
{
	user_song::PrintList();
}

/*
void user::operate()
{
	int cmd = 0;
	do
	{
		string menu[] = { "点    歌","置    顶","删    除","评    分","查看已点","退    出" };
		vector<string> inputmenu;
		for (int i = 0; i < 6; i++)
			inputmenu.push_back(menu[i]);
		//dialog_service dialog(inputmenu);

		do
		{
			cmd = _getch();
		} while (cmd < '1' || cmd>'6');

		switch (cmd)
		{
		case '1':PlayASong(); break;
		case '2':StickTop(); break;
		case '3':DelASong(); break;
		case '4':RateASong(); break;
		case '5':PrintList(); break;
		}
	} while (cmd != '6');
}*/

void user::Exist()
{
	user_song::Exist();
}



admin::admin()
{
	//adminID = inputadminID;
}

void admin::AddByHand(string songname,string singer,string pinyin)
{
	song_lib::AddByHand(songname, singer, pinyin);
}

void admin::AddByFile(string Path)
{
	song_lib::AddByFile(Path);
}

void admin::AlterSong(int num,string songname,string singer,string pinyin)
{
	song_lib::AlterSong(num, songname, singer, pinyin);
}

void admin::DeleteSong(int num)
{
	song_lib::DeleteSong(num);
}

void admin::SearchSongInfor()
{
	song_lib::SearchSongInfor();
}

void admin::PrintRanking()
{
	song_lib::PrintRanking();
}

void admin::ChangePassword()
{
	string OldPassword;
	string NewPassword;
	string NewPasswordAgain;

	do
	{
		cout << "Old Password       : ";
		cin >> OldPassword;
		cout << "New Password       : ";
		cin >> NewPassword;
		cout << "New Password again : ";
		cin >> NewPasswordAgain;

		if (NewPassword != NewPasswordAgain)
			continue;
	} while (admin_infor::ChangePassword(adminID, OldPassword, NewPassword));
}
/*
void admin::operate()
{
	int cmd = 0;
	do
	{
		string menu[] = { "添加歌曲","批量添加","修    改","删    除","歌库信息","歌曲排名","修改密码","退    出" };
		vector<string> inputmenu;
		for (int i = 0; i < 8; i++)
			inputmenu.push_back(menu[i]);
		//dialog_service dialog(inputmenu);

		do
		{
			cmd = _getch();
		} while (cmd < '1' || cmd>'8');

		switch (cmd)
		{
		case '1':AddByHand(); break;
		case '2':AddByFile(); break;
		case '3':AlterSong(); break;
		case '4':DeleteSong(); break;
		case '5':SearchSongInfor(); break;
		case '6':PrintRanking(); break;
		case '7':ChangePassword(); break;
		}
	} while (cmd != '8');
}*/