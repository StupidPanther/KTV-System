#pragma once
#include<string>
#include<vector>
#include<fstream>
using namespace std;
//testtesttest
class song_lib
{
protected:
	class song_lib_unit
	{
		int num;
		string songname;
		string singer;
		string pinyin;
		int status;
		double rating;
		int ratingnum;
		int airplay;//中文：播放量

		friend class song_lib;
		friend class user_song_unit;
		friend class user_song;
	};

private:
	vector<song_lib_unit> songlist;

	void reorder();
	vector<song_lib_unit> Search(string Keyword);
	void PrintSongs(vector<song_lib_unit> SongsToPrint);

protected:
	song_lib();
	~song_lib();

	//user_song in
	bool RateSong(int num, int givenrating);

	//user_song out
	song_lib_unit PlaySong(int num);//点歌
	void PrintSearch(string Keyword);

	//admin in
	bool AddByHand(string songname, string singer, string pinyin);
	bool AddByFile(string filename);
	bool AlterSong(int num, string songname, string singer, string pinyin);
	bool DeleteSong(int num);

	//admin out
	void SearchSongInfor();
	void PrintRanking();
};

class user_infor
{
private:
	class user_infor_unit
	{
		int num;
		int status;

		friend class user_infor;
	};

	vector<user_infor_unit> userlist;

protected:
	user_infor();
	~user_infor();

	//system out
	int GetUserStatus(int usernum);
};

class user_song:private song_lib
{
private:
	class user_song_unit
	{
		int seqnum;
		song_lib_unit song_infor;
		int status;

		friend class user_song;
	};

	int userID;
	vector<user_song_unit> usersonglist;

protected:
	user_song();
	~user_song();

	//user in
	bool PlayASong(int num);
	void SearchASong(string Keyword);
	bool StickTop(int num);
	bool DelASong(int num);
	bool RateASong(int num,int givenrating);
	void Exist();

	//user out
	void PrintList();//查看已点
};

class admin_infor
{
private:
	class admin_infor_unit
	{
		string adminID;
		string adminpassword;

		friend class admin_infor;
	};

	vector<admin_infor_unit> adminlist;

protected:
	admin_infor();
	~admin_infor();

	//admin in
	bool ChangePassword(string inputID,string oldpassword,string newpassword);
	
	//system out
	bool SignIn(string inputID,string password);
};