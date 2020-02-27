#pragma once
#include"core.h"

class user:private user_infor, private user_song
{
private:
	int userID;

public:
	//user in
	void PlayASong(int num);
	void SearchASong(string Keyword);
	void StickTop(int num);
	void DelASong(int num);
	void NextSong();
	void RateASong(int num, int Rating);

	//user out
	void PrintList();//查看已点
	void Exist();

	user(int inputID);
//	void operate();
};

class admin:private song_lib, private admin_infor
{
private:
	string adminID;

public:
	//admin in
	void AddByHand(string songname, string singer, string pinyin);
	void AddByFile(string Path);
	void AlterSong(int num, string songname, string singer, string pinyin);
	void DeleteSong(int num);

	//admin out
	void SearchSongInfor();
	void PrintRanking();

	//admin in
	void ChangePassword();

	admin();
	void operate();
};