#ifndef _File_output_
#define _File_output_

#include  <iostream>
#include  <fstream>
#include<string>

/*------------------------------------------
����������        a=0 �����Ǽ�ÿ���ں����ۼ����  a=1 ����
                            b=0 �½�����matlab�ļ�  .m�ļ�     b=1 �½�����txt�ļ�  .txt�ļ�
Output_file1��   *p ָ�������ָ�� intial �����ٻ���ֵ����ָ�� size 
                            �������ش���̫�������ٻ���ֵ����Ϊdouble ����������1.0���
Output_file2��   size1�������뾫ȷ�����򲻶Իᴮ��
//------------------------------------------*/

using namespace std;
class Ofstream_me
{
public:
	Ofstream_me(string filename, int a,int b);//a 0�ļ�β׷�� ���������д   b 0 .m�ļ� ����.txt�ļ�
	void Open_file(int II); 
	void Output_file(string datestr, double datefile); // д datestr: datefile
	//void Output_file(double date_date);	//дһ����������

	void Output_file1(double *p, int size);	//*p ������ ����Ĵ�С
	void Output_file1(double *p, double inital, int size);//�����ٻ���ֵһ���� double   *p�����inital��������ļ���ֵ��Ϊ��ʵֵ
	void Output_file1(double *p, double *inital, int size);//*p�����inital���飬��Ӧ���

	//void Output_file1(double *p, int size, string datestr);//datestr:��һ����ֵ
	//void Output_file1(double *p, int size1, int dat);//date ��ʾ��	 dat ��һ����ֵ	 �õĸ��ʲ��������׺�(double *p, double inital, int size)��
	//void Output_file1(double *p, double inital, int size, int dat);
	//void Output_file1(double *p, double *inital, int size, int dat);

	void Output_file2(double *p, int size1, int size2);//size1 ��  size2 ��  ����Ҫ��ȷ�������״�λ *p��A[][]����A[]��ʾ 
	//void Output_file2(double *p, int size1, int size2, int dat);//dat ��һ������  size1 ��  size2 �� 
	void Updater_file();//����ļ��������
	//void Close();//�ر��ļ�д������������
	//string date_str;
	//double date_file;
	~Ofstream_me();//��Ҫ����	
	ofstream file;
private:
	int size1_file, size2_file, control, control1;
	//~Ofstream_me();
	string file_name,name;
};
#endif