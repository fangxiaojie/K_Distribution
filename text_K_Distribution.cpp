#include "K_Distribution.h"
#include  "File_output.h"
//测试文件

int main()
{
	double Sigma[4000],EedfText[4000];
	Ofstream_me	text_out("text",0,1);
	K_Distribution_Class dis(100);
	dis.Druyvesteyn_distri(3.0);
	//dis.Maxwell_distri(3.0);
	text_out.Output_file1(dis.distri_enery, dis.distri_n);
	text_out.Output_file1(dis.distri_eedf, dis.distri_n);
	Sigma[0] = 0.0;//验证能量分布函数是否归一化
	for  (int i = 1; i < 4000; i++)
	{
		Sigma[0] = dis.distri_eedf[i]*dis.distri_enery_delta + Sigma[0];
		Sigma[i] = 1.0;
		EedfText[i] = dis.distri_eedf[i] / sqrt(dis.distri_enery[i]);
	}
	cout << Sigma[0];
	text_out.Output_file1(EedfText, dis.distri_n);
	dis.DistributMc_distri(EedfText);
	text_out.Output_file1(dis.distri_eedf, dis.distri_n);
	dis.Maxwell_distri(3.0);
	dis.K_distri(Sigma,9.1E-31);
	cout << dis.distri_K << endl;
	//text_out.~Ofstream_me();
	//dis.~K_Distribution_Class();
	return 0;
}