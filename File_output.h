#ifndef _File_output_
#define _File_output_

#include  <iostream>
#include  <fstream>
#include<string>

/*------------------------------------------
析构函数中        a=0 不覆盖即每次在后面累加输出  a=1 覆盖
                            b=0 新建的是matlab文件  .m文件     b=1 新建的是txt文件  .txt文件
Output_file1中   *p 指向数组的指针 intial 无量纲化的值或者指针 size 
                            由于重载次数太多无量纲化的值必须为double 如果不是则乘1.0解决
Output_file2中   size1行数必须精确，否则不对会串行
//------------------------------------------*/

using namespace std;
class Ofstream_me
{
public:
	Ofstream_me(string filename, int a,int b);//a 0文件尾追加 其他清空再写   b 0 .m文件 其他.txt文件
	void Open_file(int II); 
	void Output_file(string datestr, double datefile); // 写 datestr: datefile
	//void Output_file(double date_date);	//写一个单独数据

	void Output_file1(double *p, int size);	//*p 数组名 数组的大小
	void Output_file1(double *p, double inital, int size);//无量纲化的值一定是 double   *p数组乘inital把输出到文件的值变为真实值
	void Output_file1(double *p, double *inital, int size);//*p数组乘inital数组，对应相乘

	//void Output_file1(double *p, int size, string datestr);//datestr:下一行数值
	//void Output_file1(double *p, int size1, int dat);//date 提示量	 dat 下一行数值	 用的概率不大但是容易和(double *p, double inital, int size)混
	//void Output_file1(double *p, double inital, int size, int dat);
	//void Output_file1(double *p, double *inital, int size, int dat);

	void Output_file2(double *p, int size1, int size2);//size1 行  size2 列  行数要正确否者容易错位 *p（A[][]）用A[]表示 
	//void Output_file2(double *p, int size1, int size2, int dat);//dat 下一行数据  size1 行  size2 列 
	void Updater_file();//清空文件里的数据
	//void Close();//关闭文件写在析构函数中
	//string date_str;
	//double date_file;
	~Ofstream_me();//需要调用	
	ofstream file;
private:
	int size1_file, size2_file, control, control1;
	//~Ofstream_me();
	string file_name,name;
};
#endif