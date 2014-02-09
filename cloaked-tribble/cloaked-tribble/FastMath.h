#ifndef _FASTMATH_H_
#define _FASTMATH_H_

namespace FastMath
{
	float sqrt(float x)
	{
		if(x==0)
			return 0;
		float n=x;
		float m=x/2;
		for(int i=0;i<10;i++){
			m=((n/m)+m)/2;
		}
		return m;
	}
	float log(x)
	{
		if(x==0)
			return 0;

		return 0.0;
	}

};

#endif