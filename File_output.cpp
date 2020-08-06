#include  "File_output.h"
#include  <iomanip>

using namespace std;

//a 0�ļ�β׷�� ���������д   b 0 .m�ļ� ����.txt�ļ�
Ofstream_me::Ofstream_me(string filename,int a,int b)
{
	control = b;
	control1 = a;
	file_name = filename;
	name = filename+"_out";
	Open_file(1);
}

//���ļ�
void Ofstream_me::Open_file(int II)
{
	if (II == 1)
	{
		if (control == 0)
			file_name = file_name + ".m";
		else
			file_name = file_name + ".txt";
	}

	if (control1 == 0)
		file.open(file_name.c_str(), ios::app | ios::out);
	else
		file.open(file_name.c_str(), ios::ate | ios::out);

	if (!file.is_open())
	{
		cout << "\nerror on open " << file_name << " file!" << endl;
		getchar();
	}

	if (control == 0)
		file << name << "= [";
}

//д��һ������
void Ofstream_me::Output_file(string datestr, double date_date)
{
	file << datestr<<":" << date_date << endl;
}
//void Ofstream_me::Output_file(double date_date)
//{
//	file << date_date << endl;
//}


//дһ��һά����д�����
void Ofstream_me::Output_file1(double *p, int size)
{
	size1_file = size;
	file.setf(ios::scientific);
	for (int i = 0; i < size1_file; i++)
	{
		file << *(p + i) << ' ';//<<"\n"
	}
	file << endl;
	file.unsetf(ios::scientific);
}
void Ofstream_me::Output_file1(double *p,double inital,int size)
{
	size1_file = size;
	file.setf(ios::scientific);
	for (int i = 0; i < size1_file; i++)
	{
		file << (*(p + i))*inital<<' ';//<<"\n"
	}
	file << endl;
	file.unsetf(ios::scientific);
}
void Ofstream_me::Output_file1(double *p, double *inital, int size)
{
	size1_file = size;
	file.setf(ios::scientific);
	for (int i = 0; i < size1_file; i++)
	{
		file << (*(p + i))*(*(inital+i)) << ' ';
		//cout << *(p + i) << ' ' << *(inital+i) <<endl; //���Խ���Ƿ���ȷ
	}
	file << endl;
	file.unsetf(ios::scientific);
}

//void Ofstream_me::Output_file1(double *p, int size, string datestr)
//{
//	file << datestr << ":" << endl;
//	Output_file1(p, size);
//}

//void Ofstream_me::Output_file1(double *p, int size, int dat)
//{
//	file << dat << endl;
//	Output_file1(p, size);
//}
//void Ofstream_me::Output_file1(double *p, double inital, int size, int dat)
//{
//	file << dat << endl;
//	Output_file1(p,  inital, size);
//	//Output_file1(p, size);
//}
//void Ofstream_me::Output_file1(double *p, double *inital, int size, int dat)
//{
//	file << dat << endl;
//	Output_file1(p, inital, size);
//	//Output_file1(p, size);
//}
//

//���ļ���дһ����ά����
void Ofstream_me::Output_file2(double *p, int size1, int size2)//���������������ȷ�����λ
{
	//����size1��ʾ�У�size2��ʾ�С�
	size1_file = size1;
	size2_file = size2;
	file.setf(ios::scientific);
	for (int j = 0; j < size1_file; j++)
	{
		for (int i = 0; i < size2_file; i++)
		{
			file << *(p + i+j*size1) << ' ';
		}
		file << endl;
	}
	file.unsetf(ios::scientific);
}
//void Ofstream_me::Output_file2(double *p, int size1, int size2, int dat)
//{
//	file << dat << endl;
//	Output_file2(p,size1,size2);
//}

//�ú����������������
//void Ofstream_me::Close()	
//{
//	if (control == 0)
//	{
//		file << "];";
//	}
//	file.close();
//}

void Ofstream_me::Updater_file()
{
	//a=0,�ļ�β׷�ӣ�a=\�������д
	int Y_N;
	file.close();
	Y_N=remove(file_name.c_str());
	if (Y_N == 1)
	{
		cout << "\n error deletion " << file_name << " file!" << endl;
		getchar();
	}
	Open_file(2);
}

Ofstream_me::~Ofstream_me()
{
	if (control == 0)
	{
		file << "];";
	}
	file.close();
	cout << "delete " << file_name<<endl;
}