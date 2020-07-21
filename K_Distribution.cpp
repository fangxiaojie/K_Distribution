#include "K_Distribution.h"
#include  <fstream>
#include  <iostream>

/*----------------------------------------------------------------------------------------------------------
  K_=sqrt(2*1.6E-19/Me)*[sigma*sqrt(enery)*f(enery)*delta_enery] 0_+00
  f(enery)=2.0/sqrt(Pi)*(Te^-1.5)*sqrt(energy)*exp(-energy/Te)  Max
-----------------------------------------------------------------------------------------------------------*/

using namespace std;
K_Distribution_Class::K_Distribution_Class(double enery_max)
{
	distri_enery_max = enery_max;
	distri_enery_min = 0.0;
	distri_n = 4000;
	distri_enery_delta = (distri_enery_max - distri_enery_min) / distri_n;
	for (int i = 0; i <distri_n ; i++)
	{
		distri_enery[i] = i*distri_enery_delta;
		distri_sigma[i] = 0.0;
		distri_v_distributionfunction[i] = 0.0;
	}
	//³õÊ¼»¯
	distri_c1 = 0.0;
	distri_c2 = 0.0;
	distri_te = 0.0;
	distri_k = 0.0;
}

K_Distribution_Class::~K_Distribution_Class()
{
	cout << endl<<"bye distribution_function"<<endl;
}

void K_Distribution_Class::Maxwell_distri(double dis_Te)
{
	distri_te = dis_Te;
	for (int i = 0; i < distri_n; i++)
	{
		distri_v_distributionfunction[i] = 2.0 / sqrt(3.1415926)*pow(distri_te, -1.5)*sqrt(distri_enery[i])*exp(-distri_enery[i] / distri_te);
	}
}

void K_Distribution_Class::Druyvesteyn_distri(double dis_Te)
{
	distri_c1 = 0.56515196759131;
	distri_c2 = 0.24315995724738;
	distri_te = dis_Te;
	for (int i = 0; i < distri_n; i++)
	{
		distri_v_distributionfunction[i] = distri_c1*pow(distri_te, -1.5)*sqrt(distri_enery[i])*exp(-distri_c2 *distri_enery[i]*distri_enery[i]/ (distri_te*distri_te));
	}
}

void K_Distribution_Class::Distribut_FromMcc_distri(double *f_eedf)
{
	for (int i = 0; i < distri_n; i++)
	{
		distri_v_distributionfunction[i] = *(f_eedf + i);
	}
}

double K_Distribution_Class::K_distri(double *p_sigma,double me_distri)       
{
	distri_k = 0.0;
	for (int i = 0; i < distri_n; i++)
	{
		distri_sigma[i] = *(p_sigma + i);
		distri_k = distri_sigma[i] * sqrt(2.0*distri_enery[i] * 1.6E-19 / me_distri)*distri_v_distributionfunction[i] * distri_enery_delta;
	}
	return distri_k;
}
