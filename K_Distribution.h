#ifndef _K_Distribution_
#define _K_Distribution_


//2020.7.15
/*-----------------------------------------------------------------------------------
1.定义分布函数 
2.求解速率系数
------------------------------------------------------------------------------------*/

using namespace std;
class  K_Distribution_Class
{
public:
	K_Distribution_Class(double enery_max);
	~K_Distribution_Class();

	//得到分布函数
	void Maxwell_distri(double dis_Te);
	void Druyvesteyn_distri(double dis_Te);
	void Distribut_FromMcc_distri(double *f_v_distributionfunction);

	//得到速率系数
	double K_distri(double *p_sigma,double me_distri);

	int distri_n;
	double  distri_k;
	double distri_enery_delta;
	double distri_v_distributionfunction[4000];
	double distri_enery[4000];
	
private:
	
	double distri_c1;
	double distri_c2;
	double distri_te;
	double distri_enery_max;
	double distri_enery_min;
	double distri_sigma[4000];
};
#endif