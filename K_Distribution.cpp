#include "K_Distribution.h"
#include  <fstream>
#include  <iostream>

/*------------------------------------------
  K_=sqrt(2*1.6E-19/Me)*[sigma*sqrt(enery)*f(enery)*delta_enery] 0_+00
  f(enery)=2.0/sqrt(Pi)*(Te^-1.5)*sqrt(energy)*exp(-energy/Te)  Max
-------------------------------------------*/
using namespace std;
K_Distribution_Class::K_Distribution_Class(double enery)
{
	distri_enery_max = enery;
	distri_enery_min = 0.0;
	distri_n = 4000;
	distri_enery_delta = (distri_enery_max - distri_enery_min) / distri_n;
	for (int i = 0; i <distri_n ; i++)
	{
		distri_enery[i] = i*distri_enery_delta;
		distri_sigma[i] = 0.0;
		distri_eedf[i] = 0.0;
	}
}

K_Distribution_Class::~K_Distribution_Class()
{
	cout << "bye distribution_function"<<endl;
}

void K_Distribution_Class::Maxwell_distri(double dis_Te)
{
	distri_Te = dis_Te;
	for (int i = 0; i < distri_n; i++)
	{
		distri_eedf[i] = 2.0 / sqrt(3.1415926)*pow(distri_Te, -1.5)*sqrt(distri_enery[i])*exp(-distri_enery[i] / distri_Te);
	}
}

void K_Distribution_Class::Druyvesteyn_distri(double dis_Te)
{
	distri_C1 = 0.56515196759131;
	distri_C2 = 0.24315995724738;
	distri_Te = dis_Te;
	for (int i = 0; i < distri_n; i++)
	{
		distri_eedf[i] = distri_C1*pow(distri_Te, -1.5)*sqrt(distri_enery[i])*exp(-distri_C2 *distri_enery[i]*distri_enery[i]/ (distri_Te*distri_Te));
	}
}

void K_Distribution_Class::DistributMc_distri(double *f_eedf)
{
	for (int i = 0; i < distri_n; i++)
	{
		distri_eedf[i] = *(f_eedf + i);
	}
}

double K_Distribution_Class::K_distri(double *p_sigma,double m_distri)                 //µç×ÓEEDF
{
	//double Me = 9.1E-31;
	distri_K = 0.0;
	for (int i = 0; i < distri_n; i++)
	{
		distri_sigma[i] = *(p_sigma + i);
		distri_K = distri_sigma[i] * sqrt(2.0*distri_enery[i] * 1.6E-19 / m_distri)*distri_eedf[i] * distri_enery_delta;
	}
	return distri_K;
}
