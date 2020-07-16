#ifndef _K_Distribution_
#define _K_Distribution_
//#include<>

//2020.7.15
/*—————————————
1.定义分布函数 
2.求解速率系数
——————————————*/

using namespace std;
class  K_Distribution_Class
{
public:
	K_Distribution_Class(double enery);//构造函数
	~K_Distribution_Class();//析构函数
	void Maxwell_distri(double dis_Te);
	void Druyvesteyn_distri(double dis_Te);
	void DistributMc_distri(double *f_eedf);

	double K_distri(double *p_sigma,double m_distri);

	double distri_Te, distri_eedf[4000];
	double distri_enery[4000], distri_enery_delta, distri_enery_max, distri_enery_min;
	double distri_sigma[4000], distri_K, distri_C1, distri_C2;
	int distri_n;
private:
	//double distri_enery[4000], distri_enery_delta, distri_enery_max, distri_enery_min;
	//double distri_sigma[4000], distri_K, distri_C1, distri_C2;
	
};
#endif