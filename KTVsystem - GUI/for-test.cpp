#include"stdafx.h"
#include"for-test.h"
#include<fstream>
#include<iostream>

using namespace std;

void fortest::initSongLib()
{
	ofstream fout("song_lib.txt");
	fout << "14" << endl;
	fout << "1 ��� VS nh 0 4.5 23 129" << endl;
	fout << "2 debug VS debug 0 0.8 36543 10000991" << endl;
	fout << "3 ���� VS sj 0 4.1 5 29" << endl;
	fout << "4 ҹ������������ ���ܼƻ� ykzzldx 0 4.2 12 440" << endl;
	fout << "5 LoveStory TS lovestory 0 4.3 656 4325" << endl;
	fout << "6 ������� ��ʦ�� cxsj 0 5 234 236" << endl;
	fout << "7 NJU ������ nju 0 4.6 703 5437" << endl;
	fout << "8 ������Ϊ ���ٺ� nsyw 0 3.9 4 17" << endl;
	fout << "9 ������ � yxr 0 0 0 1" << endl;
	fout << "10 ���������� ������սNZBZ jadsn 0 4.5 2 5" << endl;
	fout << "11 ���� ë���� xc 0 0 0 4" << endl;
	fout << "12 �Ϸ����� ���� nfgn 0 0 0 3" << endl;
	fout << "13 ʲɲ�� � sch 0 0 0 2" << endl;
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