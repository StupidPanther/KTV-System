#include"stdafx.h"
#include"for-test.h"
#include<fstream>
#include<iostream>

using namespace std;

void fortest::initSongLib()
{
	ofstream fout("song_lib.txt");
	fout << "14" << endl;
	fout << "1 你好 VS nh 0 4.5 23 129" << endl;
	fout << "2 debug VS debug 0 0.8 36543 10000991" << endl;
	fout << "3 世界 VS sj 0 4.1 5 29" << endl;
	fout << "4 夜空中最亮的星 逃跑计划 ykzzldx 0 4.2 12 440" << endl;
	fout << "5 LoveStory TS lovestory 0 4.3 656 4325" << endl;
	fout << "6 程序设计 老师好 cxsj 0 5 234 236" << endl;
	fout << "7 NJU 张凌宇 nju 0 4.6 703 5437" << endl;
	fout << "8 年少有为 李荣浩 nsyw 0 3.9 4 17" << endl;
	fout << "9 异乡人 李健 yxr 0 0 0 1" << endl;
	fout << "10 骄傲的少年 南征北战NZBZ jadsn 0 4.5 2 5" << endl;
	fout << "11 消愁 毛不易 xc 0 0 0 4" << endl;
	fout << "12 南方姑娘 赵雷 nfgn 0 0 0 3" << endl;
	fout << "13 什刹海 李健 sch 0 0 0 2" << endl;
	fout << "14 AsLongAsYouLoveMe JustinBieber alaylm 0 0 0 1" << endl;
	fout.close();
}

void fortest::initAdminInfor()
{
	ofstream fout("admin_infor.txt");
	fout << "4" << endl;
	fout << "admin admin" << endl;
	fout << "boss ktvboss" << endl;
	fout << "netease wangyi" << endl;
	fout << "tencent tengxun" << endl;
	fout.close();
}

fortest::fortest()
{
	initSongLib();
	initAdminInfor();
}