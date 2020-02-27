#include"stdafx.h"
#include"core.h"
#include<vector>
#include<fstream>
#include<iostream>
#include<iomanip>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;

song_lib::song_lib()
{
	ifstream fin("song_lib.txt");
	int len = 0;
	fin >> len;
	for (int i = 0; i < len; i++)
	{
		song_lib_unit temp;
		songlist.push_back(temp);
		fin >> songlist[i].num;
		fin >> songlist[i].songname;
		fin >> songlist[i].singer;
		fin >> songlist[i].pinyin;
		fin >> songlist[i].status;
		fin >> songlist[i].rating;
		fin >> songlist[i].ratingnum;
		fin >> songlist[i].airplay;
	}

	fin.close();
}

song_lib::~song_lib()
{
	ofstream fout("song_lib.txt");
	int len = songlist.size();
	fout << len << endl;
	for (int i = 0; i < len; i++)
	{
		fout << songlist[i].num << " ";
		fout << songlist[i].songname << " ";
		fout << songlist[i].singer << " ";
		fout << songlist[i].pinyin << " ";
		fout << songlist[i].status << " ";
		fout << songlist[i].rating << " ";
		fout << songlist[i].ratingnum << " ";
		fout << songlist[i].airplay << endl;
	}

	fout.close();
}

void song_lib::reorder()
{
	for (int i = 0; i < songlist.size(); i++)
	{
		songlist[i].num = i + 1;
	}
}

vector<song_lib::song_lib_unit> song_lib::Search(string Keyword)
{
	vector<song_lib_unit> ret;
	for (int i = 0; i < songlist.size(); i++)
	{
		if (Keyword==""||
			songlist[i].songname == Keyword ||
			songlist[i].singer == Keyword ||
			songlist[i].pinyin == Keyword)
		{
			ret.push_back(songlist[i]);
		}
	}

	return ret;
}

void song_lib::PrintSongs(vector<song_lib_unit> SongsToPrint)
{
	ofstream fout("print_service.txt");
	int len = SongsToPrint.size();
	int width = 7;
	fout << "ÐòºÅ ¸èÇúÃû ¸èÊÖÃû ¸èÇúÆ´Òô ×´Ì¬ ÆÀ·Ö ²¥·ÅÁ¿" << endl;
	for (int i = 0; i < len; i++)
	{
		fout << SongsToPrint[i].num << " ";
		fout << SongsToPrint[i].songname << " ";
		fout << SongsToPrint[i].singer << " ";
		fout << SongsToPrint[i].pinyin << " ";
		fout << SongsToPrint[i].status << " ";
		fout << setprecision(2)<< SongsToPrint[i].rating << " ";
		fout << SongsToPrint[i].airplay << endl;
	}
	fout.close();

	//page_print_service print(len, width);
}

bool song_lib::RateSong(int num, int givenrating)
{
	if (num >= 1 && num <= songlist.size())
	{
		songlist[num-1].rating = (double)(songlist[num-1].rating*songlist[num-1].ratingnum + givenrating) / (double)(songlist[num-1].ratingnum + 1);
		songlist[num-1].ratingnum++;

		return true;
	}
	else
		return false;

}

song_lib::song_lib_unit song_lib::PlaySong(int num)
{
	if (num >= 1 && num <= songlist.size())
	{
		songlist[num-1].airplay++;
		return songlist[num-1];
	}
	else
	{
		song_lib_unit nil;
		nil.num = -1;
		return nil;
	}
}

void song_lib::PrintSearch(string Keyword)
{
	PrintSongs(Search(Keyword));
}

bool song_lib::AddByHand(string songname, string singer, string pinyin)
{
	song_lib_unit newsong;
	newsong.num = songlist.size()+1;
	newsong.songname = songname;
	newsong.singer = singer;
	newsong.pinyin = pinyin;
	newsong.status = 0;
	newsong.rating = 0;
	newsong.ratingnum = 0;
	newsong.airplay = 0;

	songlist.push_back(newsong);

	//reorder;
	return true;
}

bool song_lib::AddByFile(string filename)
{
	ifstream fin(filename);
	int len = 0;
	fin >> len;
	for (int i = 1; i <= len; i++)
	{
		song_lib_unit temp;
		temp.num = 0;
		fin >> temp.songname;
		fin >> temp.singer;
		fin >> temp.pinyin;
		temp.status=0;
		temp.rating=0;
		temp.ratingnum=0;
		temp.airplay=0;
		songlist.push_back(temp);
	}

	fin.close();

	reorder();
	return true;
}

bool song_lib::AlterSong(int num, string songname, string singer, string pinyin)
{
	if (num >= 1 && num <= songlist.size())
	{
		songlist[num].songname = songname;
		songlist[num].singer = singer;
		songlist[num].pinyin = pinyin;

		return true;
	}
	else
		return false;
	
}

bool song_lib::DeleteSong(int num)
{
	if (num >= 1 && num <= songlist.size())
	{
		for (vector<song_lib_unit>::iterator index = songlist.begin(); index <= songlist.end(); index++)
		{
			if ((*index).num == num + 1)
			{
				songlist.erase(index);
				break;
			}
		}

		reorder();
		return true;
	}
	else
		return false;
}

void song_lib::SearchSongInfor()
{
	//print
	ofstream fout("print_service.txt");
	int len = songlist.size();
	int width = 7;
	fout << "ÐòºÅ ¸èÇúÃû ¸èÊÖÃû ¸èÇúÆ´Òô ×´Ì¬ ÆÀ·Ö ²¥·ÅÁ¿" << endl;
	for (int i = 0; i < len; i++)
	{
		fout << songlist[i].num << " ";
		fout << songlist[i].songname << " ";
		fout << songlist[i].singer << " ";
		fout << songlist[i].pinyin << " ";
		fout << songlist[i].status << " ";
		fout << setprecision(1) << songlist[i].rating << " ";
		fout << songlist[i].airplay << endl;
	}
	fout.close();

	//page_print_service print(len, width);
}

void song_lib::PrintRanking()
{
	vector<song_lib_unit> RankingList;
	for (int i = 1; i <= songlist.size(); i++)
	{
		RankingList.push_back(songlist[i - 1]);
	}

	//sort by airplay
	for (int i =  RankingList.size() - 1;i>=0; i--)
	{
		for (int j = 0; j < i; j++)
		{
			if (RankingList[j].airplay < RankingList[j + 1].airplay)
			{
				song_lib_unit temp = RankingList[j];
				RankingList[j] = RankingList[j + 1];
				RankingList[j + 1] = temp;
			}
		}
	}

	//print
	ofstream fout("print_service.txt");
	fout << "ÐòºÅ ¸èÇúÃû ¸èÊÖÃû ¸èÇúÆ´Òô ×´Ì¬ ÆÀ·Ö ²¥·ÅÁ¿" << endl;
	for (int i = 0; i < RankingList.size(); i++)
	{
		fout << RankingList[i].num << " ";
		fout << RankingList[i].songname << " ";
		fout << RankingList[i].singer << " ";
		fout << RankingList[i].pinyin << " ";
		fout << RankingList[i].status << " ";
		fout << setprecision(2) << RankingList[i].rating << " ";
		fout << RankingList[i].airplay << endl;
	}
	fout.close();

	//page_print_service print(RankingList.size(), 7);
}



user_infor::user_infor()
{
	ifstream fin("C:/KTVsystem/user_infor.txt");
	int len = 0;
	fin >> len;
	for (int i = 1; i <= len; i++)
	{
		user_infor_unit temp;
		fin >> temp.num;
		fin >> temp.status;
		userlist.push_back(temp);
	}

	fin.close();
}

user_infor::~user_infor()
{
	ofstream fout("user_infor.txt");
	int len = userlist.size();
	fout << len << endl;
	for (int i = 0; i < len; i++)
	{
		fout << userlist[i].num << " ";
		fout << userlist[i].status << " ";
	}

	fout.close();
}

int user_infor::GetUserStatus(int usernum)
{
	for (int i = 0; i < userlist.size(); i++)
	{
		if (userlist[i].num == usernum)
			return userlist[i].status;
	}

	return -1;
}



user_song::user_song()
{
	string fixed = "usersong";
	string filename = fixed + to_string(userID)+".txt";
	ifstream fin(filename);
	int len = 0;
	fin >> len;
	for (int i = 1; i <= len; i++)
	{
		user_song_unit temp;
		fin >> temp.seqnum;
		fin >> temp.song_infor.num;
		fin >> temp.song_infor.songname;
		fin >> temp.song_infor.singer;
		fin >> temp.song_infor.pinyin;
		fin >> temp.song_infor.status;
		fin >> temp.song_infor.rating;
		fin >> temp.song_infor.ratingnum;
		fin >> temp.song_infor.airplay;
		fin >> temp.status;
		usersonglist.push_back(temp);
	}

	fin.close();

	PrintList();
}

user_song::~user_song()
{
	string fixed = "usersong";
	string filename = fixed + to_string(userID) + ".txt";
	ofstream fout(filename);
//	fout << "0" << endl;
	int len = usersonglist.size();
	fout << len << endl;
	for (int i = 0; i < len; i++)
	{
		if (i == 0)
			usersonglist[i].status = 1;
		else
			usersonglist[i].status = 0;

		fout << usersonglist[i].seqnum << " ";
		fout << usersonglist[i].song_infor.num << " ";
		fout << usersonglist[i].song_infor.songname << " ";
		fout << usersonglist[i].song_infor.singer << " ";
		fout << usersonglist[i].song_infor.pinyin << " ";
		fout << usersonglist[i].song_infor.status << " ";
		fout << usersonglist[i].song_infor.rating << " ";
		fout << usersonglist[i].song_infor.ratingnum << " ";
		fout << usersonglist[i].song_infor.airplay << " ";
		fout << usersonglist[i].status << endl;
	}

	fout.close();
}

bool user_song::PlayASong(int num)
{
	song_lib_unit newsong = PlaySong(num);
	if (newsong.num != -1)
	{
		user_song_unit newusersong;
		newusersong.song_infor = newsong;
		newusersong.status = 0;
		newusersong.seqnum = usersonglist.size();

		usersonglist.push_back(newusersong);
		return true;
	}
	else
		return false;
}

void user_song::SearchASong(string Keyword)
{
	PrintSearch(Keyword);
}

bool user_song::StickTop(int num)
{
	if (num >= 0 && num < usersonglist.size())
	{
		usersonglist[num].seqnum = 0;
		user_song_unit temp = usersonglist[num];
		for (int i = num; i>0; i--)
		{
			usersonglist[i] = usersonglist[i - 1];
			usersonglist[i].seqnum = i;
		}
		usersonglist[0] = temp;

		return true;
	}
	else
		return false;
}

bool user_song::DelASong(int num)
{
	if (num >= 0 && num < usersonglist.size())
	{
		for (int i = num; i < usersonglist.size() - 1; i++)
		{
			usersonglist[i] = usersonglist[i + 1];
			usersonglist[i].seqnum = i;
		}
		usersonglist.pop_back();

		return true;
	}
	else
		return false;
}

bool user_song::RateASong(int num, int givenrating)
{
	return RateSong(num, givenrating);
}

void user_song::PrintList()
{
	ofstream fout("print_service.txt");
	fout << "²¥·ÅË³Ðò ÏµÍ³ÐòºÅ ¸èÇúÃû ¸èÊÖÃû ¸èÇúÆ´Òô ÆÀ·Ö ²¥·ÅÁ¿ ²¥·Å×´Ì¬" << endl;
	for (int i = 0; i < usersonglist.size(); i++)
	{
		fout << usersonglist[i].seqnum << " ";
		fout << usersonglist[i].song_infor.num << " ";
		fout << usersonglist[i].song_infor.songname << " ";
		fout << usersonglist[i].song_infor.singer << " ";
		fout << usersonglist[i].song_infor.pinyin << " ";
		fout << usersonglist[i].song_infor.rating << " ";
		fout << usersonglist[i].song_infor.airplay << " ";
		fout << ((usersonglist[i].status == 1) ? "ÕýÔÚ²¥·Å" : "×¼±¸ÖÐ") << endl;
	}
	fout.close();

	//page_print_service print(usersonglist.size(), 8);
}

void user_song::Exist()
{
	usersonglist.swap(vector<user_song_unit>());
}



admin_infor::admin_infor()
{
	ifstream fin("admin_infor.txt");
	int len = 0;
	fin >> len;
	for (int i = 1; i <= len; i++)
	{
		admin_infor_unit temp;
		fin >> temp.adminID;
		fin >> temp.adminpassword;
		adminlist.push_back(temp);
	}

	fin.close();
}

admin_infor::~admin_infor()
{
	ofstream fout("admin_infor.txt");
	int len = adminlist.size();
	fout << len << endl;
	for (int i = 0; i < len; i++)
	{
		fout << adminlist[i].adminID << " ";
		fout << adminlist[i].adminpassword << " ";
	}

	fout.close();
}

bool admin_infor::ChangePassword(string inputID,string oldpassword, string newpassword)
{
	for (int i = 0; i < adminlist.size(); i++)
	{
		if (inputID == adminlist[i].adminID)
		{
			if (oldpassword == adminlist[i].adminpassword)
			{
				adminlist[i].adminpassword = newpassword;
				return true;
			}
			else
				return false;
		}
	}

	return false;
}

bool admin_infor::SignIn(string inputID, string password)
{
	for (int i = 0; i < adminlist.size(); i++)
	{
		if (inputID == adminlist[i].adminID)
		{
			if (password == adminlist[i].adminpassword)
				return true;
			else
				return false;
		}
	}

	return false;
}